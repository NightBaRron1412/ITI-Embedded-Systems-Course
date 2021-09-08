/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Amir Shetaia
 */
#include "Lib/Std_Types.h"
#include "Lib/Bit_Math.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/TMR_interface.h"
#include "MCAL/TMR_private.h"
#include "MCAL/GIE_interface.h"

void main()
{
    DIO_VidSetPinMode(Port_B, Pin_3, output);
    GIE_VidEnable();
    TMR_VidEnableTimer(0);
    TMR_VidSetDutyCycle(0, 49.5);
    TMR_VidInit();

    while (1)
    {
    }
}
