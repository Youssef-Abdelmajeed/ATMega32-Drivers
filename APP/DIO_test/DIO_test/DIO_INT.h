/**
 * @file DIO_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief DIO Interface file
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#define NC 255

typedef enum EN_PinNumber 
{
    PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
    PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
    PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
    PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,

} EN_PinNumber_t;

typedef enum EN_PortNumber 
{
    PORTA , PORTB , PORTC , PORTD
}EN_PortNumber_t;
 
typedef enum EN_Directions
{
    INPUT, OUTPUT, INPUT_PULLUP
}EN_Directions_t;

typedef enum EN_Values
{
    LOW, HIGH ,TOGGLE 
}EN_Values_t;

/**
 * @brief set DIO data direction for an individual pin 
 * 
 * @param pinNum pin number E.g.(PA0) for pin 0 port A 
 * @param pinDirection pin direction (INPUT, OUTPUT, INPUT_PULLUP)
 */
void DIO_setPinDirection(EN_PinNumber_t pinNum,EN_Directions_t pinDirection) ;

/**
 * @brief set DIO value for an individual pin
 * 
 * @param pinNum pin number E.g.(PA0) for pin 0 port A 
 * @param value pin value (LOW, HIGH ,TOGGLE)
 */
void DIO_setPinValue(EN_PinNumber_t pinNum, EN_Values_t value) ;

/**
 * @brief get DIO value for an individual pin
 * 
 * @param pinNum pin number E.g.(PA0) for pin 0 port A 
 * @return uint8_t  pin value 
 */
uint8_t DIO_getPinValue(EN_PinNumber_t pinNum) ;

/**
 * @brief set DIO data direction for whole port  
 * 
 * @param portNum port number  E.g.(PORTA, PORTB, PORTC, PORTD) 
 * @param pinDirection pin direction (INPUT, OUTPUT, INPUT_PULLUP)
 */
void DIO_setPortDirection(EN_PortNumber_t portNum,EN_Directions_t pinDirection) ;

/**
 * @brief set DIO value for whole port 
 * 
 * @param portNum port number  E.g.(PORTA, PORTB, PORTC, PORTD) 
 * @param value pin value (8 BIT ) 
 */
void DIO_setPortValue(EN_PortNumber_t portNum,uint8_t value) ;

#endif /* DIO_INT_H_ */