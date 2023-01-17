
#define F_CPU 8000000UL

#include "LIB/STD_TYPES.h"
#include "USART_INT.h"

void sendString(int8_t * string) ; 

int main(void)
{
    USART_Init(USART_8bit,disableParity,oneStopBit);
	
	USART_SetBaudRate(9600); 
	 
	
    while (1) 
    {
		USART_Send((int8_t)'A') ;
    }
}

void sendString(int8_t * string)
{

	while(string)
	{
		if (USART_Send(*string)==UART_OK)
		{
			string++;
		}
	}


} 