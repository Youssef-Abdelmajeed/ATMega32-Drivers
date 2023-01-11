/**
 * @file TimeOne_private.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Timer one private file 
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TIMER_1_PRIVATE_H_  
#define TIMER_1_PRIVATE_H_  

/* Timer clock select */

#define Stoped                          0
#define NoPrescaler                     1    
#define Prescaler8                      2
#define Prescaler64                     3
#define Prescaler256                    4
#define Prescaler1024                   5
#define External_onRising               6 
#define External_onFalling              7

/* Timer Waveform Generation */ 

#define Normal_Mode                     0   
#define PWM_PhaseCorrect_8bit           1
#define PWM_PhaseCorrect_9bit           2
#define PWM_PhaseCorrect_10bit          3
#define CTC_OCR                         4                     
#define Fast_PWM_8bit                   5
#define Fast_PWM_9bit                   6
#define Fast_PWM_10bit                  7   
#define PWM_Phase_Freq_Correct_ICR      8
#define PWM_Phase_Freq_Correct_OCR      9
#define PWM_PhaseCorrect_ICR            10
#define PWM_PhaseCorrect_OCR            11
#define CTC_ICR                         12
#define Fast_PWM_ICR                    14
#define Fast_PWM_OCR                    15

/* Timer Errors */

#define TimerOK                          1
#define WrongSelection                   2
#define NULL_POINTER                     3

/* output compare modes */

#define disconnected                     0 

/* non-PWM */

#define Toggle_on_Compare                1
#define Clear_on_Compare                 2
#define Set_on_Compare                   3

/* fast/phase correct PWM */

#define Inverting                        3
#define NonInverting                     2

/* output compare OC1A */
#define ChannelA                         1
/* output compare OC1B */
#define ChannelB                         2

#endif /* TIMER_1_PRIVATE_H_ */

                   