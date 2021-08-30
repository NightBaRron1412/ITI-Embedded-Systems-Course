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
u8 Sev_Seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
static u8 i = 1;

void blink()
{
    DIO_VidSetPortValue(Port_C, Sev_Seg[i]);
    i++;
    if (i == 10)
    {
        i = 0;
    }
}

void main()
{
    DIO_VidSetPortMode(Port_C, Port_output);
    DIO_VidSetPortValue(Port_C, Sev_Seg[0]);
    GIE_VidEnable();
    TMR_VidEnableTimer(0);
    TMR_VidInit();
    TMR_VidSetCallBack(0, blink);
    while (1)
    {
    }
}
