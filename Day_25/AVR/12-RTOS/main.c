/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "RTOS_interface.h"
#include "MCAL/DIO_interface.h"

void Task1();
void Task2();
void Task3();

void main()
{

    DIO_VidSetPinMode(Port_B, Pin_0, output);
    DIO_VidSetPinMode(Port_B, Pin_1, output);
    DIO_VidSetPinMode(Port_B, Pin_2, output);

    RTOS_VidCreateTask(0, 200, Task1);
    RTOS_VidCreateTask(1, 400, Task2);
    RTOS_VidCreateTask(2, 800, Task3);

    RTOS_VidStart();

    while (1)
    {
        RTOS_VidDispatcher();
    }
}

void Task1(void)
{
    static u8 state = 0;
    state = !state;
    DIO_VidSetPinValue(Port_B, Pin_0, state);
}

void Task2(void)
{
    static u8 state = 0;
    state = !state;
    DIO_VidSetPinValue(Port_B, Pin_1, state);
}

void Task3(void)
{
    static u8 state = 0;
    state = !state;
    DIO_VidSetPinValue(Port_B, Pin_2, state);
}
