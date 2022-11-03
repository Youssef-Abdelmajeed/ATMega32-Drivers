/**
 * @file TIMERS_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  TIMERS Interface file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TIMERS_INT_H_
#define TIMERS_INT_H_

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "TIMERS_config.h"
#include "TIMERS_REG.h"
/**
 * @brief init TIMER0 Config 
 * 
 */
void TIMER0_Init(void) ;

/**
 * @brief set TIMER0 to Compare match mode and set the ISR callback 
 * 
 * @param ISR Callback function 
 */
void TIMER0_SetCompareMatchISR(void(*ISR)(void)) ;  

/**
 * @brief set TIMER0 to overflow mode and set the ISR callback 
 * 
 * @param ISR Callback function 
 */
void TIMER0_SetOverflowISR(void(*ISR)(void)) ;  


#endif /* TIMERS_INT_H_ */