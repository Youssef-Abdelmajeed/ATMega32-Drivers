
#define F_CPU 8000000UL

#include "LIB/STD_TYPES.h"
#include "USART_INT.h"
#include "DIO_INT.h"
void sendString(int8_t * string) ; 
uint16_t Data_in ; 
int main(void)
{
    USART_Init(USART_8bit,disableParity,oneStopBit);
	
	USART_SetBaudRate(9600); 
	 
	DIO_setPortDirection(PORTA,OUTPUT) ;

    while (1) 
    {
		/*
		sendString("HI I am Youssef :)") ;
		sendString("\r\n") ;
		sendString("HI in new line ");
		sendString("\r\n") ;
		*/
		USART_Receive(&Data_in) ; 
		if (Data_in=='A')
		{
			DIO_setPinValue(PA0,HIGH) ; 
			sendString("\r\nLED1 IS ON\r\n") ; 
		}
		else if (Data_in =='B')
		{
			DIO_setPinValue(PA1,HIGH) ;
			sendString("\r\nLED2 IS ON\r\n") ;
		}
		else if(Data_in == 'C')
		{
			DIO_setPinValue(PA2,HIGH) ;
			sendString("\r\nLED3 IS ON\r\n") ;
		}
		else
		{
			DIO_setPinValue(PA0,LOW) ;
			DIO_setPinValue(PA1,LOW) ;
			DIO_setPinValue(PA2,LOW) ;
			sendString("\r\nLEDs IS OFF\r\n") ;
		}
	}
}

void sendString(int8_t * string)
{

	while(*string!='\0')
	{
		if (USART_Send(*string)==UART_OK)
		{
			string++;
		}
	}


} 