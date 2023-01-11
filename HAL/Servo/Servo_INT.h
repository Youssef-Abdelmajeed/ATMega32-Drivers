/**
 * @file Servo_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Servo interface file 
 * @version 0.1
 * @date 2023-01-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */ 


#ifndef SERVO_INT_H_
#define SERVO_INT_H_

/**
 * @brief Initialize Servo(s)
 * 
 */
void Servo_Init(void) ; 
/**
 * @brief move the servo with given angle 
 * 
 * @param pin PD4, PD5 
 * @param angle -90 - 90 
 * @return uint8_t Error state : SERVO_OK , WRONG_PIN , WRONG_ANGLE 
 */
uint8_t Servo_Move(uint8_t pin,int16_t angle); 

#endif /* SERVO_INT_H_ */