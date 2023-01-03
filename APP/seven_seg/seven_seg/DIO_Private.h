/*
 * DIO_Private.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Mostafa Rashed
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
//Define four port registers
#define DIO_u8_DDRA *((volatile u8*)0x3A)
#define DIO_u8_DDRB *((volatile u8*)0x37)
#define DIO_u8_DDRC *((volatile u8*)0x34)
#define DIO_u8_DDRD *((volatile u8*)0x31)
//
#define DIO_u8_PORTA *((volatile u8*)0x3B)
#define DIO_u8_PORTB *((volatile u8*)0x38)
#define DIO_u8_PORTC *((volatile u8*)0x35)
#define DIO_u8_PORTD *((volatile u8*)0x32)
//
#define DIO_u8_PINA *((volatile u8*)0x39)
#define DIO_u8_PINB *((volatile u8*)0x36)
#define DIO_u8_PINC *((volatile u8*)0x33)
#define DIO_u8_PIND *((volatile u8*)0x30)

//
#define DIO_u8_INPUT  0
#define DIO_u8_OUTPUT 1

#define MIN_u8_PORT_ID         0
#define MAX_u8_PORT_ID         3
//
#define MIN_u8_PIN_ID          0
#define MAX_u8_PIN_ID          7
//
#define MIN_u8_PIN_VAL         0
#define MAX_u8_PIN_VAL         1
//
#define MIN_u8_PIN_Dir         0
#define MAX_u8_PIN_Dir         1
//
#define MIN_u8_PORT_VAL        0b00000000
#define MAX_u8_PORT_VAL        0b11111111
//
#define MIN_u8_PORT_DIR        0b00000000
#define MAX_u8_PORT_DIR        0b11111111
//
#endif /* DIO_PRIVATE_H_ */
