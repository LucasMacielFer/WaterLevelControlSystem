# WaterLevelControlSystem

Este repositório contém o firmware para o sistema de controlo de nível de água, uma solução de malha fechada desenvolvida
para a unidade curricular de Microprocessadores (2025/2026), da Licenciatura em Engenharia Electrotécnica e de Computadores
do Instituto Politécnico de Leiria. O projeto foi integralmente validado em ambiente de simulação 
(Proteus), não tendo sido realizada a sua implementação em hardware físico.

## 🛠️ Tecnologias e Periféricos (Ambiente Simulado)

- Microcontrolador: Operação com cristal externo de 10 MHz.

- Sensores de Nível: Simulação de 10 sensores digitais (S0 a S9) com resolução de 10%.

- Armazenamento: Memória EEPROM 24LC256 (I2C) para registo histórico circular, gerida por uma máquina de estados não bloqueante.

- Visualização: Interface gráfica em display TFT ILI9341 (240x320) e sinalização via LEDs e LCD alfanumérico 16x2.

- Comunicação: Interface EUSART (38400 bps) para terminal série, simulando monitorização e controlo remoto.


## ⚙️ Gestão de Firmware e Timers

- Timer 1 (Malha de Controlo): Base de tempo de 100 ms. Em atuação crítica (bomba ligada), a leitura é feita a cada ciclo; em monitorização, a amostragem é reduzida para 1 Hz.

- Timer 0: Controla a intermitência do LED de sistema ativo a 1 Hz.

- Timer 2 (ECCP1): Gera o sinal PWM de 4 kHz para o buzzer (tanque cheio).

- Timer 4: Gere o cooldown de 10 ms para a escrita estável na EEPROM simulada.


## ✨ Funcionalidades e Segurança

- Modos de Referência: Seleção entre Modo Analógico (via potenciómetro/ADC) ou Modo Digital (via terminal serial).

- Botão de Emergência: Implementado via interrupção externa (INT0), forçando a paragem imediata da bomba no Proteus.

- Lógica de Atuação: Acionamento da bomba hidráulica sempre que o nível medido é inferior à referência.

- Interface Assíncrona: Atualização do display TFT orientada a eventos, refrescando os dados apenas quando existem alterações efetivas.
