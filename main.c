/*
 * MINIPROJ: 3 - Sistema de controlo do nivel de agua
 * TURMA: PLN
 * GRUPO: 3
 * 
 * NOME: Lucas Maciel Ferreira
 * NUMERO: 2025224967
 *
 */

#include "mcc_generated_files/system/system.h"
#include "lib_ili9341.h"
#include "lib_24lc256.h"
#include "tft_images.h"

volatile adc_result_t pot_value = 0;
volatile unsigned char perform_control = 0;
volatile unsigned char conversion_done = 0;
volatile unsigned char EEPROM_write_flag = 0;

volatile unsigned char control_on;
volatile unsigned char pump_on;
volatile unsigned char system_status_changed;

// Int 0: Botao de emergencia
void int0_interrupt(void)
{
    control_on = 0;
    pump_on = 0;
    PUMP_SetLow();
    LED_PUMP_SetLow();
    perform_control = 0;
    system_status_changed = 1;
}

// Timer 0: Temporizacao do piscar do LED
void tmr0_interrupt(void)
{
    LED_ON_Toggle();
}

// Timer 1: Temporizacao da malha de controlo
void tmr1_interrupt(void)
{
    perform_control = 1;
}

// Timer 4: Temporizacao da escrita na EEPROM
void tmr4_interrupt(void)
{
    TMR4_Stop();
    TMR4_CounterSet(0);
    EEPROM_write_flag = 1;
}

// ADC
void adc_interrupt(void)
{
    pot_value = ADC_GetConversionResult();
    conversion_done = 1;
}

