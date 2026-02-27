/**
 * TMR4 Generated Driver File
 *
 * @file tmr4.c
 * 
 * @ingroup  tmr4
 * 
 * @brief This file contains the API implementation for the TMR4 module.
 *
 * @version Driver Version 2.0.0
 *
 * @version Package Version 2.0.0
 */
/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <xc.h>
#include "../tmr4.h"

static void (*TMR4_PeriodMatchCallback)(void);
static void TMR4_DefaultPeriodMatchCallback(void);

/**
  Section: TMR4 APIs
*/

void TMR4_Initialize(void)
{
    // Set TMR4 to the options selected in the User Interface
    PR4 = 0xDF;            // Period 0.01; Frequency 22321.428571428572Hz; Count 223
    TMR4 = 0x0;
    TMR4_PeriodMatchCallback = TMR4_DefaultPeriodMatchCallback;
    
    PIR5bits.TMR4IF = 0;   
    PIE5bits.TMR4IE = 1;
    T4CON = (2 << _T4CON_T4CKPS_POSN)   // T4CKPS 1:16
        | (0 << _T4CON_TMR4ON_POSN)   // TMR4ON off
        | (6 << _T4CON_T4OUTPS_POSN);  // T4OUTPS 1:7
}

void TMR4_Deinitialize(void)
{
    T4CONbits.TMR4ON = 0;
    PIR5bits.TMR4IF = 0;	   
    PIE5bits.TMR4IE = 0;
    T4CON = 0x0;
    PR4 = 0xFF;
    TMR4 =0x0;
}

void TMR4_Start(void)
{   
    T4CONbits.TMR4ON = 1;
}

void TMR4_Stop(void)
{   
    T4CONbits.TMR4ON = 0;
}

uint8_t TMR4_CounterGet(void)
{
    return TMR4;
}

void TMR4_CounterSet(uint8_t counterValue)
{  
    TMR4 = counterValue;
}

void TMR4_PeriodSet(uint8_t periodCount)
{
    PR4 = periodCount;
}

uint8_t TMR4_PeriodGet(void)
{
    return PR4;
}

uint8_t TMR4_MaxCountGet(void)
{
    return TMR4_MAX_COUNT;
}

void TMR4_TMRInterruptEnable(void)
{
    PIE5bits.TMR4IE = true;
}

void TMR4_TMRInterruptDisable(void)
{
    PIE5bits.TMR4IE = false;
}

void TMR4_ISR(void)
{
    // The ticker is set to 1 -> The callback function gets called every time this ISR executes.
    if(NULL != TMR4_PeriodMatchCallback)
    {
        TMR4_PeriodMatchCallback();
    }
    PIR5bits.TMR4IF = 0;
}

void TMR4_PeriodMatchCallbackRegister(void (* CallbackHandler)(void))
{
   TMR4_PeriodMatchCallback = CallbackHandler;
}

static void TMR4_DefaultPeriodMatchCallback(void)
{
    // Default callback function
}

