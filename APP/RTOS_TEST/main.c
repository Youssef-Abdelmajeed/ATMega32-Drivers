#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_INT.h"
#include "RTOS/RTOS_INT.h"

void task1(void) ;
void task2(void) ;
void task3(void) ;

int main(void)
{
	DIO_setPortDirection(PORTA,OUTPUT) ;
	ST_Task_t led1_task  = {0, 1000, &task1}  ;
	ST_Task_t led2_task  = {1, 2000, &task2}  ;
	ST_Task_t led3_task  = {2, 3000, &task3}  ;
	RTOS_CreateTask(&led1_task) ;
	RTOS_CreateTask(&led2_task) ;
	RTOS_CreateTask(&led3_task)	;
	RTOS_Start() ;
	while(1)
	{

	}
}

void task1(void)
{
	DIO_setPinValue(PA0,TOGGLE) ;
}
void task2(void)
{
	DIO_setPinValue(PA1,TOGGLE) ;
}
void task3(void)
{
	DIO_setPinValue(PA2,TOGGLE) ;
}

