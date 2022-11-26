/**
 * @file TIMERS_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  TIMERS Implementation file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "TIMERS_INT.h"

#define NULL ((void *)0) 

void (*compareMatchISR) (void) = NULL; 
void (*OverFlowISR)     (void) = NULL ;

void TIMER0_Init(void) 
{
    /*Set wave generation mode */
    #if   TIMER0_WavMode == 0 
        TCCR0 = (0<<TCCR0_WGM01) | (0<<TCCR0_WGM00)  ;
    #elif TIMER0_WavMode == 1
        TCCR0 = (0<<TCCR0_WGM01) | (1<<TCCR0_WGM00)  ;
    #elif TIMER0_WavMode == 2
        TCCR0 = (1<<TCCR0_WGM01) | (0<<TCCR0_WGM00)  ;
    #elif TIMER0_WavMode == 3
        TCCR0 = (1<<TCCR0_WGM01) | (1<<TCCR0_WGM00)  ;
    #endif /*Set wave generation mode */

    /*set CTC Output Mode */
    #if TIMER0_CTCMode == 0 
        TCCR0 = (0<<TCCR0_COM00) | (0<<TCCR0_COM01) ;
    #elif TIMER0_CTCMode == 1
        TCCR0 = (0<<TCCR0_COM00) | (1<<TCCR0_COM01) ;
    #elif TIMER0_CTCMode == 2
        TCCR0 = (1<<TCCR0_COM00) | (0<<TCCR0_COM01) ;
    #elif TIMER0_CTCMode == 3
        TCCR0 = (1<<TCCR0_COM00) | (1<<TCCR0_COM01) ;
    #endif /*set CTC Output Mode */
    
    /* Clock Select */
    #if TIMER0_prescaler ==   0 
        TCCR0 = (0<<TCCR0_CS02) | (0<<TCCR0_CS01) | (0<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 1
        TCCR0 = (0<<TCCR0_CS02) | (0<<TCCR0_CS01) | (1<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 2
        TCCR0 = (0<<TCCR0_CS02) | (1<<TCCR0_CS01) | (0<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 3
        TCCR0 = (0<<TCCR0_CS02) | (1<<TCCR0_CS01) | (1<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 4
        TCCR0 = (1<<TCCR0_CS02) | (0<<TCCR0_CS01) | (0<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 5
        TCCR0 = (1<<TCCR0_CS02) | (0<<TCCR0_CS01) | (1<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 6
        TCCR0 = (1<<TCCR0_CS02) | (1<<TCCR0_CS01) | (0<<TCCR0_CS00) ; 
    #elif TIMER0_prescaler == 7
        TCCR0 = (1<<TCCR0_CS02) | (1<<TCCR0_CS01) | (1<<TCCR0_CS00) ; 
    #endif /* Clock Select */

}

void TIMER0_SetCompareMatchISR(void(*ISR)(void)) 
{
    /* set compare match interrupt enable */
    TIMSK |= (1<<TIMSK_OCIE0) ;
    /* clear overflow interrupt enable */
    TIMSK &= ~(1<<TIMSK_TOIE0) ;
    /* set compare match ISR callback */
    compareMatchISR = ISR ; 
} 

void TIMER0_SetOverflowISR(void(*ISR)(void)) 
{
    /* set overflow interrupt enable */
    TIMSK |= (1<<TIMSK_TOIE0) ;
    /* clear compare match interrupt enable */
    TIMSK &= ~(1<<TIMSK_OCIE0) ;
    /* set overflow ISR callback */
    OverFlowISR = ISR ; 
}

/**
 * @brief TIMER0 Compare Match ISR
 * 
 */
void __vector_10(void) __attribute__((signal)) ; 
void __vector_10(void)
{
    if(compareMatchISR!= NULL)
    {
        compareMatchISR() ;
    }
    else 
    {
        /* Do Nothing*/
    }
}
/**
 * @brief TIMER0 overflow ISR
 * 
 */
void __vector_11(void) __attribute__((signal)) ; 
void __vector_11(void)
{
    if(OverFlowISR!=NULL)
    {
        OverFlowISR() ;
    }
    else 
    {
         /* Do Nothing*/
    }
}