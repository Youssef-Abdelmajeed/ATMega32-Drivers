/**
 * @file Servo_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Servo implementation file 
 * @version 0.1
 * @date 2023-01-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/GIE/GIE_INT.h"
#include "../../MCAL/TimerOne/TimerOne_INT.h"
#include "../../MCAL/TimerOne/TimerOne_private.h"
#include "Servo_INT.h"
#include "Servo_private.h"

void Servo_Init(void) 
{
	/*Set Global Interrupt enable */
	GIE_Enable() ; 
	
	/*if pin PD4 (Timer Channel B) is used to control a servo */
	#if _USE_PD4_ == 1 
	DIO_setPinDirection(PD4,OUTPUT) ; 
	Timer1_SetOutputCompareMode(ChannelB,NonInverting) ;
	#endif /*_USE_PD4_*/
	
	/*if pin PD5 (Timer Channel A) is used to control a servo */
	#if _USE_PD5_ == 1 
	DIO_setPinDirection(PD5,OUTPUT) ;
	Timer1_SetOutputCompareMode(ChannelA,NonInverting) ;
 	#endif /*_USE_PD5_*/
	
	/*set Timer1 input capture Register to 20000 to achieve period of 20ms*/
	Timer1_SetInputCaptureRegister(20000) ;
	 
	/*set timer mode to be fast PWM  and The top is ICR1 Register */
	Timer1_init(Prescaler8,Fast_PWM_ICR) ;

	
}
static int32_t MAP (int32_t x, int32_t min1, int32_t max1, int32_t min2, int32_t max2) {
	return (x - min1) * (max2 - min2) / (max1 - min1) + min2;
}
uint8_t Servo_Move(uint8_t pin,int16_t angle) 
{
	uint8_t ErrorState ; 
	if(angle<-90||angle>90)
	{
		ErrorState =WRONG_ANGLE ;
	}
	else
	{
		/* map the given angle against the compare match value */ 
		uint16_t CompValue = MAP(angle,-90,90,MIN_CONTROL_VALUE_US,MAX_CONTROL_VALUE_US); 

		switch (pin)
		{
		case  PD5:
			Timer1_SetOutputCompareRegisterA(CompValue) ; 
			ErrorState =SERVO_OK ;
			break;
		case PD4:
			Timer1_SetOutputCompareRegisterB(CompValue) ; 
			ErrorState =SERVO_OK ; 
			break;
		default:
			ErrorState = WRONG_PIN ; 
			break;
		}
	}
	return ErrorState ; 
}