/**
 * @file LCD_PRG.C
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief LCD Implementation file (HAL)
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_INT.h"
#include "LCD_COM.h"
#include "LCD_INT.h" 
#include <util/delay.h>
/**
 * @brief LCD_PRG static function to generate 5 ms pulse on enable pin 
 *             5ms
 *            _____  
 *           |     |
 * MC pin ___|     |___ EN
 * 
 * @param lcd the lcd object 
 * 
 */
static void _PulseEnable(LCD_t *lcd)
{

	DIO_setPinValue(lcd->EN,LOW) ;
	_delay_us(1) ;
	DIO_setPinValue(lcd->EN,HIGH) ;
	_delay_us(500) ;
	DIO_setPinValue(lcd->EN,LOW) ;
	_delay_us(1) ;

}

/**
 * @brief LCD_PRG static function to write a data on 4 bit mode 
 * 
 * @param lcd the lcd object 
 * @param data  command or data to be written to the screen 
 */
static void _write4bit(LCD_t *lcd,uint8_t data)
{
    
   for(uint8_t i=0,j=4 ; i<4;i++)
        {
            DIO_setPinValue(lcd->dataPins[j++],getBit(data,i)) ;
        }
        _PulseEnable(lcd);
} 

/**
 * @brief LCD_PRG static function to write a data on 8 bit mode 
 * 
 * @param lcd the lcd object 
 * @param data command or data to be written to the screen  
 */
static void _write8bit(LCD_t *lcd,uint8_t data)
{
   for(uint8_t i=0 ; i<8;i++)
        {
            DIO_setPinValue(lcd->dataPins[i],getBit(data,i)) ;
        }
        _PulseEnable(lcd);
}

/**
 * @brief LCD_PRG static function to set the lcd pin configuration
 * 
 * @param LCD_CONFIG Pins configuration for lcd object 
 */
static void _LCD_SetPinConfig (LCD_t *LCD_CONFIG )
{
    /* Init lcd private members */ 
	LCD_CONFIG->cur_pos = 0 ;
    LCD_CONFIG->is8Bit = 1;

    /* Set control pins */ 
    DIO_setPinDirection(LCD_CONFIG->RS,OUTPUT);
    DIO_setPinDirection(LCD_CONFIG->RW,OUTPUT);
    DIO_setPinDirection(LCD_CONFIG->EN,OUTPUT);
    
    /* check D0 ~ D3 for Not connected (NC) pins */
    for(uint8_t i=0 ;(i<4 && LCD_CONFIG->is8Bit);i++)
    {
        LCD_CONFIG->is8Bit = (LCD_CONFIG->dataPins[i]==NC)? 0 : 1 ; 
    }

    if (LCD_CONFIG->is8Bit)
    {
        /*Set all data pins*/ 
        for(uint8_t i =0 ; i<8 ;i++)
        {
            DIO_setPinDirection(LCD_CONFIG->dataPins[i],OUTPUT) ;
        }
    }
    else
    {
        /*Set from data pins D4 ~ D7 */ 
        for(uint8_t i =4 ; i<8 ;i++)
        {
            DIO_setPinDirection(LCD_CONFIG->dataPins[i],OUTPUT) ;
        }
    }
}

void LCD_Init(LCD_t *lcd) 
{
    _LCD_SetPinConfig(lcd);
    /* wait for 30 ms after the power of the LCD */
    _delay_ms(30) ;
    
    LCD_SendCommand(lcd,LCDHome) ;
	/* wait for 39 us */
	_delay_us(39) ;

    /* function set */
    LCD_SendCommand(lcd,(lcd->is8Bit)?functionSet8bit:functionSet4bit) ; /* Select Mode */ 
    /* wait for 39 us */
    _delay_us(39) ;
    
    /* Display ON/OFF */
    LCD_SendCommand(lcd,DisplayOn_OFF) ;
    /* wait for 39 us */
    _delay_us(39) ; 

    /* Display clear */ 
    LCD_SendCommand(lcd,DisplayClear) ;
    /* wait for 1.53 ms */
    _delay_ms(1.53) ; 

    /*Entry mode set */ 
    LCD_SendCommand(lcd,EntryModeSet) ;
    /* wait for 2 ms */
    _delay_ms(2) ; 
    /*  END */

}

