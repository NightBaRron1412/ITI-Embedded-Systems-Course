/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Amir Shetaia
 */
#include "Lib/Bit_Math.h"
#include "Lib/Std_Types.h"
#include "DIO_interface.h"

void main()
{
    DIO_VidSetPinMode(Port_A, Pin_0, output);
    DIO_VidSetPinValue(Port_A, Pin_0, high);

    while (1)
    {
    }
}
