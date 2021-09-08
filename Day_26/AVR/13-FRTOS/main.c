/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "Lib/Bit_Math.h"
#include "MCAL/DIO_interface.h"
#include "F-RTOS/FreeRTOS.h"
#include "F-RTOS/task.h"
#include <util/delay.h>

void Task1(void *pv);

void main()
{

	DIO_VidSetPinMode(Port_A, Pin_0, output);

	xTaskCreate(Task1, NULL, 100, NULL, 0, NULL);
	vTaskStartScheduler();

	while (1)
	{
	}
}

void Task1(void *pv)
{

	static u8 local_u8state = 0;
	while (1)
	{
		local_u8state = !local_u8state;
		DIO_VidSetPinValue(Port_A, Pin_0, local_u8state);
		_delay_ms(1000);
	}
}
