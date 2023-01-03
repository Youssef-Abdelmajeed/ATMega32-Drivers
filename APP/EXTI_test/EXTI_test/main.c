/**
 * @file main.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  External Interrupt test (button to increment and button to decrement the counter and show the value on a port ) 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "DIO_INT.h"
#include "GIE_INT.h"
#include "EXTI_INT.h"

#define button_countup   INT0_PIN
#define button_countdown INT1_PIN
#define PORT PORTA

/* 8bit counter */ 
volatile int8_t counter = 0; 

void countup(void)
{
	counter++ ;
}
void countdown(void)
{
	counter --;
}

int main(void)
{
	/* set buttons to be input pull up */
	DIO_setPinDirection(button_countup,INPUT_PULLUP) ; 
	DIO_setPinDirection(button_countdown,INPUT_PULLUP) ;
	
	/*output port */
	DIO_setPortDirection(PORT,OUTPUT) ;
	
	/* set global Interrupt enable */
	GIE_Enable() ;
	
	/* init Interrupts */
	EXTI_InitIntrrupt(INT0, RISING, &countup)   ; 
	EXTI_InitIntrrupt(INT1, RISING, &countdown) ;
	
	

    while (1) 
    {
		DIO_setPortValue(PORT,counter) ;
    }
}

