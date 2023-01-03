/*
 * Keypad_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Mostafa Rashed
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
//
#define KPD_u8_ROWS 4
#define KPD_u8_COLS 4
//
#define DIO_u8_INPUT  0
#define DIO_u8_OUTPUT 1
//
#define KPD_u8_KEYS_NUM  KPD_u8_ROWS*KPD_u8_COLS
//

void KPD_void_Init(void);
//
void KPD_void_Get_Status(u8 *PTR_u8_KPD_Status);

#endif /* KEYPAD_INTERFACE_H_ */
