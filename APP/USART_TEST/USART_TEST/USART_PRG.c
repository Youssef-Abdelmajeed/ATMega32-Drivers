/**
 * @file USART_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Universal Synchronous Asynchronous Receiver Transmitter Implementation file 
 * @version 0.1
 * @date 2023-01-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "USART_REG.h"
#include "USART_INT.h"

/* Temporary placeholder for UCSRC register */
uint8_t UCSRC_TEMP ;

/* number of data to send/Receive */
uint8_t global_No_of_Bits ;

static uint8_t USART_SelectDataSize(uint8_t dataSize)
{
    uint8_t errorState ; 
    if(dataSize>7||dataSize==4||dataSize==5||dataSize==6)
    {
        errorState = WRONG_SIZE ; 
    }
    else 
    {
        global_No_of_Bits = dataSize ; 
        /* Set MSB of dataSize in the bit 2 in UCSRA register */
        UCSRA |= (dataSize&0X04) ;

        /* Set LSB of dataSize in bits 2:1 in UCSRC placeholder */
        UCSRC_TEMP |= (dataSize&0x03)<<1 ;  
        
        errorState = UART_OK ; 
    }
    return errorState ;  
}
static uint8_t USART_SetParity(uint8_t parityMode)
{
    uint8_t errorState ; 
    if(parityMode>3 ||parityMode==1)
    {
        errorState = WRONG_Parity ; 
    }
    else 
    {
        /*Set bits 5:4 of parityMode in UCSRC placeholder */
        UCSRC_TEMP |= (parityMode<<0x04) ; 

        errorState = UART_OK ; 
    }
    return errorState ; 
}
static uint8_t USART_SetStopBits(uint8_t StopBits)
{
    uint8_t errorState  ; 
    if(StopBits>1)
    {
        errorState = WRONG_STOP_BITS ; 
    }
    else
    {
        /* set stop bit in UCSRC placeholder bit 3 */
        UCSRC_TEMP |=(StopBits<<3) ;
        errorState = UART_OK ; 
    }
    return errorState ; 
}
uint8_t USART_Init(uint8_t dataSize, uint8_t parityMode, uint8_t stopBits)
{
    /* initialized UCSRC placeholder and select UCSRC */
    UCSRC_TEMP = 0 ;
	
	setBit(UCSRC_TEMP,UCSRC_URSEL) ;
	
	setBit(UCSRB,UCSRB_TXEN) ;
	
	setBit(UCSRB,UCSRB_RXB8) ;

    if(USART_SelectDataSize(dataSize)!=UART_OK)
    {
        return WRONG_SIZE ;
    }
    if(USART_SetParity(parityMode)!=UART_OK)
    {
        return WRONG_Parity; 
    }
    if(USART_SetStopBits(stopBits)!=UART_OK)
    {
       return WRONG_STOP_BITS ;  
    }
    
    /* Set all selected configuration */
    UCSRC = UCSRC_TEMP ; 
	
	return UART_OK ; 
}
uint8_t USART_SetBaudRate(uint16_t baudRate)
{   uint8_t errorState  ; 
    uint16_t UBRR_Value = ((FOSC/(16UL*baudRate))-1UL); 
    if (UBRR_Value>4095)
    {
        errorState = WRONG_BAUD_RATE ; 
    }
    else
    {
        errorState = UART_OK ;
        /* Set LSB */ 
        UBRRL = UBRR_Value ; 
        /* Set MSB */
        UBRRH = UBRR_Value>>8 ;
    }
    return errorState ; 
}
uint8_t USART_Receive(int16_t *result)
{
    
    /* wait for data */
    while (!getBit(UCSRA,UCSRA_RXC)) ; 
    
    *result = UDR ;  
    
    if(global_No_of_Bits==USART_9bit)
    {
        /* Get the ninth data bit of the received character */
        *result |= (getBit(UCSRB,UCSRB_RXB8)<<8); 
    }
    if(getBit(UCSRA,UCSRA_PE))
    {
        /* Parity Error */
        return PARITY_ERROR ;
    }
    if(getBit(UCSRA,UCSRA_DOR))
    {
        /* Data OverRun */
        return DATA_OVER_RUN ; 
    }
    if(getBit(UCSRA,UCSRA_FE))
   {
        /* Frame Error */
        return FRAME_ERROR ; 
   }

   return UART_OK ; 
}
uint8_t USART_Send(int16_t data)
{
    /* wait till data register is empty */
    while (!getBit(UCSRA,UCSRA_UDRE)); 

    if(global_No_of_Bits==USART_9bit)
    {
        /*clear the ninth data bit of data*/
        UCSRB &= UCSRB_TXB8_MASK ; 
        
        /* Set the new ninth data bit */
        UCSRB|= getBit(data,8) ; 
    }

    /* send the first 8 bit of data */
    UDR = (uint8_t)data ;  

	return UART_OK ; 
}