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

typedef struct Task 
{
    uint8_t Priority ; 
    uint16_t Periodicity  ; 
    void (*taskFunction)(void) ;
}ST_Task_t; 

void RTOS_Start(void) ; 

void RTOS_CreateTask(ST_Task_t *task) ;

void RTOS_SuspendTask(ST_Task_t *task) ;

void RTOS_ResumeTask(ST_Task_t *task) ;

#endif /*RTOS_INT_H_*/
