/**
 * @file TIMERS_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  TIMERS Registers file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TIMERS_REG_H_
#define TIMERS_REG_H_

/* TIMER0 Registers */

/* Timer0/Counter Control Register */
#define TCCR0           (*(uint8_t *)(0x53)) 
#define TCCR0_CS00      0 /* Prescaler select */
#define TCCR0_CS01      1 /* Prescaler select */
#define TCCR0_CS02      2 /* Prescaler select */
#define TCCR0_WGM01     3 /* wave generation select */
#define TCCR0_COM00     4 /* Compare match output mode select */
#define TCCR0_COM01     5 /* Compare match output mode select */
#define TCCR0_WGM00     6 /* wave generation select */

/* Timer0/Counter Register */
#define TCNT0           (*(uint8_t *)(0x52)) /* NORMAL Mode Register */

/* Output Compare Register */ 
#define OCR0            (*(uint8_t *)(0x5C))  /* Compare match Register */

/* Timer/Counter Interrupt Mask Register */
#define TIMSK           (*(uint8_t *)(0x59)) 
#define TIMSK_TOIE0     0  /* Overflow Interrupt Enable */
#define TIMSK_OCIE0     1  /* Output Compare Match Interrupt Enable */

/* Timer/Counter Interrupt Flag Register – TIFR */ 
#define TIFR            (*(uint8_t *)(0x58)) 
#define TIFR_TOV0       0 /* Timer/Counter0 Overflow Flag */
#define TIFR_OCF0       1 /* Output Compare Flag 0 */



#endif /* TIMERS_REG_H_ */