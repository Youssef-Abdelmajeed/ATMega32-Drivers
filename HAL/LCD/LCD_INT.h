/**
 * @file LCD_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief LCD interface file (HAL)
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define F_CPU 8000000UL

/**
 * @brief a struct to hold lcd control pins & data pins  
 * 
 */
typedef struct LCD
{
    /* Control Pins */  
    EN_PinNumber_t RS ;
    EN_PinNumber_t RW ;
    EN_PinNumber_t EN ;
    /* Data Pins */  
    EN_PinNumber_t dataPins[8] ;

    /* not meant to be initialized */ 
    _Bool is8Bit ;      /* flag to indicate if the screen is in 8 bit mode or not */
    
	uint8_t cur_pos;      /* cursor position */

}LCD_t;

/**
 * @brief LCD initialization setup
 * 
 * @param lcd the lcd object 
 */
void LCD_Init(LCD_t *lcd) ;

/**
 * @brief function to send command to LCD controller
 * 
 * @param lcd the lcd object 
 * @param command 
 */
void LCD_SendCommand(LCD_t *lcd,uint8_t command) ;

/**
 * @brief function that character with respect to the 16x2 boundary to LCD controller
 * 
 * @param lcd the lcd object 
 * @param data
 */
void LCD_SendChar(LCD_t *lcd ,uint8_t data) ;

/**
 * @brief function that sends string to LCD controller
 * 
 * @param lcd the lcd object 
 * @param string 
 */
void LCD_Write(LCD_t *lcd,const char * string) ;

/**
 * @brief function that write numbers to LCD controller (32 bit)
 * 
 * @param lcd the lcd object
 * @param n integer number 
 */
void LCD_WriteNumber(LCD_t *lcd,uint32_t n)  ;

/**
 * @brief function that change the coordinates of the cursor 
 * @param lcd the lcd object 
 * @param x 
 * @param y 
 */
void LCD_Goto(LCD_t *lcd,uint8_t x ,uint8_t y) ; 
/**
 * @brief function to create custom characters and store it at CGRAM
 * 
 * @param pos  new char position 0 - 7 (only) 
 * @param chararr new char array representation
 */
void LCD_CreateChar(LCD_t *lcd ,uint8_t pos ,uint8_t chararr[] ) ;


#endif /* LCD_INT_H_ */