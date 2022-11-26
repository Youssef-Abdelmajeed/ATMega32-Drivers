/**
 * @file TIMERS_config.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  TIMERS configuration file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TIMERS_CON_H_
#define TIMERS_CON_H_ 

/* 
    Waveform Generation Modes 
        Normal                 0
        PWM_PhaseCorrect       1
        CTC                    2
        FAST_PWM               4 
*/

/* TIMER0 Waveform Generation Mode */
#define TIMER0_WavMode  2

/* Compare Match Output Mode */
#define TIMER0_CTCMode  0 

/*
    Clock Select Bit Description
        No clock source (Timer/Counter stopped).                    0
        clkI/O/(No prescaling)                                      1
        clkI/O/8 (From prescale                                     2
        clkI/O/64 (From prescaler)                                  3
        clkI/O/256 (From prescaler)                                 4
        clkI/O/1024 (From prescaler)                                5
        External clock source on T0 pin. Clock on falling edge.     6
        External clock source on T0 pin. Clock on rising edge.      7
*/
#define TIMER0_prescaler    1  


#endif /*TIMERS_CON_H_*/