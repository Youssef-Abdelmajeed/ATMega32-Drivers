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
    while (1) 
    {
		DIO_setPinValue(PA0,TOGGLE) ;
		_delay_ms(300) ;
    }
}

