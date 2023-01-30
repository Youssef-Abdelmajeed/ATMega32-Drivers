/**
 * @file RTOS_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief RTOS interface file 
 * @version 0.1
 * @date 2023-01-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef RTOS_INT_H_ 
#define RTOS_INT_H_ 

/**
 * error states
 */
#define RTOS_OK 			1
#define OCCUPATED 			2
#define SUSPENDED_BEFORE	3
#define RUNNING_BEFORE 		4
#define EMPTY_BEFORE		5

typedef struct Task 
{
    uint8_t  Priority ;
    uint16_t Periodicity  ; 
    void (*taskFunction)(void) ;
    uint16_t firstDelay ;
}ST_Task_t; 

void RTOS_Start(void) ; 

uint8_t RTOS_CreateTask(ST_Task_t  *task) ;

uint8_t RTOS_SuspendTask(ST_Task_t *task) ;

uint8_t RTOS_ResumeTask(ST_Task_t  *task) ;

uint8_t RTOS_DeleteTask(ST_Task_t  *task) ;
#endif /*RTOS_INT_H_*/
