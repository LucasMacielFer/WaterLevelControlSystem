/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define S0_TRIS                 TRISAbits.TRISA0
#define S0_LAT                  LATAbits.LATA0
#define S0_PORT                 PORTAbits.RA0
#define S0_WPU                  WPUAbits.
#define S0_OD                   ODCONAbits.
#define S0_ANS                  ANSELAbits.ANSA0
#define S0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define S0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define S0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define S0_GetValue()           PORTAbits.RA0
#define S0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define S0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define S0_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S0_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S0_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S0_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define S0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 aliases
#define S1_TRIS                 TRISAbits.TRISA1
#define S1_LAT                  LATAbits.LATA1
#define S1_PORT                 PORTAbits.RA1
#define S1_WPU                  WPUAbits.
#define S1_OD                   ODCONAbits.
#define S1_ANS                  ANSELAbits.ANSA1
#define S1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define S1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define S1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define S1_GetValue()           PORTAbits.RA1
#define S1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define S1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define S1_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S1_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S1_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S1_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define S1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 aliases
#define S2_TRIS                 TRISAbits.TRISA2
#define S2_LAT                  LATAbits.LATA2
#define S2_PORT                 PORTAbits.RA2
#define S2_WPU                  WPUAbits.
#define S2_OD                   ODCONAbits.
#define S2_ANS                  ANSELAbits.ANSA2
#define S2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define S2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define S2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define S2_GetValue()           PORTAbits.RA2
#define S2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define S2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define S2_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S2_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S2_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S2_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define S2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 aliases
#define S3_TRIS                 TRISAbits.TRISA3
#define S3_LAT                  LATAbits.LATA3
#define S3_PORT                 PORTAbits.RA3
#define S3_WPU                  WPUAbits.
#define S3_OD                   ODCONAbits.
#define S3_ANS                  ANSELAbits.ANSA3
#define S3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define S3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define S3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define S3_GetValue()           PORTAbits.RA3
#define S3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define S3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define S3_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S3_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S3_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S3_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define S3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RA4 aliases
#define S4_TRIS                 TRISAbits.TRISA4
#define S4_LAT                  LATAbits.LATA4
#define S4_PORT                 PORTAbits.RA4
#define S4_WPU                  WPUAbits.
#define S4_OD                   ODCONAbits.
#define S4_ANS                  ANSELAbits.
#define S4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define S4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define S4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define S4_GetValue()           PORTAbits.RA4
#define S4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define S4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define S4_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S4_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S4_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S4_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S4_SetAnalogMode()      do { ANSELAbits. = 1; } while(0)
#define S4_SetDigitalMode()     do { ANSELAbits. = 0; } while(0)

// get/set RA5 aliases
#define S5_TRIS                 TRISAbits.TRISA5
#define S5_LAT                  LATAbits.LATA5
#define S5_PORT                 PORTAbits.RA5
#define S5_WPU                  WPUAbits.
#define S5_OD                   ODCONAbits.
#define S5_ANS                  ANSELAbits.ANSA5
#define S5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define S5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define S5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define S5_GetValue()           PORTAbits.RA5
#define S5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define S5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define S5_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S5_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S5_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S5_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define S5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RA6 aliases
#define S6_TRIS                 TRISAbits.TRISA6
#define S6_LAT                  LATAbits.LATA6
#define S6_PORT                 PORTAbits.RA6
#define S6_WPU                  WPUAbits.
#define S6_OD                   ODCONAbits.
#define S6_ANS                  ANSELAbits.
#define S6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define S6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define S6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define S6_GetValue()           PORTAbits.RA6
#define S6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define S6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define S6_SetPullup()          do { WPUAbits. = 1; } while(0)
#define S6_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define S6_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define S6_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define S6_SetAnalogMode()      do { ANSELAbits. = 1; } while(0)
#define S6_SetDigitalMode()     do { ANSELAbits. = 0; } while(0)

