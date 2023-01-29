/**
 * @file RTOS_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief RTOS Implementation file 
 * @version 0.1
 * @date 2023-01-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../GIE/GIE_INT.h"
#include "../TIMERS/TIMERS_INT.h"
#include "RTOS_CONFIG.h"
#include "RTOS_Private.h"
#include "RTOS_INT.h"

#define NULL ((void*)0x00)

/*place holder for all RTOS System Tasks*/
ST_Task_t SystemsTasks[TASK_NUM] = {{0}} ;

/*place holder for all RTOS Suspended System Tasks*/
uint8_t SuspendedTasks[TASK_NUM] ={0} ;

void RTOS_Start(void) 
{
	/*set the Timer CTC Mode callback to the Scheduler function*/
	Timer_SetCTC_Callback(TIMER_USED,&Scheduler) ;
	/*Global Interrupt Enable*/
	GIE_Enable() ;
	/*Set the Selected timer with a Prescaler and use CTC Mode*/
	Timer_Init(TIMER_USED,prescaler64,CTC) ;
	/*Set output match compare value*/
	Timer_SetCTCRegister(TIMER_USED,125) ;
} 
void RTOS_CreateTask(ST_Task_t * task) 
{
	SystemsTasks[task->Priority] = *task ;
}
void RTOS_SuspendTask(ST_Task_t * task)
{
	SuspendedTasks[task->Priority] = 1 ;
}

void RTOS_ResumeTask(ST_Task_t *task)
{
	SuspendedTasks[task->Priority] = 0 ;
}
void Scheduler(void)
{
	static uint32_t tickCounter= 0 ;
	tickCounter++ ;
	uint16_t TaskCounter ;
	for(TaskCounter=0 ; TaskCounter<TASK_NUM;TaskCounter++)
	{
		/*check if the task is suspended*/
		if(SuspendedTasks[TaskCounter]!=1)
		{
			/*if it time for the task*/
			if( tickCounter % (SystemsTasks[TaskCounter].Periodicity)==0)
			{

				if(SystemsTasks[TaskCounter].taskFunction!=NULL)
				{
					/*run task*/
					SystemsTasks[TaskCounter].taskFunction() ;
				}
				else
				{
					/*do nothing*/
				}
			}
		}
		else
		{
			/*the task is suspended do nothing*/
		}

	}

}
