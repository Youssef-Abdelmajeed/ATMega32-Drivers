#define F_CPU 8000000UL
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO_INT.h"
#include "SPI_INT.h"

uint8_t data_back = 0 ; 
int main(void)
{
	DIO_setPinDirection(PA0,OUTPUT) ;
	DIO_setPinDirection(PB4,INPUT_PULLUP) ; 
	DIO_setPinDirection(PB5,OUTPUT) ;
	DIO_setPinDirection(PB6,INPUT) ;
	DIO_setPinDirection(PB7,OUTPUT) ;
	if(SPI_MasterInit(SPI_Prescaler16,0,MSB_FIRST) == SPI_OK)
	{
		DIO_setPinValue(PA0,HIGH) ; 
	} 
	
    while (1) 
    {
		//data_back = 0 ; 
		SPI_Tranceive(0X0F) ; 	
    }
}

