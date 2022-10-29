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
#define PORTA   (*(uint8_t *) (0x3B))
    /* Data Direction Register A */
#define DDRA    (*(uint8_t *) (0x3A))
    /* Port INput Register A */
#define PINA    (*(uint8_t *) (0x39))


    /* PORT Register B*/
#define PORTB   (*(uint8_t *) (0x38))
    /* Data Direction Register B */
#define DDRB    (*(uint8_t *) (0x37))
    /* Port INput Register B */
#define PINB    (*(uint8_t *) (0x36))


    /* PORT Register C*/
#define PORTC   (*(uint8_t *) (0x35))
    /* Data Direction Register C */
#define DDRC    (*(uint8_t *) (0x34))
    /* Port INput Register C */
#define PINC    (*(uint8_t *) (0x33))


    /* PORT Register D*/
#define PORTD   (*(uint8_t *) (0x32))
    /* Data Direction Register D */
#define DDRD    (*(uint8_t *) (0x31))
    /* Port INput Register D */
#define PIND    (*(uint8_t *) (0x30))


#endif /* DIO_REG_H_ */