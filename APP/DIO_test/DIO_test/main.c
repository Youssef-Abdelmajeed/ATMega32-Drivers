/**
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief DIO test application 
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#define F_CPU 1000000UL 
#include <util/delay.h>
#include "DIO_INT.h"

int main(void)
{
	DIO_setPinDirection(PA0,OUTPUT) ;
	DIO_setPinDirection(PD0,INPUT_PULLUP) ; 
    _Bool flag = 0 ; 
	while (1) 
    {
		if (flag)
		{
			DIO_setPinValue(PA0,TOGGLE) ;
			_delay_ms(300) ;
		}
		
		/* debouncing */
		if (DIO_getPinValue(PD0)==0)
		{
			_delay_ms(300) ; 
			if (DIO_getPinValue(PD0)==1)
			{
				flag = !flag ;
			}
		}
    }
}

