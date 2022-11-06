/**
 * @file EXTI_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  External Interrupt Implementation file 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "EXTI_INT.h"
#include "EXTI_REG.h"

#define NULL ((void *) 0) 

void (*INT0_callback)(void) = NULL; /* INT0 ISR Callback place holder */
void (*INT1_callback)(void) = NULL; /* INT1 ISR Callback place holder */
void (*INT2_callback)(void) = NULL; /* INT2 ISR Callback place holder */


EN_Errors_t EXTI_SetSenseMode(EN_EXTI_PINS_t pinNum,EN_SenseModes_t mode)
{
        /* sense control for INT0, INT1 (LOW_LEVEL, CHANGE, FALLING, RISING) */
    if(pinNum<INT2)
    {
        /* make sure the two sense bits are cleared  */
        MCUCR &= ~(3<<pinNum*2) ; 
        /* set sense mode to the corresponded sense bits */
        MCUCR |= (mode<<pinNum*2) ;
    }
    else
    {
        /* sense control for INT2 (FALLING, RISING) */
        if(mode>=FALLING)
        {
            /* make sure bit 6 is cleared  */
            MCUCSR &= ~(1<<MCUCSR_ISC2) ; 
            /* set bit 6 if mode is RISING and don't change it else wise */
            MCUCSR |= ((~mode&0x01)<<MCUCSR_ISC2) ;  
        }   
        else 
        {
            return senseModeError ;
        }
    }
    return ok ;
}

void EXTI_SetSIE(EN_EXTI_PINS_t pinNum) 
{
    switch (pinNum)
    {
    case INT0:
        setBit(GICR ,GICR_INT0) ;
        break;
    case INT1:
        setBit(GICR ,GICR_INT1) ;
        break;
    case INT2:
        setBit(GICR ,GICR_INT2) ;
        break;
    default:
        /* Do Nothing */
        break;
    }
}

void EXTI_ClearSIE(EN_EXTI_PINS_t pinNum)
{
    switch (pinNum)
    {
    case INT0:
        clearBit(GICR ,GICR_INT0) ;
        break;
    case INT1:
        clearBit(GICR ,GICR_INT1) ;
        break;
    case INT2:
        clearBit(GICR ,GICR_INT2) ;
        break;
    default:
        /* Do Nothing */
        break;
    }
}

EN_Errors_t EXTI_Setcallback(EN_EXTI_PINS_t pinNum,void(*Callback)(void)) 
{
    if(Callback!=NULL)
    {
        switch (pinNum)
        {
        case INT0:
            INT0_callback= Callback ; 
            break;
        case INT1:
            INT1_callback = Callback ; 
            break;
        case INT2:
            INT2_callback = Callback ; 
            break;
        default:
            /* Do Nothing */
            break;
        }
    }
    else
    {
        return NULLCallback ;
    }
    return ok ;
}

 EN_Errors_t EXTI_InitIntrrupt(EN_EXTI_PINS_t pinNum,EN_SenseModes_t mode ,void(*Callback)(void))
{
    /* set interrupt sense mode */
    if(EXTI_SetSenseMode(pinNum,mode)==ok) 
    {
        /* Set specific Interrupt Enable */
        EXTI_SetSIE(pinNum) ; 

        /* set Interrupt callback */
        if(EXTI_Setcallback(pinNum,Callback)==ok)
        {
            return ok ;
        }
        else
        {
            return NULLCallback ;
        }
    }
    else 
    {
        /* for INT2 avalible sense modes are Falling & rising only  */
        return senseModeError ;
    }

}
/* INT0 ISR */
void __vector_1 (void) __attribute__ ((signal,used)) ; 
void __vector_1(void)
{
    if(INT0_callback!=NULL) 
    {
        INT0_callback() ; 
    }
    else
    {
        /* do nothing */
    }
}

/* INT1 ISR */
void __vector_2 (void) __attribute__ ((signal,used)) ; 
void __vector_2 (void)
{
    if(INT1_callback!=NULL) 
    {
        INT1_callback() ; 
    }
    else
    {
        /* do nothing */
    }
}

/* INT2 ISR */
void __vector_3 (void) __attribute__ ((signal,used)) ; 
void __vector_3 (void)
{
    if(INT2_callback!=NULL) 
    {
        INT2_callback() ; 
    }
    else
    {
        /* do nothing */
    }
}