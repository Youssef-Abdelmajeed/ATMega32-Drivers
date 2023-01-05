/**
 * @file EXTI_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  External Interrupt interface file 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _EXTI_INT_H_
#define _EXTI_INT_H_


/* corresponded Pins to Interrupts numbers */
#define INT0_PIN PD2 
#define INT1_PIN PD3 
#define INT2_PIN PB2 

/*External Interrupt pins */
typedef enum EN_EXTI_PINS 
{
    INT0, INT1, INT2 
} EN_EXTI_PINS_t  ;

/*External Interrupt Sense modes */
typedef enum EN_SenseModes
{
    LOW_LEVEL, CHANGE, FALLING, RISING
}EN_SenseModes_t ; 

/* errors */
typedef enum EN_Errors 
{
    ok, senseModeError , NULLCallback 
} EN_Errors_t; 

/**
 * @brief Set Interrupt Sense mode  
 * 
 * @param pinNum  INT0, INT1, INT2 
 * @param mode LOW_LEVEL, CHANGE, FALLING, RISING
 * @return EN_Errors_t 
 */
EN_Errors_t EXTI_SetSenseMode(EN_EXTI_PINS_t pinNum,EN_SenseModes_t mode); 

/**
 * @brief enable specific Interrupts 
 * 
 * @param pinNum INT0, INT1, INT2
 */
void EXTI_SetSIE(EN_EXTI_PINS_t pinNum) ;  

/**
 * @brief disable specific Interrupts 
 * 
 * @param pinNum INT0, INT1, INT2
 */
void EXTI_ClearSIE(EN_EXTI_PINS_t pinNum) ;  

/**
 * @brief set callback function to be called in the corresponded ISR  
 * 
 * @param pinNum INT0, INT1, INT2
 * @param Callback  address of the callback function 
 * @return EN_Errors_t 
 */
EN_Errors_t EXTI_Setcallback(EN_EXTI_PINS_t pinNum,void(*Callback)(void)) ;

/**
 * @brief Sets an Interrupt on a specific pin with given callback 
 * 
 * @param pinNum INT0, INT1, INT2
 * @param mode LOW_LEVEL, CHANGE, FALLING, RISING
 * @param Callback address of the callback function
 * @return EN_Errors_t 
 */
EN_Errors_t EXTI_InitIntrrupt(EN_EXTI_PINS_t pinNum,EN_SenseModes_t mode ,void(*Callback)(void)) ; 

#endif /* _EXTI_INT_H_ */