/**
 * @file GIE_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Global Interrupt Enable Interface file 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GIE_INT_H_ 
#define GIE_INT_H_

#include "LIB/STD_TYPES.h"

/* Global Interrupt Enable */
inline void GIE_Enable(void) ; 

/* Global Interrupt Disable */ 
inline void GIE_Disable(void) ;

#endif /* GIC_REG_H */