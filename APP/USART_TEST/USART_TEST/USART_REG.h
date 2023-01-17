/**
 * @file USART_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Universal Synchronous Asynchronous Receiver Transmitter registers file 
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USART_REG_H_ 
#define USART_REG_H_ 

/* USART I/O Data Register */
#define UDR                 (*(volatile uint8_t *)(0x2C)) 

/* USART Control and Status Register A */
#define UCSRA               (*(volatile uint8_t *)(0x2B)) 
/*Multi-processor Communication Mode*/
#define UCSRA_MPCM          0 
/*Double the USART Transmission Speed*/
#define UCSRA_U2X           1
/*Parity Error*/
#define UCSRA_PE            2
/*Data OverRun*/
#define UCSRA_DOR           3
/*Frame Error*/
#define UCSRA_FE            4
/*USART Data Register Empty*/
#define UCSRA_UDRE          5
/*USART Transmit Complete*/
#define UCSRA_TXC           6
/*USART Receive Complete*/
#define UCSRA_RXC           7

/* USART Control and Status Register B */
#define UCSRB               (*(volatile uint8_t *)(0x2A))
/*Transmit Data Bit 8*/
#define UCSRB_TXB8          0 
/*Receive Data Bit 8*/
#define UCSRB_RXB8          1
/*Character Size 2*/
#define UCSRB_UCSZ2         2
/*Transmitter Enable*/
#define UCSRB_TXEN          3
/*Receiver Enable*/
#define UCSRB_RXEN          4
/*USART Data Register Empty Interrupt Enable*/
#define UCSRB_UDRIE         5
/*TX Complete Interrupt Enable*/
#define UCSRB_TXCIE         6
/*RX Complete Interrupt Enable*/
#define UCSRB_RXCIE         7

#define UCSRC               (*(volatile uint8_t *)(0x40)) 
/*Clock Polarity*/
#define UCSRC_UCPOL         0
/*Character Size 0*/
#define UCSRC_UCSZ0         1
/*Character Size 1*/
#define UCSRC_UCSZ1         2
/*Stop Bit Select*/
#define UCSRC_USBS          3
/*Parity Mode 0*/
#define UCSRC_UPM0          4
/*Parity Mode 1*/
#define UCSRC_UPM1          5
/*USART Mode Select*/
#define UCSRC_UMSEL         6
/*Register Select*/
#define UCSRC_URSEL         7

#define UBRRH               (*(volatile uint8_t *)(0x40)) 

#define UBRRL               (*(volatile uint8_t *)(0x29)) 




#endif /* USART_REG_H_ */