/**
 * @file EXTI_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  External Interrupt Register file 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _EXTI_REG_H_
#define _EXTI_REG_H_

/* MCU Control Register – Interrupt Sense Control 0 - 1*/
#define MCUCR               (*(uint8_t *)(0x55)) 
#define MCUCR_ISC00         0 
#define MCUCR_ISC01         1
#define MCUCR_ISC10         2 
#define MCUCR_ISC11         3 

/*MCU Control and Status Register – Interrupt Sense Control 2*/
#define  MCUCSR             (*(uint8_t *)(0x54)) 
#define  MCUCSR_ISC2        6 

/*General Interrupt Control Register – External Interrupt Request 0,1,2 Enable*/
#define GICR                (*(uint8_t *)(0x5B)) 
#define GICR_INT0           6 
#define GICR_INT1           7
#define GICR_INT2           5 

/*General Interrupt Flag Register – External Interrupt Flag 0,1,2*/
#define GIFR                (*(uint8_t *)(0x5A)) 
#define GIFR_INTF0           6 
#define GIFR_INTF1           7
#define GIFR_INTF2           5 

#endif /* _EXTI_REG_H_ */