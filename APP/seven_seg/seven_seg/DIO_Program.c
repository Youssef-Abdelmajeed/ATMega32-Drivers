/*
 * DIO.C
 *
 *  Created on: Nov 20, 2022
 *      Author: Mostafa Rashed
 */
#include "BIT_CALC.h"
#include "STD_Types.h"
//#include ""
#include "DIO_Private.h"
#include "DIO_Interface.h"

u8 DIO_u8Set_Pin_Value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Value)
{
	u8 Loc_u8Error_State=DIO_u8_ERR_INIT_VAL;
	if ((Copy_u8_Port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=MAX_u8_PORT_ID))
	{
		if((Copy_u8_Pin_ID>=MIN_u8_PIN_ID)&&(Copy_u8_Pin_ID<=MAX_u8_PIN_ID))
		{
			if((Copy_u8_Value==MIN_u8_PIN_VAL)||(Copy_u8_Value==MAX_u8_PIN_VAL))
			{
				switch(Copy_u8_Port_ID)
					{
					case GROUP_A:
						Assign_Bit(DIO_u8_PORTA,Copy_u8_Pin_ID,Copy_u8_Value);
						break;
					case GROUP_B:
						Assign_Bit(DIO_u8_PORTB,Copy_u8_Pin_ID,Copy_u8_Value);
						break;
					case GROUP_C:
						Assign_Bit(DIO_u8_PORTC,Copy_u8_Pin_ID,Copy_u8_Value);
						break;
					case GROUP_D:
						Assign_Bit(DIO_u8_PORTD,Copy_u8_Pin_ID,Copy_u8_Value);
						break;
					default:

						break;
					}
			}
			else
			{
				Loc_u8Error_State=DIO_u8_PIN_VAL_ERR;
			}
		}
		else
		{
			Loc_u8Error_State=DIO_u8_PIN_ID_ERR;
		}
	}
	else
	{
		Loc_u8Error_State=DIO_u8_PORT_ID_ERR;
	}
	return Loc_u8Error_State;
}


u8 DIO_u8Set_Pin_Dir(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Dir)
{
	u8 Loc_u8Error_State=DIO_u8_ERR_INIT_VAL;
	if ((Copy_u8_Port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=MAX_u8_PORT_ID))
	{
		if((Copy_u8_Pin_ID>=MIN_u8_PIN_ID)&&(Copy_u8_Pin_ID<=MAX_u8_PIN_ID))
		{
			if((Copy_u8_Dir==MIN_u8_PIN_Dir)||(Copy_u8_Dir==MAX_u8_PIN_Dir))
			{
				switch(Copy_u8_Port_ID)
					{
					case GROUP_A:
						Assign_Bit(DIO_u8_DDRA,Copy_u8_Pin_ID,Copy_u8_Dir);
						break;
					case GROUP_B:
						Assign_Bit(DIO_u8_DDRB,Copy_u8_Pin_ID,Copy_u8_Dir);
						break;
					case GROUP_C:
						Assign_Bit(DIO_u8_DDRC,Copy_u8_Pin_ID,Copy_u8_Dir);
						break;
					case GROUP_D:
						Assign_Bit(DIO_u8_DDRD,Copy_u8_Pin_ID,Copy_u8_Dir);
						break;
					default:

						break;
					}
			}
			else
			{
				Loc_u8Error_State=DIO_u8_PIN_Dir_ERR;
			}
		}
		else
		{
			Loc_u8Error_State=DIO_u8_PIN_ID_ERR;
		}
	}
	else
	{
		Loc_u8Error_State=DIO_u8_PORT_ID_ERR;
	}
	return Loc_u8Error_State;
}


u8 DIO_u8Set_Port_Value(u8 Copy_u8_Port_ID,u8 Copy_u8_Port_Val)
{
			switch(Copy_u8_Port_ID)
				{
				case GROUP_A:
					DIO_u8_PORTA = Copy_u8_Port_Val;
					break;
				case GROUP_B:
					DIO_u8_PORTB = Copy_u8_Port_Val;
					break;
				case GROUP_C:
					DIO_u8_PORTC = Copy_u8_Port_Val;
					break;
				case GROUP_D:
					DIO_u8_PORTD = Copy_u8_Port_Val;
					break;
				default:
					break;
				}

	return 0 ; 
}


u8 DIO_u8Set_Port_Dir(u8 Copy_u8_Port_ID,u8 Copy_u8_Port_Dir)
{
	
			switch(Copy_u8_Port_ID)
				{
				case GROUP_A:
					DIO_u8_DDRA = Copy_u8_Port_Dir;
					break;
				case GROUP_B:
					DIO_u8_DDRB = Copy_u8_Port_Dir;
					break;
				case GROUP_C:
					DIO_u8_DDRC = Copy_u8_Port_Dir;
					break;
				case GROUP_D:
					DIO_u8_DDRD = Copy_u8_Port_Dir;
					break;
				default:

					break;
				}
		return  0 ;
}


u8 DIO_u8Get_Pin_Value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 *PTR_u8_Value)
{
	u8 Loc_u8Error_State=DIO_u8_ERR_INIT_VAL;
	if ((Copy_u8_Port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=MAX_u8_PORT_ID))
	{
		if((Copy_u8_Pin_ID>=MIN_u8_PIN_ID)&&(Copy_u8_Pin_ID<=MAX_u8_PIN_ID))
		{
			switch(Copy_u8_Port_ID)
				{
				case GROUP_A:
					*PTR_u8_Value = Get_Bit (DIO_u8_PINA,Copy_u8_Pin_ID);
					break;
				case GROUP_B:
					*PTR_u8_Value = Get_Bit (DIO_u8_PINA,Copy_u8_Pin_ID);
					break;
				case GROUP_C:
					*PTR_u8_Value = Get_Bit (DIO_u8_PINA,Copy_u8_Pin_ID);
					break;
				case GROUP_D:
					*PTR_u8_Value = Get_Bit (DIO_u8_PINA,Copy_u8_Pin_ID);
					break;
				default:

					break;
				}
		}
		else
		{
			Loc_u8Error_State=DIO_u8_PIN_ID_ERR;
		}
	}
	else
	{
		Loc_u8Error_State=DIO_u8_PORT_ID_ERR;
	}
	return Loc_u8Error_State;
}


u8 DIO_u8Get_Port_Value(u8 Copy_u8_Port_ID,u8 *PTR_u8_Value)
{
	u8 Loc_u8Error_State=DIO_u8_ERR_INIT_VAL;
	if ((Copy_u8_Port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=MAX_u8_PORT_ID))
	{
		switch(Copy_u8_Port_ID)
			{
			case GROUP_A:
				*PTR_u8_Value = DIO_u8_PINA;
				break;
			case GROUP_B:
				*PTR_u8_Value = DIO_u8_PINB;
				break;
			case GROUP_C:
				*PTR_u8_Value = DIO_u8_PINC;
				break;
			case GROUP_D:
				*PTR_u8_Value = DIO_u8_PIND;
				break;
			default:
				break;
			}
	}
	else
	{
		Loc_u8Error_State=DIO_u8_PORT_ID_ERR;
	}
	return Loc_u8Error_State;
}
