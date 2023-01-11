/**
 * @file Servo_private.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Servo private file 
 * @version 0.1
 * @date 2023-01-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */ 

#ifndef SERVO_PRIVATE_H_
#define SERVO_PRIVATE_H_

/*Timer1 Channel B*/
#define  _USE_PD4_			0

/*Timer1 Channel A*/
#define  _USE_PD5_			1 

/*Min - MAX Ton */

#define MIN_CONTROL_VALUE_US	1000
#define MAX_CONTROL_VALUE_US	2000

/* Servo Errors */

#define WRONG_PIN			1
#define SERVO_OK			2
#define WRONG_ANGLE			3

#endif /* SERVO_PRIVATE_H_ */