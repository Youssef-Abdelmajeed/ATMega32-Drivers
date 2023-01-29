/**
 * @file TIMERS_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  TIMERS [Timer0 ,Timer2] Interface file 
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TIMERS_INT_H_
#define TIMERS_INT_H_

/*Timer 0 ,2 modes  */
typedef enum prescalerModes 
{
   CounterMode, Noprescaler,prescaler8, prescaler64, prescaler256, prescaler1024, ExFalling, ExRising 
} prescalerModes_t ; 
/*  timers wave modes */
typedef enum waveModes 
{
    Normal, PWM_PhaseCorrect, CTC, Fast_PWM 
}waveModes_t ; 

/* 8 bit timers in AVR ATMEGA32 */
typedef  enum Timers
{
    TIMER0, TIMER2 
}Timers_t ; 

/**
 * @brief set timer prescaler mode 
 * 
 * @param timer TIMER0, TIMER2 
 * @param Pmode CounterMode, Noprescaler,prescaler8, prescaler64, prescaler256, prescaler1024, ExFalling, ExRising 
 */
void Timer_SetPrescaler(Timers_t timer , prescalerModes_t Pmode) ;

/**
 * @brief set timer wave mode 
 * 
 * @param timer TIMER0, TIMER2
 * @param Wmode Normal, PWM_PhaseCorrect, CTC, Fast_PWM
 */
void Timer_SetWaveMode(Timers_t timer , waveModes_t Wmode) ;

/**
 * @brief 
 * 
 * @param timer set timer wave mode and prescaler 
 * @param Pmode CounterMode, Noprescaler,prescaler8, prescaler64, prescaler256, prescaler1024, ExFalling, ExRising 
 * @param Wmode Normal, PWM_PhaseCorrect, CTC, Fast_PWM
 */
void Timer_Init(Timers_t timer , prescalerModes_t Pmode ,  waveModes_t Wmode) ; 

/**
 * @brief set timer in normal mode (overflow mode) and set callback to it 
 * 
 * @param timer TIMER0, TIMER2
 * @param isr callback function (called when timer overflow happen)
 */
void Timer_SetOverflow_Callback(Timers_t timer , void(*isr)(void)) ;

/**
 * @brief set timer in CTC mode (Compare match mode) and set callback to it 
 * 
 * @param timer TIMER0, TIMER2
 * @param isr callback function (called when timer compare match happen)
 */
void Timer_SetCTC_Callback(Timers_t timer , void(*isr)(void)) ; 

/**
 * @brief preload timer register in normal mode 
 * 
 * @param timer TIMER0, TIMER2
 * @param value  8 bit value 
 */
void Timer_SetOVFRegister(Timers_t timer,uint8_t value) ;

/**
 * @brief set compare match value in CTC mode 
 * 
 * @param timer TIMER0, TIMER2
 * @param value  8 bit value 
 */
void Timer_SetCTCRegister(Timers_t timer,uint8_t value) ;

#endif /* TIMERS_INT_H_ */