// get/set RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.
#define IO_RB0_ANS                  ANSELBbits.ANSB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RC0 aliases
#define S7_TRIS                 TRISCbits.TRISC0
#define S7_LAT                  LATCbits.LATC0
#define S7_PORT                 PORTCbits.RC0
#define S7_WPU                  WPUCbits.
#define S7_OD                   ODCONCbits.
#define S7_ANS                  ANSELCbits.
#define S7_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define S7_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define S7_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define S7_GetValue()           PORTCbits.RC0
#define S7_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define S7_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define S7_SetPullup()          do { WPUCbits. = 1; } while(0)
#define S7_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define S7_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define S7_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define S7_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define S7_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC1 aliases
#define S8_TRIS                 TRISCbits.TRISC1
#define S8_LAT                  LATCbits.LATC1
#define S8_PORT                 PORTCbits.RC1
#define S8_WPU                  WPUCbits.
#define S8_OD                   ODCONCbits.
#define S8_ANS                  ANSELCbits.
#define S8_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define S8_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define S8_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define S8_GetValue()           PORTCbits.RC1
#define S8_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define S8_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define S8_SetPullup()          do { WPUCbits. = 1; } while(0)
#define S8_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define S8_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define S8_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define S8_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define S8_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.
#define IO_RC2_OD                   ODCONCbits.
#define IO_RC2_ANS                  ANSELCbits.ANSC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 aliases
#define IO_RC3_TRIS                 TRISCbits.TRISC3
#define IO_RC3_LAT                  LATCbits.LATC3
#define IO_RC3_PORT                 PORTCbits.RC3
#define IO_RC3_WPU                  WPUCbits.
#define IO_RC3_OD                   ODCONCbits.
#define IO_RC3_ANS                  ANSELCbits.ANSC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC3_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC3_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC3_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.
#define IO_RC4_OD                   ODCONCbits.
#define IO_RC4_ANS                  ANSELCbits.ANSC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.
#define IO_RC5_OD                   ODCONCbits.
#define IO_RC5_ANS                  ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.
#define IO_RC6_OD                   ODCONCbits.
#define IO_RC6_ANS                  ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 aliases
#define IO_RC7_TRIS                 TRISCbits.TRISC7
#define IO_RC7_LAT                  LATCbits.LATC7
#define IO_RC7_PORT                 PORTCbits.RC7
#define IO_RC7_WPU                  WPUCbits.
#define IO_RC7_OD                   ODCONCbits.
#define IO_RC7_ANS                  ANSELCbits.ANSC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC7_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC7_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC7_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_WPU                  WPUDbits.
#define IO_RD0_OD                   ODCONDbits.
#define IO_RD0_ANS                  ANSELDbits.ANSD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()          do { WPUDbits. = 1; } while(0)
#define IO_RD0_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define IO_RD0_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define IO_RD0_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_WPU                  WPUDbits.
#define IO_RD1_OD                   ODCONDbits.
#define IO_RD1_ANS                  ANSELDbits.ANSD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()          do { WPUDbits. = 1; } while(0)
#define IO_RD1_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define IO_RD1_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define IO_RD1_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set RD2 aliases
#define LED_OFF_TRIS                 TRISDbits.TRISD2
#define LED_OFF_LAT                  LATDbits.LATD2
#define LED_OFF_PORT                 PORTDbits.RD2
#define LED_OFF_WPU                  WPUDbits.
#define LED_OFF_OD                   ODCONDbits.
#define LED_OFF_ANS                  ANSELDbits.ANSD2
#define LED_OFF_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LED_OFF_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LED_OFF_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LED_OFF_GetValue()           PORTDbits.RD2
#define LED_OFF_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LED_OFF_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LED_OFF_SetPullup()          do { WPUDbits. = 1; } while(0)
#define LED_OFF_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define LED_OFF_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define LED_OFF_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define LED_OFF_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define LED_OFF_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set RD3 aliases
#define LED_ON_TRIS                 TRISDbits.TRISD3
#define LED_ON_LAT                  LATDbits.LATD3
#define LED_ON_PORT                 PORTDbits.RD3
#define LED_ON_WPU                  WPUDbits.
#define LED_ON_OD                   ODCONDbits.
#define LED_ON_ANS                  ANSELDbits.ANSD3
#define LED_ON_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LED_ON_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LED_ON_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LED_ON_GetValue()           PORTDbits.RD3
#define LED_ON_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LED_ON_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LED_ON_SetPullup()          do { WPUDbits. = 1; } while(0)
#define LED_ON_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define LED_ON_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define LED_ON_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define LED_ON_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define LED_ON_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set RD4 aliases
#define LED_PUMP_TRIS                 TRISDbits.TRISD4
#define LED_PUMP_LAT                  LATDbits.LATD4
#define LED_PUMP_PORT                 PORTDbits.RD4
#define LED_PUMP_WPU                  WPUDbits.
#define LED_PUMP_OD                   ODCONDbits.
#define LED_PUMP_ANS                  ANSELDbits.ANSD4
#define LED_PUMP_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LED_PUMP_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LED_PUMP_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LED_PUMP_GetValue()           PORTDbits.RD4
#define LED_PUMP_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LED_PUMP_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define LED_PUMP_SetPullup()          do { WPUDbits. = 1; } while(0)
#define LED_PUMP_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define LED_PUMP_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define LED_PUMP_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define LED_PUMP_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define LED_PUMP_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set RD5 aliases
#define PUMP_TRIS                 TRISDbits.TRISD5
#define PUMP_LAT                  LATDbits.LATD5
#define PUMP_PORT                 PORTDbits.RD5
#define PUMP_WPU                  WPUDbits.
#define PUMP_OD                   ODCONDbits.
#define PUMP_ANS                  ANSELDbits.ANSD5
#define PUMP_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define PUMP_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define PUMP_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define PUMP_GetValue()           PORTDbits.RD5
#define PUMP_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define PUMP_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define PUMP_SetPullup()          do { WPUDbits. = 1; } while(0)
#define PUMP_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define PUMP_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define PUMP_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define PUMP_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define PUMP_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set RD6 aliases
#define S9_TRIS                 TRISDbits.TRISD6
#define S9_LAT                  LATDbits.LATD6
#define S9_PORT                 PORTDbits.RD6
#define S9_WPU                  WPUDbits.
#define S9_OD                   ODCONDbits.
#define S9_ANS                  ANSELDbits.ANSD6
#define S9_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define S9_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define S9_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define S9_GetValue()           PORTDbits.RD6
#define S9_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define S9_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define S9_SetPullup()          do { WPUDbits. = 1; } while(0)
#define S9_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define S9_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define S9_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define S9_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define S9_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.
#define IO_RD7_OD                   ODCONDbits.
#define IO_RD7_ANS                  ANSELDbits.ANSD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits. = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set RE0 aliases
#define DC_TRIS                 TRISEbits.TRISE0
#define DC_LAT                  LATEbits.LATE0
#define DC_PORT                 PORTEbits.RE0
#define DC_WPU                  WPUEbits.
#define DC_OD                   ODCONEbits.
#define DC_ANS                  ANSELEbits.ANSE0
#define DC_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define DC_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define DC_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define DC_GetValue()           PORTEbits.RE0
#define DC_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define DC_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define DC_SetPullup()          do { WPUEbits. = 1; } while(0)
#define DC_ResetPullup()        do { WPUEbits. = 0; } while(0)
#define DC_SetPushPull()        do { ODCONEbits. = 0; } while(0)
#define DC_SetOpenDrain()       do { ODCONEbits. = 1; } while(0)
#define DC_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define DC_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set RE1 aliases
#define CS_TRIS                 TRISEbits.TRISE1
#define CS_LAT                  LATEbits.LATE1
#define CS_PORT                 PORTEbits.RE1
#define CS_WPU                  WPUEbits.
#define CS_OD                   ODCONEbits.
#define CS_ANS                  ANSELEbits.ANSE1
#define CS_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define CS_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define CS_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define CS_GetValue()           PORTEbits.RE1
#define CS_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define CS_SetPullup()          do { WPUEbits. = 1; } while(0)
#define CS_ResetPullup()        do { WPUEbits. = 0; } while(0)
#define CS_SetPushPull()        do { ODCONEbits. = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONEbits. = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/