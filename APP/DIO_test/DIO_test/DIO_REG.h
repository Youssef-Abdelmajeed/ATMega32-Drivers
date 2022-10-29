/**
 * @file DIO_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief DIO registers file 
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIO_REG_H_ 
#define DIO_REG_H_

    /* PORT Register A*/
#define PORTA_REG   ((volatile uint8_t *) (0x3B))
    /* Data Direction Register A */
#define DDRA_REG    ((volatile uint8_t *) (0x3A))
    /* Port INput Register A */
#define PINA_REG    ((volatile uint8_t *) (0x39))


    /* PORT Register B*/
#define PORTB_REG   ((volatile uint8_t *) (0x38))
    /* Data Direction Register B */
#define DDRB_REG    ((volatile uint8_t *) (0x37))
    /* Port INput Register B */
#define PINB_REG    ((volatile uint8_t *) (0x36))


    /* PORT Register C*/
#define PORTC_REG   ((volatile uint8_t *) (0x35))
    /* Data Direction Register C */
#define DDRC_REG    ((volatile uint8_t *) (0x34))
    /* Port INput Register C */
#define PINC_REG    ((volatile uint8_t *) (0x33))


    /* PORT Register D*/
#define PORTD_REG   ((volatile uint8_t *) (0x32))
    /* Data Direction Register D */
#define DDRD_REG    ((volatile uint8_t *) (0x31))
    /* Port INput Register D */
#define PIND_REG    ((volatile uint8_t *) (0x30))


#endif /* DIO_REG_H_ */