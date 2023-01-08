/**
 * @file GIE_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Global Interrupt Implementation file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "GIE_INT.h"
#include "GIE_REG.h"


inline void GIE_Enable(void)  {SREG |=  (1<<SREG_I) ;}

inline void GIE_Disable(void) {SREG &= ~(1<<SREG_I) ;}