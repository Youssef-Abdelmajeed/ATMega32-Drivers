#define F_CPU 8000000UL
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO_INT.h"
#include "SPI_INT.h"
#include <util/delay.h>
uint8_t spi_data = 0 ; 

int main(void)
{
	/*test pin output*/
	DIO_setPortDirection(PORTA,OUTPUT) ;
	DIO_setPinValue(PB4,INPUT) ;  
	DIO_setPinDirection(PB5,INPUT) ;
	DIO_setPinDirection(PB6,OUTPUT) ;
	DIO_setPinDirection(PB7,INPUT) ;
	SPI_SlaveInit(0,MSB_FIRST) ; 

    while (1) 
    {
		spi_data = SPI_Tranceive(0X01) ;
		_delay_us(100);
		DIO_setPortValue(PORTA,spi_data) ; 
		
    }
}

