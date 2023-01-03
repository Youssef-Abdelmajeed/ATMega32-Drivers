/**
 * @file main.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  toggle led every 1 sec using timer 0 in CTC mode 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "DIO_INT.h"
#include "GIE_INT.h"
#include "TIMERS_INT.h"

/* led on PA0 */
#define ledpin PA0 
#define ledpin2 PA1

void LED (void) ; 
void LED2 (void);

int main(void)
{
    DIO_setPinDirection(ledpin,OUTPUT) ;
	/*init timer 0 to be in CTC mode and Prescaler to none */
	Timer_Init(TIMER0,Noprescaler,CTC) ;
	/* set compare match ISR Callback */
	Timer_SetCTC_Callback(TIMER0,&LED) ; 
	/* set compare value */
	Timer_SetCTCRegister(TIMER0,250) ; 
	
	DIO_setPinDirection(ledpin2,OUTPUT) ;
	/*init timer 2 to be in CTC mode and Prescaler to none */
	Timer_Init(TIMER2,Noprescaler,CTC) ;
	/* set compare match ISR Callback */
	Timer_SetCTC_Callback(TIMER2,&LED2) ;
	/* set compare value */
	Timer_SetCTCRegister(TIMER2,250) ; 
	/* turn on global interrupt enable */
	GIE_Enable() ; 
    while (1) 
    {
		
    }
}

void LED (void)
{
	/* counter to count the number of compare matches */
	static uint16_t counter = 0 ;
	/* if the number of compare matches is 2000 which is equal to 0.5 sec if the compare value was 250 */
	if (counter==2000)
	{
		/* reset the counter */
		counter = 0 ;
		/* toggle led pin */
		DIO_setPinValue(ledpin,TOGGLE) ;
	}
	counter++ ; 
}
void LED2 (void)
{
	/* counter to count the number of compare matches */
	static uint16_t counter = 0 ;
	/* if the number of compare matches is 4000 which is equal to 1 sec if the compare value was 250 */
	if (counter==4000)
	{
		/* reset the counter */
		counter = 0 ;
		/* toggle led pin */
		DIO_setPinValue(ledpin2,TOGGLE) ;
	}
	counter++ ;
}
