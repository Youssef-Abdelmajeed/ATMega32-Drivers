/**
 * @file BIT_MATH.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Bit operation (set, clear, get, toggle)
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BIT_MATH_H_ 
#define BIT_MATH_H_ 

/*seting a bit high at a specified position */
#define setBit(VAR,BITNO)       ((VAR) |= (0x01 << (BITNO)))

/*seting a bit low at a specified position */
#define clearBit(VAR,BITNO)     ((VAR) &= ~(0x01 << (BITNO)))

/*geting a bit at a specified position */
#define getBit(VAR,BITNO)       ((VAR) >> (BITNO) & (0x01))

/*toggle a bit at a specified position */
#define toggleBit(VAR,BITNO)    ((VAR) ^= (0x01 << (BITNO)))

#endif /* BIT_MATH_H_ */