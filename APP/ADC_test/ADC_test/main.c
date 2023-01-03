/**
 * @file main.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Read Analog value from potentiometer and write the value on some LEDs 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "DIO_INT.h"
#include "ADC_INT.h"
#include "GIE_INT.h"
#define sync	1 
#define async	2 

#define  debug sync
//#define  debug async

uint16_t reading =0 ;

#if debug==async
void ADC_happend(void)
{
	/*Write the first 8 bit to portC*/
	DIO_setPortValue(PORTC,reading) ;
	/*get the remained 2 bit and write it to portB*/
	DIO_setPortValue(PORTB,reading>>8) ;
}
#endif

int main(void)
{
	/* Set ADC0 pin to input  */
	DIO_setPinDirection(PA0,INPUT) ;
	/* set two ports as outputs */
	DIO_setPortDirection(PORTB,OUTPUT) ;
	DIO_setPortDirection(PORTC,OUTPUT) ; 
	
	GIE_Enable() ;

	/* init ADC  */
	ADC_Init(AREF,prescaller128) ; 
 	while (1) 
    {
		#if debug == sync
		/* if ADC conversion is ok*/
		if (ADC_Read(ADC0,&reading)==ADC_OK)
		{
			/*Write the first 8 bit to portB*/
			DIO_setPortValue(PORTB,reading) ;
			/*get the remained 2 bit and write it to portC*/
			DIO_setPortValue(PORTC,reading>>8) ;
		}
		#endif
		
		#if debug == async
		ADC_ReadAsync(ADC0,&reading,&ADC_happend) ;
		#endif
		
    }
}

