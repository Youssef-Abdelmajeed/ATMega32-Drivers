/**
 * @file TImerOne_PRG.C
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Timer one implementation file 
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "LIB\BIT_MATH.h"
#include "LIB\STD_TYPES.h"
#include "TimerOne_REG.h"
#include "TimerOne_private.h"
#include "TIMERS_INT.h"

inline uint8_t Timer1_SetPrescaler(uint8_t Pmode)
{
    uint8_t ErrorState ; 
    /* checks if the prescaler is wrong */
    if(Pmode<0||Pmode>7) 
    {
        ErrorState =  WrongSelection ; 
    } 
    else 
    {
        /* clear clock selection bits */
        TCCR1B  &= 0xF8 ; 
        /* set prescaler mode */
        TCCR1B  |= Pmode ;  
        ErrorState = TimerOK ; 
    }
    return ErrorState ; 
}
inline uint8_t Timer1_SetWaveMode(uint8_t Wmode)
{
    uint8_t ErrorState ; 
    /* checks if the Wave mode is wrong */
    if(Wmode<0||Wmode>15||Wmode==13) 
    {
        ErrorState =  WrongSelection ; 
    }
    else
    {
        /*  clear wave generation bits in TCCR1A,TCCR1B */
        TCCR1A &= 0xFC ;
        TCCR1B &= 0xE7 ; 
        /*Set wave generation bits in TCCR1A,TCCR1B in the right postion*/
        TCCR1A |= (Wmode&0x03) ;        // Put the LSB bits of Wmode in TCCR1A Bit 1:0
        TCCR1B |= ((Wmode<<1)&(0x18)) ; // Put the MSB bits of Wmode in TCCR1B Bit 3:4 
        ErrorState = TimerOK ; 
    }
    return ErrorState ;  
}
uint8_t Timer1_init(uint8_t Pmode,uint8_t Wmode) 
{
    uint8_t ErrorState ; 
    if(Timer1_SetPrescaler(Pmode)==TimerOK&&Timer1_SetWaveMode(Wmode)==TimerOK)
    {
        ErrorState = TimerOK ; 
    }
    else
    {
        ErrorState = WrongSelection ; 
    }
    return ErrorState ; 
}