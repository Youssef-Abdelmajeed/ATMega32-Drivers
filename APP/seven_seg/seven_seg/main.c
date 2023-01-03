/*
 * main.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Mostafa Rashed
 */


#define F_CPU 1000000UL
#include "STD_Types.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "Keypad_Interface.h"
#include <util/delay.h>

int main(void)
{
	u8 Segmant_arr[9]={0x7,0x66,0x6,0x7f,0x6d,0x5b,0x6f,0x7d,0x4f};
	u8 arr[KPD_u8_KEYS_NUM];
	KPD_void_Init();
	//DIO_u8Set_Pin_Dir(GROUP_B,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8Set_Port_Dir(GROUP_B,255);

	
	while(1)
	{
		
		KPD_void_Get_Status(arr);
		for(u8 i=0;i<(sizeof(arr)-1);i++)
		{
			if (arr[i]==0)
			{
				switch(i)
				{
				case 0:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 1:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 2:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 4:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 5:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 6:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 8:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 9:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				case 10:
					DIO_u8Set_Port_Value(GROUP_B,Segmant_arr[i]);
					break;
				default:
					DIO_u8Set_Port_Value(GROUP_B,DIO_u8_LOW);
					break;
				}
				_delay_ms(1000);
				DIO_u8Set_Port_Value(GROUP_B,0);
			}
			else
			{
				DIO_u8Set_Port_Value(GROUP_B,DIO_u8_LOW);
			}
		}
		/*if(arr[0]==0)
		{
			DIO_u8Set_Pin_Value(GROUP_B,DIO_u8_PIN_0,DIO_u8_HIGH);

		}
		else
		{
			DIO_u8Set_Pin_Value(GROUP_B,DIO_u8_PIN_0,DIO_u8_LOW);
		}*/

	}
	return 0;
}
