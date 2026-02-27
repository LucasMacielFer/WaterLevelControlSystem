/**
 * TMR4 Generated Driver API Header File
 *
 * @file tmr4.h
 *  
 * @defgroup tmr4 TMR4
 *
 * @brief This file contains the API prototypes and other data types for the Timer2 (TMR4) driver.
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

#ifndef TMR4_H
#define TMR4_H

#include <stdint.h>
#include <stdbool.h>
#include "tmr4_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tmr4
 * @brief Defines the maximum count value of the timer.
 */
#define TMR4_MAX_COUNT (255U)
/**
 * @ingroup tmr4
 * @brief Defines the timer prescaled clock frequency in hertz.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TMR4_CLOCK_FREQ (22321.428571428572UL)
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_MAX_COUNT.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TIMER4_MAX_COUNT TMR4_MAX_COUNT
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CLOCK_FREQ.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TIMER4_CLOCK_FREQ TMR4_CLOCK_FREQ
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Initialize API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Initialize TMR4_Initialize
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Deinitialize API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Deinitialize TMR4_Deinitialize
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Start API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Start TMR4_Start
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Stop API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Stop TMR4_Stop
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterGet API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_CounterGet TMR4_CounterGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterSet API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_CounterSet TMR4_CounterSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodSet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodSet TMR4_PeriodSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodGet API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodGet TMR4_PeriodGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_MaxCountGet API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_MaxCountGet TMR4_MaxCountGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_TMRInterruptEnable API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_TMRInterruptEnable TMR4_TMRInterruptEnable
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_TMRInterruptDisable API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_TMRInterruptDisable TMR4_TMRInterruptDisable
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_ISR API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_ISR TMR4_ISR
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodMatchCallbackRegister API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodMatchCallbackRegister TMR4_PeriodMatchCallbackRegister

/**
 * @ingroup tmr4
 * @brief Initializes the TMR4 module.
 *        This routine must be called before any other TMR4 routines.
 * @param None.
 * @return None.
 */
void TMR4_Initialize(void);

/**
 * @ingroup tmr4
 * @brief Deinitializes the TMR4 module.
 * @param None.
 * @return None.
 */
void TMR4_Deinitialize(void);

/**
 * @ingroup tmr4
 * @brief Starts the TMR4 timer.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR4_Start(void);

/**
 * @ingroup tmr4
 * @brief Stops the TMR4 timer.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR4_Stop(void);

/**
 * @ingroup tmr4
 * @brief Returns the current counter value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return Counter value from the TMR4 register
 */
uint8_t TMR4_CounterGet(void);

/**
 * @ingroup tmr4
 * @brief Sets the counter value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param counterValue - Counter value to be written to the TMR4 register
 * @return None.
 */
void TMR4_CounterSet(uint8_t counterValue);

/**
 * @ingroup tmr4
 * @brief Sets the period value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param periodCount - Period count value written to the PR4 register
 * @return None.
 */
void TMR4_PeriodSet(uint8_t periodCount);

/**
 * @ingroup tmr4
 * @brief Returns the current period value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return Period count value from the PR4 register
 */
uint8_t TMR4_PeriodGet(void);

/**
 * @ingroup tmr4
 * @brief Returns the maximum count value.
 * @param None.
 * @return Maximum count value
 */
uint8_t TMR4_MaxCountGet(void);

/**
 * @ingroup tmr4
 * @brief Enables the TMR4 interrupt.
 * @param None.
 * @return None.
 */
void TMR4_TMRInterruptEnable(void);

/**
 * @ingroup tmr4
 * @brief Disables the TMR4 interrupt.
 * @param None.
 * @return None.
 */
void TMR4_TMRInterruptDisable(void);

/**
 * @ingroup tmr4
 * @brief Interrupt Service Routine (ISR) for the TMR4 period match interrupt.
 * @param None.
 * @return None.
 */
void TMR4_ISR(void);

/**
 * @ingroup tmr4
 * @brief Setter function for the TMR4 period match callback.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR4_PeriodMatchCallbackRegister(void (* CallbackHandler)(void));


#endif // TMR4_H
/**
 End of File
*/
