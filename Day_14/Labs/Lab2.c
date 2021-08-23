/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/STD_TYPES.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/GIE_interface.h"
#include "MCAL/EXTI_interface.h"
#include "util/delay.h"

void main()
{
	GIE_VidEnable();
	EXTI1_VidInit();

	DIO_VidSetPinMode(Port_A, Pin_3, output);

	/*Set interrupt pin as input */
	DIO_VidSetPinMode(Port_D, Pin_3, input);
	DIO_VidSetPinValue(Port_D, Pin_3, high);

	DIO_VidSetPortMode(Port_A, Port_output);

	while (1)
	{
		for (s8 i = 7; i >= 0; i--)
		{
			DIO_VidSetPinValue(Port_A, i, high); //Setting pin #i on PORTA to high
			_delay_ms(250);						 //Delay for 250 milliseconds
			DIO_VidSetPinValue(Port_A, i, low);	 //Setting pin #i on PORTA to low
		}
	}
}

void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	DIO_VidSetPortValue(Port_A, Port_low);
	for (u8 i = 0; i <= 3; i++)
	{
		DIO_VidSetPinValue(Port_A, i, high);	 //Setting pin #i on PORTA to high
		DIO_VidSetPinValue(Port_A, 7 - i, high); //Setting pin #7 - i on PORTA to high
		_delay_ms(300);							 //Delay for 250 milliseconds
		DIO_VidSetPinValue(Port_A, i, low);		 //Setting pin #i on PORTA to low
		DIO_VidSetPinValue(Port_A, 7 - i, low);	 //Setting pin #7 - i on PORTA to low}
	}
}