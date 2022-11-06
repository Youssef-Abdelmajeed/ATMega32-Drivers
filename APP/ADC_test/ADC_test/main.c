/**
 * @file main.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Read Analog value from potentiometer and write the value on some leds 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "DIO_INT.h"
#include "ADC_INT.h"


int main(void)
{
	/* Set ADC0 pin to input  */
	DIO_setPinDirection(PA0,INPUT) ;
	/* set two ports as outputs */
	DIO_setPortDirection(PORTB,OUTPUT) ;
	DIO_setPortDirection(PORTC,OUTPUT) ; 
	/* init ADC  */
	ADC_Init(AREF,prescaller128) ; 
	uint16_t reading =0 ; 
 	while (1) 
    {
		reading = ADC_Read(ADC0) ; 
		DIO_setPortValue(PORTB,reading) ;
		DIO_setPortValue(PORTC,reading>>8) ;
    }
}

