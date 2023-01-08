
#define F_CPU  8000000UL
#include "LIB\BIT_MATH.h"
#include "LIB\STD_TYPES.h"
#include "DIO_INT.h"
#include "GIE_INT.h"
#include "TIMERS_INT.h"

#define USE_TIMER TIMER0 
#define PIN PA0

void do_fake_pwm(void); 

int main(void)
{
    DIO_setPinDirection(PIN,OUTPUT) ; 
	DIO_setPinValue(PIN,HIGH) ; 
	GIE_Enable() ; 
	Timer_Init(USE_TIMER,prescaler8,CTC) ;
	Timer_SetCTC_Callback(USE_TIMER,&do_fake_pwm) ;  
	Timer_SetCTCRegister(USE_TIMER,250) ; 
	while (1) 
    {
		
    }
}

void do_fake_pwm(void)
{
	static uint8_t counter = 0 ; 
	counter++ ; 
	if (counter==2)
	{
		DIO_setPinValue(PIN,LOW) ; 
	}
	else if (counter==10)
	{
		DIO_setPinValue(PIN,HIGH) ;
		counter = 0 ;  
	}
	
}