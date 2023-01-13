#define F_CPU 8000000UL 
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_INT.h"
#include "MCAL/TimerOne/TimerOne_INT.h"
#include "HAL/Servo/Servo_INT.h"
#include <util/delay.h>
#define DELAY_TIME 50
int main(void)
{
	Servo_Init() ; 
	DIO_setPinDirection(PA0,OUTPUT) ; 
    while (1) 
    {
		int i  ; 
		for(i = -90 ; i<=90 ; i++)
		{
			Servo_Move(PD5,i) ;
			_delay_ms(DELAY_TIME) ; 
		}
		_delay_ms(DELAY_TIME+50) ;
		for(i = 90 ; i>=-90 ; i--)
		{
			Servo_Move(PD5,i) ;
			_delay_ms(DELAY_TIME) ;
		}
		_delay_ms(DELAY_TIME+50) ;


    }
}

