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
	EXTI0_VidInit();
	EXTI1_VidInit();

	DIO_VidSetPinMode(Port_A, Pin_2, output);
	DIO_VidSetPinMode(Port_A, Pin_3, output);

	/*Set interrupt pin as input */
	DIO_VidSetPinMode(Port_D, Pin_2, input);
	DIO_VidSetPinValue(Port_D, Pin_2, high);
	
	DIO_VidSetPinMode(Port_D, Pin_3, input);
	DIO_VidSetPinValue(Port_D, Pin_3, high);

	while (1)
	{

		/*Infinity loop*/
	}
}

void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	DIO_VidSetPinValue(Port_A, Pin_2, high);
	_delay_ms(1000);
	DIO_VidSetPinValue(Port_A, Pin_2, low);
}

void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	DIO_VidSetPinValue(Port_A, Pin_3, high);
	_delay_ms(1000);
	DIO_VidSetPinValue(Port_A, Pin_3, low);
}