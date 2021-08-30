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
#include "MCAL/GIE_interface.h"
static u8 state = 1;

void blink()
{
    state = !state;
    DIO_VidSetPinValue(Port_B, Pin_3, state);
}

void main()
{
    DIO_VidSetPinMode(Port_B, Pin_3, output);
    GIE_VidEnable();
    TMR_VidEnableTimer(0);
    TMR_VidInit();
    TMR_VidSetCallBack(0, blink);
    while (1)
    {
    }
}
