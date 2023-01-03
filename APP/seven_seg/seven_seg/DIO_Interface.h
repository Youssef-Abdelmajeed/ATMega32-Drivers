/*
 * DIO_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Mostafa Rashed
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


//
#define GROUP_A 0   //0b00000000
#define GROUP_B 1   //0b00000001
#define GROUP_C 2   //0b00000010
#define GROUP_D 3   //0b00000011
//
#define DIO_u8_PIN_0 0
#define DIO_u8_PIN_1 1
#define DIO_u8_PIN_2 2
#define DIO_u8_PIN_3 3
#define DIO_u8_PIN_4 4
#define DIO_u8_PIN_5 5
#define DIO_u8_PIN_6 6
#define DIO_u8_PIN_7 7
//
#define DIO_u8_HIGH  1
#define DIO_u8_LOW   0
//
#define DIO_u8_ERR_INIT_VAL 0
#define DIO_u8_PORT_ID_ERR  1
#define DIO_u8_PIN_ID_ERR   2
//
#define DIO_u8_PIN_VAL_ERR  3
//
#define DIO_u8_PIN_Dir_ERR  4
//
#define DIO_u8_PORT_VAL_ERR 5
//
#define DIO_u8_PORT_DIR_ERR 6
//
//void DIO_u8Set_Pin_Value(void);
u8 DIO_u8Set_Pin_Value (u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Value);
//
u8 DIO_u8Set_Pin_Dir (u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Dir);
//
u8 DIO_u8Set_Port_Value (u8 Copy_u8_Port_ID,u8 Copy_u8_Port_Val);
//
u8 DIO_u8Set_Port_Dir (u8 Copy_u8_Port_ID,u8 Copy_u8_Port_Dir);
//
u8 DIO_u8Get_Pin_Value (u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 *PTR_u8_Value);
//
u8 DIO_u8Get_Port_Value (u8 Copy_u8_Port_ID,u8 *PTR_u8_Value);
//


#endif /* DIO_INTERFACE_H_ */
