/**
 * @file GIE_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Global Interrupt Enable Registers file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GIE_REG_H_ 
#define GIE_REG_H_

/* Special Register */
#define SREG            (*(uint8_t *)(0x5F))  /* To Do ( sepreate Global Interrupt Enable drive ) */
#define SREG_I          7  /* Global Interrupt Enable */

#endif /* GIC_REG_H */