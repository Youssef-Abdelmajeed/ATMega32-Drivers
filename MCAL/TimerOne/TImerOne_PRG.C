/**
 * @file TImerOne_PRG.c
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

#define NULL ((void*)0) 

/* place holder for the output compare match A mode callback */
void (*COMPA_Callback)(void) = NULL ; 
/* place holder for the output compare match B mode callback */
void (*COMPB_Callback)(void) = NULL ; 
/* place holder for the normal mode callback */
void (*NormalMode_Callback)(void) = NULL ; 

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
        /* clear wave generation bits in TCCR1A, TCCR1B */
        TCCR1A &= 0xFC ;
        TCCR1B &= 0xE7 ; 
        /* Set wave generation bits in TCCR1A,TCCR1B in the right postion */
        TCCR1A |= (Wmode&0x03) ;        // Put the LSB bits of Wmode in TCCR1A Bit 1:0
        TCCR1B |= ((Wmode<<1)&(0x18)) ; // Put the MSB bits of Wmode in TCCR1B Bit 4:3 
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
uint8_t Timer1_SetOverFlow_Callback(void(*callback)(void))
{
    uint8_t ErrorState ; 
    /* checks for NULL pointer */
    if (callback!=NULL)
    {
        NormalMode_Callback = callback ; 
        ErrorState = TimerOK ; 
    }
    else 
    {
        ErrorState = NULL_POINTER ; 
    }
    return ErrorState ; 
}
uint8_t Timer1_SetOutputCompareA_Callback(void(*callback)(void))
{
    uint8_t ErrorState ; 
    /* checks for NULL pointer */
    if (callback!=NULL)
    {
        COMPA_Callback = callback ; 
        ErrorState = TimerOK ; 
    }
    else 
    {
        ErrorState = NULL_POINTER ; 
    }
    return ErrorState ;
}
uint8_t Timer1_SetOutputCompareB_Callback(void(*callback)(void))
{
    uint8_t ErrorState ; 
    /* checks for NULL pointer */
    if (callback!=NULL)
    {
        COMPB_Callback = callback ; 
        ErrorState = TimerOK ; 
    }
    else 
    {
        ErrorState = NULL_POINTER ; 
    }
    return ErrorState ;
}
inline uint8_t Timer1_SetOverFlowRegister(uint16_t value)
{
    TCNT1 = value ;
    return TimerOK; 
}
inline uint8_t Timer1_SetOutputCompareRegisterA(uint16_t value)
{
    OCR1A = value ; 
    return TimerOK ; 
}
inline uint8_t Timer1_SetOutputCompareRegisterB(uint16_t value)
{
    OCR1B = value ; 
    return TimerOK ; 
}
/* Timer1 COMPA ISR */
void __vector7(void)__attribute__((signal)) ; 
void __vector7(void)
{
    /* checks for NULL pointer */
    if(COMPA_Callback!=NULL)
    {
        COMPA_Callback(); 
    }
}
/* Timer1 COMPB ISR */
void __vector8(void)__attribute__((signal)) ; 
void __vector8(void)
{
    /* checks for NULL pointer */
    if(COMPB_Callback!=NULL)
    {
        COMPB_Callback(); 
    }
}
/* Timer1 overflow ISR */
void __vector9(void)__attribute__((signal)) ; 
void __vector9(void)
{
    /* checks for NULL pointer */
    if(NormalMode_Callback!=NULL)
    {
        NormalMode_Callback(); 
    }
}