/**
 * @file TIMERS_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  TIMERS [Timer0 ,Timer2] Registers file 
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TIMERS_REG_H_
#define TIMERS_REG_H_

    /* TIMER0 Registers 8 bit*/

/* Timer/Counter Control Register */
#define TCCR0           (*(volatile uint8_t *)(0x53)) 
#define TCCR0_CS00      0 /* prescaler select */
#define TCCR0_CS01      1 /* prescaler select */
#define TCCR0_CS02      2 /* prescaler select */
#define TCCR0_WGM01     3 /* wave genration select */
#define TCCR0_COM00     4 /* Compare match output mode select */
#define TCCR0_COM01     5 /* Compare match output mode select */
#define TCCR0_WGM00     6 /* wave genration select */

/* Timer/Counter Register */
#define TCNT0           (*(volatile uint8_t *)(0x52)) /* NORMAL Mode Register */

/* Output Compare Register */ 
#define OCR0            (*(volatile uint8_t *)(0x5C))  /* Compare match Register */

    
    /* TIMER2 Registers 8 bit*/

/* Timer/Counter Control Register */
#define TCCR2           (*(volatile uint8_t *)(0x45)) 
#define TCCR2_CS00      0 /* prescaler select */
#define TCCR2_CS01      1 /* prescaler select */
#define TCCR2_CS02      2 /* prescaler select */
#define TCCR2_WGM01     3 /* wave genration select */
#define TCCR2_COM00     4 /* Compare match output mode select */
#define TCCR2_COM01     5 /* Compare match output mode select */
#define TCCR2_WGM00     6 /* wave genration select */

/* Timer/Counter Register */
#define TCNT2           (*(volatile uint8_t *)(0x44)) /* NORMAL Mode Register */

/* Output Compare Register */ 
#define OCR2            (*(volatile uint8_t *)(0x43))  /* Compare match Register */

    /* Shared Registers */

/* Timer/Counter Interrupt Mask Register */
#define TIMSK           (*(volatile uint8_t *)(0x59)) 
#define TIMSK_TOIE0     0  /* Overflow Interrupt Enable 0 */
#define TIMSK_OCIE0     1  /* Output Compare Match Interrupt Enable 0*/

#define TIMSK_TOIE2     6  /* Overflow Interrupt Enable 2 */
#define TIMSK_OCIE2     7  /* Output Compare Match Interrupt Enable 2*/

/* Timer/Counter Interrupt Flag Register – TIFR */ 
#define TIFR            (*(volatile uint8_t *)(0x58)) 
#define TIFR_TOV0       0 /* Timer/Counter0 Overflow Flag */
#define TIFR_OCF0       1 /* Output Compare Flag 0 */

#define TIFR_TOV2       6 /* Timer/Counter2 Overflow Flag */
#define TIFR_OCF2       7 /* Output Compare Flag 2 */


#endif /* TIMERS_REG_H_ */