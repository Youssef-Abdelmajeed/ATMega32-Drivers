/**
 * @file DIO_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Implementation file 
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "DIO_INT.h"
#include "DIO_REG.h"

/* All ports registers */
volatile uint8_t * DIO_Registers[4][3]=
{
    {PORTA_REG,DDRA_REG,PINA_REG},
    {PORTB_REG,DDRB_REG,PINB_REG},
    {PORTC_REG,DDRC_REG,PINC_REG},
    {PORTD_REG,DDRD_REG,PIND_REG}
} ;
/**
 * @brief get pin number from pin name 
 * 
 * @param pinnum pin name
 * @return uint8_t pin number 
 */
inline static uint8_t getPinNumber(EN_PinNumber_t pinnum)
{
    if(pinnum>=0 && pinnum<=7)         return    pinnum     ; 
    else if (pinnum>=8  && pinnum<=15) return   (pinnum-8)  ; 
    else if (pinnum>=16 && pinnum<=23) return   (pinnum-16) ;
    else if (pinnum>=24 && pinnum<=31) return   (pinnum-24) ;
	return NC ; 
}
/**
 * @brief get port number from pin name
 * 
 * @param pinnum pin name
 * @return uint8_t port number 
 */
inline static uint8_t getPortNumber(EN_PinNumber_t pinnum)
{
    if(pinnum>=0 && pinnum<=7)         return    PORTA  ; 
    else if (pinnum>=8  && pinnum<=15) return    PORTB  ; 
    else if (pinnum>=16 && pinnum<=23) return    PORTC  ;
    else if (pinnum>=24 && pinnum<=31) return    PORTD  ;
	return NC ;
}

void DIO_setPinDirection(EN_PinNumber_t pinNum,EN_Directions_t pinDirection) 
{
	
    /* get pin number and port number */
    uint8_t pin = getPinNumber(pinNum) , port = getPortNumber(pinNum) ;
	/* select DDRX Register */
	volatile uint8_t  * DDRX =  (DIO_Registers[port][1]) ;
	/* select PORTX Register */ 
	volatile uint8_t  * PORTX = (DIO_Registers[port][0]) ;
    switch (pinDirection)
    {
    case INPUT:
        /* set DDRX to 0 to set as input  */
        clearBit((*DDRX),pin) ;
        break;
    case OUTPUT:
        /* set PORTX to 1 to set as output */
        setBit((*DDRX),pin) ;
        break;
    case INPUT_PULLUP:
        /* set PORTX to 1 to active the pull up resistor */
        setBit((*PORTX),pin) ;  
        /* set DDRX to 0 to set as input  */
        clearBit((*DDRX),pin) ;
        break;
    default:
        /* do nothing */
        break;
    }

}

void DIO_setPinValue(EN_PinNumber_t pinNum, EN_Values_t value) 
{
    /* get pin number and port number */
    uint8_t pin = getPinNumber(pinNum) , port = getPortNumber(pinNum) ;
	/* select PORTX Register */
   	volatile uint8_t  * PORTX = (DIO_Registers[port][0]) ;
    switch (value)
    {
        
    case LOW:
        /* set the selected pin to LOW */
       clearBit((*PORTX),pin) ;
        break;    
    case HIGH:
        /* set the selected pin to HIGH */
        setBit((*PORTX),pin) ;
        break;
    case TOGGLE:
        /*TOGGLE the selected pin */
        toggleBit((*PORTX),pin) ;
        break;
    
    default:
        /*do nothing*/
        break;
    }
}

uint8_t DIO_getPinValue(EN_PinNumber_t pinNum) 
{
    /* get pin number and port number */
    uint8_t pin = getPinNumber(pinNum) , port = getPortNumber(pinNum) ;
	/* select PINX Register */ 
	volatile uint8_t * PINX = (DIO_Registers[port][2]);
   /* return pin value */
    return getBit((*PINX) ,pin);
}

void DIO_setPortDirection(EN_PortNumber_t portNum,EN_Directions_t pinDirection) 
{
	/* select DDRX Register */
	volatile uint8_t  * DDRX =  (DIO_Registers[portNum][1]) ;
	/* select PORTX Register */
	volatile uint8_t  * PORTX = (DIO_Registers[portNum][0]) ;
	
    switch (pinDirection)
    {
    case INPUT:
        /* set the whole port as input */
        *DDRX = 0X00 ; 
        break;
    case OUTPUT:
        /* set the whole port as output */
       *DDRX= 0XFF ; 
        break;
    case INPUT_PULLUP:
        /* active pull up resistor for the whole port */
       *PORTX =0xFF; 
        /* set the whole port as input */
      *DDRX = 0X00 ; 
        break;
    default:
        /* do nothing */
        break;
    }
}

void DIO_setPortValue(EN_PortNumber_t portNum,uint8_t value) 
{
	/* select PORTX Register */
    volatile uint8_t  * PORTX = (DIO_Registers[portNum][0]) ;
	/* set the port value */	
    *PORTX = value ;
}