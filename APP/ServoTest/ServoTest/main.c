#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_INT.h"
#include "MCAL/TimerOne/TimerOne_INT.h"
#include "HAL/Servo/Servo_INT.h"

int main(void)
{
	Servo_Init() ; 
	DIO_setPinDirection(PA0,OUTPUT) ; 
    while (1) 
    {
		Servo_Move(PD5,90) ;

    }
}

