
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_INT.h"
#include "LCD_INT.h"

int main(void)
{
    LCD_t lcd_4bit1 = {.RS =PB4,.RW=PB5,.EN=PB6,.dataPins={NC,NC,NC,NC,PB0,PB1,PB2,PB3}};   
	LCD_Init(&lcd_4bit1) ; 	 
	LCD_Write(&lcd_4bit1,"HELLO WORLD") ;
	while (1) 
    {
		
    }
}