int main(void)
{
    SYSTEM_Initialize();
    
    unsigned int ref_level = 0;
    unsigned int water_level;
    int delta_level;
    unsigned char control_mode; // 0 - pot, 1 - serial
    unsigned char ref_level_temp;
    char ticksUntilMeasurement = 0;
    
    int last_water_level = 0;
    int last_ref_level = 0;
    int n_logs;
    int reading_on_addr;
    int log_count;
    uint8_t log_level, log_ref;
    
    unsigned char rx_data, char_accepted, write_mode;
    unsigned char char_count, menu_selection, select_on_menu;

    char on_txt[3] = "ON";
    char off_txt[4] = "OFF";
    char serial_interface_txt[17] = "Interface serial";
    char potentiometer_txt[14] = "Potenciometro";
    char adjust_buffer[4];
    
    // Flags (estados) de escrita na EEPROM
    unsigned char EEPROM_write_log = 0;
    unsigned char EEPROM_write_lvl = 0;
    unsigned char EEPROM_write_addr_h = 0;
    unsigned char EEPROM_write_addr = 0;
    
    uint16_t last_addr;
    uint8_t last_addr_h, last_addr_l;
    uint8_t addr_h_prev;
    
    // Inicializacao do Display TFT
    char tft_string[50] = "";
    uint16_t *ptr_lucas = &foto_lucas_80x80[0];
    uint16_t *ptr_logo = &logo_ipl_80x25[0];
    
    // Desativacao da bomba, do buzzer e do timer de escrita na EEPROM
    TMR2_Stop();
    TMR4_Stop();
    pump_on = 0;
    PUMP_SetLow();
    LED_PUMP_SetLow();
    
    // Flags de inicializacao
    system_status_changed = 1;
    control_mode = 0;
    control_on = 1;
    
    SPI1_Open(HOST_CONFIG);
    lcd_init();
    
    // Tela de "boot" TFT
    lcd_draw_image(0, 159, 80, 80, ptr_lucas);
    lcd_draw_image(119, 30, 80, 25, ptr_logo);
    lcd_draw_string(82, 220, "ENGENHARIA ELETROTECNICA", LIME, BLACK);
    snprintf(tft_string, sizeof(tft_string), "MICROPROCESSADORES");
    lcd_draw_string(85, 190, tft_string, YELLOW, BLACK);
    snprintf(tft_string, sizeof(tft_string), "2025 / 26");
    lcd_draw_string(125, 165, tft_string, ILI9341_CYAN, BLACK);
    snprintf(tft_string, sizeof(tft_string), "PROPOSTA 3");
    lcd_draw_string(110, 140, tft_string, WHITE, BLACK);
    snprintf(tft_string, sizeof(tft_string), "SISTEMA DE CONTROLO DO NIVEL");
    lcd_draw_string(30, 120, tft_string, WHITE, BLACK);
    snprintf(tft_string, sizeof(tft_string), "DE AGUA");
    lcd_draw_string(120, 100, tft_string, WHITE, BLACK);
    snprintf(tft_string, sizeof(tft_string), "Autor: Lucas Ferreira");
    lcd_draw_string(80, 80, tft_string, LIME, BLACK);
    
    // Configuracao do display TFT para a operacao
    lcd_fill(0);
    snprintf(tft_string, sizeof(tft_string), "SISTEMA DE CONTROLO DO NIVEL");
    lcd_draw_string(30, 220, tft_string, WHITE, BLACK);
    snprintf(tft_string, sizeof(tft_string), "DE AGUA");
    lcd_draw_string(120, 200, tft_string, WHITE, BLACK);
    snprintf(tft_string, sizeof(tft_string), "Nivel de referencia: ");
    lcd_draw_string(10, 120, tft_string, ILI9341_CYAN, BLACK);
    snprintf(tft_string, sizeof(tft_string), "Nivel atual: ");
    lcd_draw_string(10, 100, tft_string, ILI9341_CYAN, BLACK);
    
    //Estado inicial do terminal serie
    EUSART1_Write(12);   // Clear
    printf("\r\n----| Sistema de controlo de nivel da agua |----");
    printf("\r\n------------| Selecione uma opcao |------------");
    printf("\r\n 1 - Controlo da bomba de agua");
    printf("\r\n 2 - Modo de controlo");
    printf("\r\n 3 - Verificar nivel da agua");
    printf("\r\n 4 - Verificar nivel de referencia configurado");
    printf("\r\n 5 - Verificar historico do sistema");
    
    TMR0_OverflowCallbackRegister(tmr0_interrupt);
    TMR1_OverflowCallbackRegister(tmr1_interrupt);
    TMR4_PeriodMatchCallbackRegister(tmr4_interrupt);
    INT0_SetInterruptHandler(int0_interrupt);
    ADC_SetInterruptHandler(adc_interrupt);
    
    INTERRUPT_GlobalInterruptHighEnable(); 
    INTERRUPT_GlobalInterruptLowEnable(); 
    
    // Coloquei depois de ativar as interrupcoes porque o I2C eh interrupt-driven
    // Recuperando o endereco do ultimo log
    last_addr_h = EEPROM_ReadByte(0);
    last_addr_l = EEPROM_ReadByte(1);
    
    addr_h_prev = last_addr_h;
    last_addr = ((unsigned int)last_addr_h << 8) | last_addr_l;
    if(last_addr >= 31999) last_addr = 1;
    
    while(1)
    {
        // Leitura do potenciometro
        if(conversion_done)
        {
            ref_level = (int) ((pot_value/1023.0)*100);            
            conversion_done = 0;
        }
        
        // Terminal Serie
        if(EUSART1_IsRxReady())
        {
            rx_data = EUSART1_Read();
            EUSART1_Write(rx_data);
            if((rx_data >= '0' && rx_data <= '9') || rx_data == 13)
            {
                char_accepted = 1;
                menu_selection = rx_data;
            }
            else
            {
                char_accepted = 0;
                menu_selection = '0';
            }
            
            if(write_mode == 1)
                menu_selection = 1;
            else if(write_mode == 2)
                menu_selection = 2;
            
            // O utilizador esta no menu 1 - Esperamos que desligue a bomba ou volte ao main menu
            if(select_on_menu == '1') 
            {
                 switch(rx_data)
                 {
                     case '1':
                        pump_on = 0;
                        PUMP_SetLow();
                        LED_PUMP_SetLow();
                        control_on = 0;
                        system_status_changed = 1;
                        menu_selection = '1';
                        break;
                     case '0':
                         menu_selection = '0';
                         break;
                     default:
                         menu_selection = '1';
                         break;
                 }
                 select_on_menu = 0;
            }
            
            // O utilizador esta no menu 2 - Esperamos que ligue/configure o sistema
            else if(select_on_menu == '2') 
            {
                switch(rx_data)
                {
                     case '1':
                        control_on = 1;
                        control_mode = 1;
                        system_status_changed = 1;
                        menu_selection = '2';
                        break;
                     case '2':
                        control_mode = 0;
                        control_on = 1;
                        system_status_changed = 1;
                        menu_selection = '2';
                        break;
                     case '0':
                         menu_selection = '0';
                         break;
                     default:
                         menu_selection = '2';
                         break;
                 }
                select_on_menu = 0;
            }
            
            switch(menu_selection)
            {
                // Main menu
                case '0':
                    EUSART1_Write(12);   // Clear
                    printf("\r\n----| Sistema de controlo de nivel da agua |----");
                    printf("\r\n------------| Selecione uma opcao |------------");
                    printf("\r\n 1 - Controlo da bomba de agua");
                    printf("\r\n 2 - Modo de controlo");
                    printf("\r\n 3 - Verificar nivel da agua");
                    printf("\r\n 4 - Verificar nivel de referencia configurado");
                    printf("\r\n 5 - Verificar historico do sistema");
                    if(control_mode)
                        printf("\r\n 6 - Ajustar nivel de referencia");
                    break;
                    
                // Opcao 1 - Parar a bomba
                case '1':
                    EUSART1_Write(12);   // Clear
                    printf("\r\n---------| Controlo da bomba de agua |---------");
                    printf("\r\n A bomba de agua esta: ");
                    printf(pump_on? on_txt : off_txt);
                    printf("\r\n\r\n 1 - Desligar a bomba de agua");
                    printf("\r\n\r\n 0 - Menu principal");
                    select_on_menu = '1';
                    break;
                    
                // Opcao 2 - Ligar/configurar o sistema
                case '2':
                    EUSART1_Write(12);   // Clear
                    printf("\r\n-------------| Modo de controlo |-------------");
                    printf("\r\n\r\n O sistema de controlo esta: ");
                    printf(control_on? on_txt : off_txt);
                    printf("\r\n Modo de controlo atual: ");
                    printf(control_mode? serial_interface_txt : potentiometer_txt);
                    printf("\r\n\r\n Definir modo de controlo para:");
                    printf("\r\n 1 - Interface serial");
                    printf("\r\n 2 - Potenciometro");
                    printf("\r\n\r\n 0 - Menu principal");
                    select_on_menu = '2';
                    break;
                    
                // Opcao 3 - "Peek" no nivel
                case '3':
                    EUSART1_Write(12);   // Clear
                    printf("\r\n----------| Verificar nivel da agua |----------");
                    printf("\r\n\r\n Nivel atual: %d %%", water_level);
                    printf("\r\n\r\n 0 - Menu principal");
                    break;
                    
                // Opcao 4 - "Peek" no nivel de referência
                case '4':
                    EUSART1_Write(12);   // Clear
                    printf("\r\n-| Verificar nivel de referencia configurado |-");
                    printf("\r\n\r\n Nivel de referencia atual: %d %%", ref_level);
                    printf("\r\n\r\n 0 - Menu principal");
                    break;
                
                // Opcao 5 - Checar o historico
                case '5':
                    EUSART1_Write(12);   // Clear
                    printf("\r\n-------| Verificar historico do sistema |-------");
                    printf("\r\n\r\n 0 - Menu principal");
                    printf("\r\n\r\n Registos a verificar: ");
                    write_mode = 2;
                    char_count = 0;
                    break;
                    
                // Opcao 6 - Inserir novo nivel ref
                case '6':
                    if(control_mode)
                    {
                        EUSART1_Write(12);   // Clear
                        printf("\r\n--------| Ajustar nivel de referencia |--------");
                        printf("\r\n\r\n 0 - Menu principal");
                        printf("\r\n\r\n Insira um novo valor de referencia: ");
                        write_mode = 1;
                        char_count = 0;
                    }
                    break;
                    
                // Insercao novo nivel ref
                case 1:
                    adjust_buffer[char_count] = rx_data;
                    
                    if (char_count == 2 || rx_data == 13)
                    {
                        if (char_count == 2) 
                            char_count++;
                        adjust_buffer[char_count]='\0';
                        ref_level_temp = atoi(adjust_buffer);
                        
                        if(ref_level_temp >= 0 && ref_level_temp <= 100)
                        {
                            printf("\r\n\r\n Valor de referencia redefinido com sucesso para %d", ref_level_temp);
                            printf("\r\n prima 0 para voltar ao menu principal.");
                            ref_level = ref_level_temp;
                            write_mode = 0;
                        }
                        else
                        {
                            printf("\r\n\r\n Valor invalido! O nivel de referencia deve estar entre 0 e 100...");
                            printf("\r\n Insira um novo valor de referencia: ");
                            char_count = 0;
                        }
                    }
                    else 
                    {
                        char_count++;
                    }
                    break;
                    
                // Insercao da quantidade de registos a ser mostrada
                case 2:
                    adjust_buffer[char_count] = rx_data;
                    
                    if (char_count == 2 || rx_data == 13)
                    {
                        if (char_count == 2) 
                            char_count++;
                        adjust_buffer[char_count]='\0';
                        n_logs = atoi(adjust_buffer);
                        
                        if(n_logs >= 0)
                        {
                            // Para ler do mais antigo ao mais recente
                            reading_on_addr = (int)last_addr - (n_logs*2);
                            log_count = 0;
                            
                            if(reading_on_addr < 2) 
                                reading_on_addr = 31999 + (reading_on_addr - 2);
                            
                            while(log_count < n_logs)
                            {
                                if (reading_on_addr >= 31999) 
                                    reading_on_addr = 1;
                                
                                log_ref = EEPROM_ReadByte(++reading_on_addr);
                                log_level = EEPROM_ReadByte(++reading_on_addr);
                                
                                if(log_level == 0xFF || log_ref == 0xFF)
                                {
                                    printf("\r\n\r\n Registos esgotados.");
                                    break;
                                }
                                
                                printf("\r\n Nivel da agua: %d \t Nivel de referencia: %d.", log_level, log_ref);
                                log_count++;
                            }
                            
                            printf("\r\n\r\n prima 0 para voltar ao menu principal.");
                            ref_level = ref_level_temp;
                            write_mode = 0;
                        }
                        else
                        {
                            printf("\r\n\r\n Valor invalido!");
                            printf("\r\n Insira o numero de registos: ");
                            char_count = 0;
                        }
                    }
                    else 
                    {
                        char_count++;
                    }
                    break;
            }
        }
        
        // Malha de controlo
        if(perform_control)
        {
            //Leitura do ADC antes, para usarmos um valor novo
            if(control_mode == 0 && ticksUntilMeasurement == 1)
                ADC_StartConversion();
            
            // Verifica o nível da agua a cada 1s ou se a bomba estiver ligada
            if(ticksUntilMeasurement <= 0 || pump_on)
            {
                if(!S9_GetValue())
                    water_level = 100;
                else if(!S8_GetValue())
                    water_level = 90;
                else if(!S7_GetValue())
                    water_level = 80;
                else if(!S6_GetValue())
                    water_level = 70;
                else if(!S5_GetValue())
                    water_level = 60;
                else if(!S4_GetValue())
                    water_level = 50;
                else if(!S3_GetValue())
                    water_level = 40;
                else if(!S2_GetValue())
                    water_level = 30;
                else if(!S1_GetValue())
                    water_level = 20;
                else if(!S0_GetValue())
                    water_level = 10;
                else
                    water_level = 0;

                // Buzzer
                if(water_level == 100)
                    TMR2_Start();
                else
                    TMR2_Stop();
                
                delta_level = ref_level - water_level;
            }
                
            // 1 segundo se passou -> Vamos operar a bomba (se necessario))
            if(ticksUntilMeasurement <= 0 )
            {
                if(delta_level > 0 && !pump_on)
                {
                    pump_on = 1;
                    PUMP_SetHigh();
                    LED_PUMP_SetHigh();
                }
                
                if(water_level != last_water_level)
                {
                    snprintf(tft_string, sizeof(tft_string), "%d   ", water_level);
                    lcd_draw_string(100, 100, tft_string, ILI9341_CYAN, BLACK);
                    last_water_level = water_level;
                }
                if(ref_level != last_ref_level)
                {
                    snprintf(tft_string, sizeof(tft_string), "%d   ", ref_level);
                    lcd_draw_string(165, 120, tft_string, ILI9341_CYAN, BLACK);
                    last_ref_level = ref_level;
                }
                
                // Log na EEPROM
                EEPROM_write_log = 1;
                TMR4_Start();
                
                ticksUntilMeasurement = 10;
            }
            else
                ticksUntilMeasurement -= 1;
            
            // Encheu de mais -> Vamos desligar a bomba (nao espera 1 segundo))
            if(delta_level <= 0 && pump_on)
            {
                pump_on = 0;
                PUMP_SetLow();
                LED_PUMP_SetLow();
            }

            perform_control = 0;
        }
        
        // Ataliza a interface com base nas mudancas do sistema (ON/OFF))
        if(system_status_changed)
        {
            if(control_on)
            {
                // LEDs indicativos:
                TMR0_Start();
                LED_OFF_SetLow();
                
                // Ativar temporizacao da malha de controlo
                TMR1_Start();
                
                // Display TFT
                snprintf(tft_string, sizeof(tft_string), "      CONTROLO ATIVADO    ");
                lcd_draw_string(50, 50, tft_string, LIME, BLACK);
            }
            else
            {
                // LEDs indicativos:
                TMR0_Stop();
                LED_ON_SetLow();
                LED_OFF_SetHigh();
                
                // Desativar temporizacao da malha de controlo
                TMR1_Stop();
                perform_control = 0;
                
                // Buzzer, caso esteja ligado
                TMR2_Stop();
                
                // Display TFT
                snprintf(tft_string, sizeof(tft_string), "CONTROLO DESATIVADO");
                lcd_draw_string(50, 50, tft_string, RED, BLACK);
            }
            
            system_status_changed = 0;
        }
        
        // Mini state machine para escrever na EEPROM com cooldown de 10 ms
        if(EEPROM_write_flag)
        {
            // Primeiro escreve o nivel de referencia
            if(EEPROM_write_log)
            {
                last_addr++;
                if(last_addr >= 31999) last_addr = 2;
                
                EEPROM_WriteByte(last_addr, (uint8_t)ref_level);
                EEPROM_write_log = 0;
                EEPROM_write_lvl = 1;
                
                TMR4_Start();
            }
            // Depois escreve o nivel lido
            else if(EEPROM_write_lvl)
            {           
                last_addr++;
                
                EEPROM_WriteByte(last_addr, (uint8_t)water_level);
                EEPROM_write_addr = 1;
                EEPROM_write_lvl = 0;
                
                TMR4_Start();
            }
            // Depois escreve o low byte do endereco atual
            else if(EEPROM_write_addr)
            {
                last_addr_h = (uint8_t)(last_addr >> 8);
                last_addr_l = (uint8_t)(0x00FF & last_addr);
                
                EEPROM_WriteByte(1, last_addr_l);
                EEPROM_write_addr = 0;
                
                if(addr_h_prev != last_addr_h)
                {
                    EEPROM_write_addr_h = 1;
                }
                
                TMR4_Start();
                addr_h_prev = last_addr_h;
            }
            // Se precisar, escreve o high byte
            else if(EEPROM_write_addr_h)
            {
                EEPROM_WriteByte(0, last_addr_h);
                EEPROM_write_addr_h = 0;
                TMR4_Start();
            }
            
            EEPROM_write_flag = 0;
        }
    }
}