void LCD_SendCommand(LCD_t *lcd,uint8_t command) 
{   
    /* Set to control register  */ 
    DIO_setPinValue(lcd->RS,LOW);
    /* Set to write Mode */ 
    DIO_setPinValue(lcd->RW,LOW);

    if(lcd->is8Bit)
    {
        /* send the whole command */ 
        _write8bit(lcd,command) ;
    }
    else
    {
        /* send the second 4 bits */
        _write4bit(lcd,command>>4) ; 
        /* send the first 8 bits */ 
        _write4bit(lcd,command) ; 
    }
}

/**
 * @brief static function to send character to LCD controller
 * 
 * @param lcd the lcd object 
 * @param data 
 */
static void _SendChar(LCD_t *lcd,uint8_t data) 
{   
    /* Set to control register  */ 
    DIO_setPinValue(lcd->RS,HIGH);
    /* Set to write Mode */ 
    DIO_setPinValue(lcd->RW,LOW);

    if(lcd->is8Bit)
    {
        /* send the whole command */ 
        _write8bit(lcd,data) ;
    }
    else
    {
        /* send the second 4 bits */
        _write4bit(lcd,data>>4) ; 
        /* send the first 8 bits */ 
        _write4bit(lcd,data) ; 
    }
	
}

void LCD_SendChar(LCD_t *lcd ,uint8_t data)
{
	_SendChar(lcd,data);
	/* make 16 x2 boundary for the cursor */
	lcd->cur_pos++ ;
	switch(lcd->cur_pos)
	{
		/* end of the first line */
		case 16:
			LCD_Goto(lcd,0,1) ;
			break ;
		
		/* end of the second line */
		case 32:
			LCD_Goto(lcd,0,0) ;
			lcd->cur_pos = 0 ;
			break ;
	}
}

void LCD_Write(LCD_t *lcd,const char * string)
{
	/* transversing through the array of character and writing char by char */
	while (*(string)!='\0')
	{
		LCD_SendChar(lcd,*(string++)) ;
	}

}

void LCD_WriteNumber(LCD_t *lcd,uint32_t n)
{
	if (n==0)
	{
		LCD_SendChar(lcd,'0') ; 
	}
	else
	{
		/* buffer to hold the number after separation */
		uint8_t buff[10] ;
		/* counter */
		uint8_t i = 0 ;
		/*  transverse and separate the number till the number ends or the buffer gets full */
		while ((n!=0)&&(i<10))
		{
			buff[i++] = n%10 ;
			n/=10 ;
		}
	
		/* sending each number in reverse */
		while(i>0)
		{
			i--;
			LCD_SendChar(lcd,'0'+buff[i]) ;
		}
	}
}

void LCD_Goto(LCD_t *lcd,uint8_t x ,uint8_t y)
{
    lcd->cur_pos= x+y*16 ; /* set the new cursor pos */

	switch (y)
	{
		case 0 :LCD_SendCommand(lcd,FirstRow+x) ;break;

		case 1 :LCD_SendCommand(lcd,SecondRow+x) ;break;
		
        default:
		break;
	}
}

void LCD_CreateChar(LCD_t *lcd ,uint8_t pos ,uint8_t chararr[] ) 
{
    /* limit the pos to be only 8 positions */  
    pos &= 0x7 ; 
    
    /* switch form DDRAM -> CGRAM in the specified postion */
    LCD_SendCommand(lcd,SetCGRAM | pos<<3) ; 
    
    /* write the new char byte by byte (max 8 bytes) */
    for(uint8_t i=0 ; i<8 ; i++)
    {
        _SendChar(lcd,chararr[i]) ; 
    }

    /* go to the first position in the lcd */
	LCD_Goto(lcd,0,0) ;
}

