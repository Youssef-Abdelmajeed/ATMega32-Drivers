/*
 * Keypad_Program.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Mostafa Rashed
 */

#include "BIT_CALC.h"
#include "STD_Types.h"
#include "DIO_Interface.h"
#include "Keypad_Private.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include <util/delay.h>
//
u8 KPD_Au8_Rows_Pins[KPD_u8_ROWS]={KPD_Rows_0_PIN,KPD_Rows_1_PIN,KPD_Rows_2_PIN,KPD_Rows_3_PIN,};
u8 KPD_Au8_Cols_Pins[KPD_u8_COLS]={KPD_COL_0_PIN,KPD_COL_1_PIN,KPD_COL_2_PIN,KPD_COL_3_PIN,};
//
void KPD_void_Init(void)
{
	u8 LOC_u8Col_Index;
	u8 LOC_u8Row_Index;
	for(LOC_u8Col_Index =0;LOC_u8Col_Index < KPD_u8_COLS ; LOC_u8Col_Index++)
	{
		DIO_u8Set_Pin_Dir(KPD_u8_COLS_PORT,KPD_Au8_Cols_Pins[LOC_u8Col_Index],DIO_u8_OUTPUT);
		DIO_u8Set_Pin_Dir(KPD_u8_COLS_PORT,KPD_Au8_Cols_Pins[LOC_u8Col_Index],DIO_u8_HIGH);
	}
	for(LOC_u8Row_Index =0;LOC_u8Row_Index < KPD_u8_ROWS ; LOC_u8Row_Index++)
	{
		DIO_u8Set_Pin_Dir(KPD_u8_ROWS_PORT,KPD_Au8_Rows_Pins[LOC_u8Row_Index],DIO_u8_INPUT);
		DIO_u8Set_Pin_Value(KPD_u8_ROWS_PORT,KPD_Au8_Rows_Pins[LOC_u8Row_Index],DIO_u8_HIGH);
	}
}
//
void KPD_void_Get_Status(u8 *PTR_u8_KPD_Status)
{
	u8 LOC_u8Key_Num;
	u8 LOC_u8Col_Index;
	u8 LOC_u8Row_Index;
	for(LOC_u8Col_Index =0;LOC_u8Col_Index < KPD_u8_COLS ; LOC_u8Col_Index++)
	{
		DIO_u8Set_Pin_Value(KPD_u8_COLS_PORT , KPD_Au8_Cols_Pins[LOC_u8Col_Index],DIO_u8_LOW);
		for(LOC_u8Row_Index =0;LOC_u8Row_Index < KPD_u8_ROWS ; LOC_u8Row_Index++)
		{
			LOC_u8Key_Num=LOC_u8Col_Index + (LOC_u8Row_Index*4);// Dependent :  0  1  2  3
																 //				4  5  6  7
																 //				8  9  10 11
																 //				12 13 14 15
			DIO_u8Get_Pin_Value(KPD_u8_ROWS_PORT , KPD_Au8_Rows_Pins[LOC_u8Row_Index],&PTR_u8_KPD_Status[LOC_u8Key_Num]);
		}
		DIO_u8Set_Pin_Value(KPD_u8_ROWS_PORT , KPD_Au8_Cols_Pins[LOC_u8Col_Index],DIO_u8_HIGH);
	}
}


