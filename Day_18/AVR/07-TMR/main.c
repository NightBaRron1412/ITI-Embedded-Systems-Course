/*
 * main.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Amir Shetaia
 */
#include "Lib/Std_Types.h"
#include "Lib/Bit_Math.h"
#include "Lib/Utils.h"
#include "HAL/CLCD_interface.h"
#include <stdlib.h>
#include "MCAL/DIO_interface.h"
#include "MCAL/TMR_interface.h"
#include "MCAL/GIE_interface.h"
#include <util/delay.h>

void main()
{
    DIO_VidSetPortMode(Port_A, Port_output);
    DIO_VidSetPortMode(Port_B, Port_output);

    DIO_VidSetPinMode(Port_D, Pin_5, output);

    GIE_VidEnable();
    TMR_VidEnableTimer(1);
    TMR_VidInit();
    CLCD_VidInit();
    char String[5];
    char String1[5];
    u16 Val1;
	u16 Val;

    while (1)
    {

        CLCD_VidDisplayClear();
        CLCD_VidGotoXY(0, 0);
        CLCD_VidSendString("Period =");
        CLCD_VidGotoXY(0, 8);
        Val = TMR_u16GetPeriod();
        itoa(Val, String, 10); /* Integer to string conversion */
        CLCD_VidSendString(String);
        CLCD_VidGotoXY(0, 14);
        CLCD_VidSendString("us");
        CLCD_VidGotoXY(1, 0);
        CLCD_VidSendString("OnTime =");
        CLCD_VidGotoXY(1, 8);
        Val1 = TMR_u16OnTime();
        itoa(Val1, String1, 10); /* Integer to string conversion */
        CLCD_VidSendString(String1);
        CLCD_VidGotoXY(1, 14);
        CLCD_VidSendString("us");
        _delay_ms(1000);
    }
}
