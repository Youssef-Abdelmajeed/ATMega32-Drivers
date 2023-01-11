/**
 * @file TimerOne_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Timer one registers file 
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TIMER_1_REG_H_ 
#define TIMER_1_H_REG_ 

/* Timer/Counter1 Control Register A */
#define TCCR1A (*(volatile uint8_t *)(0x4F))
/* Waveform Generation Mode 0 */
#define TCCR1A_WGM10                0
/* Waveform Generation Mode 1 */
#define TCCR1A_WGM11                1
/* Force Output Compare for Channel B */
#define TCCR1A_FOC1B                2
/* Force Output Compare for Channel A */
#define TCCR1A_FOC1A                3
/* Compare Output Mode for Channel B0 */
#define TCCR1A_COM1B0               4
/* Compare Output Mode for Channel B1 */
#define TCCR1A_COM1B1               5
/* Compare Output Mode for Channel A0 */
#define TCCR1A_COM1A0               6
/* Compare Output Mode for Channel A1 */
#define TCCR1A_COM1A1               7

/* Timer/Counter1 Control Register B */
#define TCCR1B (*(volatile uint8_t *)(0x4E))
/* Clock Select 0 */
#define TCCR1B_CS10                 0
/* Clock Select 1 */
#define TCCR1B_CS11                 1
/* Clock Select 2 */
#define TCCR1B_CS12                 2
/* Waveform Generation Mode 2 */
#define TCCR1B_WGM12                3
/* Waveform Generation Mode 3 */
#define TCCR1B_WGM13                4
/* Input Capture Edge Select */
#define TCCR1B_ICES1                6
/* Input Capture Noise Canceler */
#define TCCR1B_ICNC1                7

/* Timer/Counter1 Register */ 
#define TCNT1  (*(volatile uint16_t *)(0x4C))
/* Timer/Counter1 Register High byte */ 
#define TCNT1H (*(volatile uint8_t *)(0x4D))
/* Timer/Counter1 Register Low byte */ 
#define TCNT1L (*(volatile uint8_t *)(0x4C))

/* Output Compare Register 1 A */
#define OCR1A  (*(volatile uint16_t *)(0x4A))
/*Output Compare Register 1 A High byte */
#define OCR1AH (*(volatile uint8_t *)(0x4B))
/*Output Compare Register 1 A Low byte */
#define OCR1AL (*(volatile uint8_t *)(0x4A))

/* Output Compare Register 1 B */
#define OCR1B  (*(volatile uint16_t *)(0x48))
/* Output Compare Register 1 B High byte */
#define OCR1BH (*(volatile uint8_t *)(0x49))
/* Output Compare Register 1 B Low byte */
#define OCR1BL (*(volatile uint8_t *)(0x48))


    /* Shared Registers */

/* Timer/Counter Interrupt Mask Register */
#define TIMSK1           (*(volatile uint8_t *)(0x59)) 
/* Timer/Counter1, Overflow Interrupt Enable */
#define TIMSK1_TOIE1                2
/* Timer/Counter1, Output Compare B Match Interrupt Enable */
#define TIMSK1_OCIE1B               3
/* Timer/Counter1, Output Compare A Match Interrupt Enable */
#define TIMSK1_OCIE1A               4
/* Timer/Counter1, Input Capture Interrupt Enable */
#define TIMSK1_TICIE1               5

/* Timer/Counter Interrupt Flag Register – TIFR */ 
#define TIFR1            (*(volatile uint8_t *)(0x58)) 
/* Timer/Counter1, Overflow Flag */
#define TIFR1_TOV1                  2
/* Timer/Counter1, Output Compare B Match Flag */
#define TIFR1_OCF1B                 3
/* Timer/Counter1, Output Compare A Match Flag */
#define TIFR1_OCF1A                 4
/* Timer/Counter1, Input Capture Flag */
#define TIFR1_ICF1                  5

#endif /* TIMER_1_REG_H_ */