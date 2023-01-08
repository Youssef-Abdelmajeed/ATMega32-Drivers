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

#define Sync		1 
#define Async		2 
#define chainAsync	3

//#define  debug sync
#define  debug chainAsync

uint16_t reading =0 ;
uint16_t channelsReadings[2]= {0,0} ;
uint8_t channelsarr[2] = {PA0,PA1} ;
	 
#if debug==chainAsync
void ADC_happend(void)
{
	DIO_setPortValue(PORTC,channelsReadings[0]) ;
	DIO_setPortValue(PORTB,channelsReadings[1]) ;
}
#endif

#if debug==Async
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
	/* Set ADC1 pin to input  */
	DIO_setPinDirection(PA1,INPUT) ;

	/* set two ports as outputs */
	DIO_setPortDirection(PORTB,OUTPUT) ;
	DIO_setPortDirection(PORTC,OUTPUT) ; 
		
	GIE_Enable() ;

	/* init ADC  */
	ADC_Init(AREF,prescaller128) ; 
 	while (1) 
    {
		#if debug == Sync
		/* if ADC conversion is OK*/
		if (ADC_Read(ADC0,&reading)==ADC_OK)
		{
			/*Write the first 8 bit to portB*/
			DIO_setPortValue(PORTB,reading) ;
			/*get the remained 2 bit and write it to portC*/
			DIO_setPortValue(PORTC,reading>>8) ;
		}
		#endif
		
		#if debug == Async
		ADC_ReadAsync(ADC0,&reading,&ADC_happend) ;
		#endif
		
		#if debug == chainAsync
		ST_ADC_Chain_t chain1 = {.channelsArr=channelsarr,.length = 2 , .results=channelsReadings,&ADC_happend} ;
		ADC_ReadChainAsync(&chain1) ;
		#endif
		
    }
}

