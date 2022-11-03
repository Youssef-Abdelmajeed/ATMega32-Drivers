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

void LED (void) ; 

int main(void)
{
    DIO_setPinDirection(ledpin,OUTPUT) ;
	/*init timer 0 to be in CTC mode and Prescaler to none (TIMERS_config.h)*/
	TIMER0_Init() ; 
	/* set compare match ISR Callback */
	TIMER0_SetCompareMatchISR(&LED) ; 
	/* set compare value */
	OCR0 = 250 ;  
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
	/* if the number of compare matches is 4000 which is equal to 1 sec if the compare value was 250 */
	if (counter==4000)
	{
		/* reset the counter */
		counter = 0 ;
		/* toggle led pin */
		DIO_setPinValue(ledpin,TOGGLE) ;
	}
	counter++ ; 
}