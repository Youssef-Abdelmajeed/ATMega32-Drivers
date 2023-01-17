/**
 * @file USART_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Universal Synchronous Asynchronous Receiver Transmitter interface file 
 * @version 0.1
 * @date 2023-01-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USART_INT_H_ 
#define USART_INT_H_ 


/* BIT Masks */
#define  UCSRC_MASK          0b10000000
#define  UCSRB_TXB8_MASK     0b11111110
/********************/

/* Error States */
#define WRONG_SIZE           1
#define UART_OK              2
#define WRONG_Parity         3
#define WRONG_STOP_BITS      4
#define WRONG_BAUD_RATE      5
#define DATA_OVER_RUN        7
#define PARITY_ERROR	     8
#define FRAME_ERROR          9
/********************/

/* Data size */
#define  USART_5bit           0
#define  USART_6bit           1
#define  USART_7bit           2
#define  USART_8bit           3
#define  USART_9bit           7
/********************/

/* parity modes*/
#define  disableParity        0
#define  evenParity           2
#define  oddParity            3
/********************/

/* StopBits */
#define oneStopBit            0
#define twoStopBits           1
/********************/

/* CLOCK */
#define FOSC  8000000UL /* oscillator clock */

/**
 * @brief Initialize USART protocol 
 * 
 * @param dataSize      5, 6, 7, 8, 9 bits modes 
 * @param parityMode    disableParity, evenParity, oddParity 
 * @param stopBits      oneStopBit, twoStopBits 
 * @return uint8_t error state 
 */
uint8_t USART_Init(uint8_t dataSize, uint8_t parityMode, uint8_t stopBits);
/**
 * @brief Set USART protocol BaudRate (Asynchronous mode) 
 * 
 * @param baudRate 
 * @return uint16_t error state 
 */
uint8_t USART_SetBaudRate(uint16_t baudRate) ; 
/**
 * @brief Receive data using USART protocol 
 * 
 * @param result the received data 
 * @return uint8_t error state 
 */
uint8_t USART_Receive(int16_t *result); 
/**
 * @brief Send data using USART protocol 
 * 
 * @param data data to be send
 * @return uint8_t error state 
 */
uint8_t USART_Send(int16_t data); 

#endif /*USART_INT_H_*/