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
static u8 counter = 0;
static u8 state = 0;

void Sev_Seg_Counter()
{
    state = !state;
    DIO_VidSetPinValue(Port_D, Pin_1, state);
    DIO_VidSetPinValue(Port_D, Pin_2, !state);
}
void increase()
{
    DIO_VidSetPortValue(Port_C, Sev_Seg[counter]);
    counter++;
    if (counter == 10)
    {
        counter = 0;
    }
}
void main()
{
    DIO_VidSetPortMode(Port_C, Port_output);
    DIO_VidSetPortMode(Port_D, Port_output);
    GIE_VidEnable();
    TMR_VidEnableTimer(0);
    TMR_VidEnableTimer(2);
    TMR_VidInit();
    TMR_VidSetCallBack(0, Sev_Seg_Counter);
    TMR_VidSetCallBack(2, increase);

    while (1)
    {
    }
}
