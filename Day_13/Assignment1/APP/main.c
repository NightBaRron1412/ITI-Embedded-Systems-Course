/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Amir Shetaia
 */
#include "../Lib/Std_Types.h"
#include "../MCAL/DIO_Interface.h"
#include "../HAL/CLCD_interface.h"
#include "../HAL/CLCD_config.h"
#include <util/delay.h>

void main()
{

    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_RS_PIN, output);
    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_RW_PIN, output);
    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_EN_PIN, output);

    DIO_VidSetPortMode(CLCD_DATA_PORT, output);

    DIO_VidSetPinMode(Port_C, Pin_0, input);
    DIO_VidSetPinMode(Port_C, Pin_1, input);

    DIO_VidSetPinValue(Port_C, Pin_0, high);
    DIO_VidSetPinValue(Port_C, Pin_1, high);

    DIO_VidSetPinMode(Port_D, Pin_0, output);
    DIO_VidSetPinMode(Port_D, Pin_1, output);

    CLCD_VidInit();

    u8 button1State = 0;
    u8 button2State = 0;
    u8 button1PrevState = 0;
    u8 button2PrevState = 0;

    while (1)
    {
        DIO_VidGetPinValue(Port_C, Pin_0, &button1State);
        DIO_VidGetPinValue(Port_C, Pin_1, &button2State);

        if (button1State != button1PrevState && button2State != button2PrevState)
        {
            if (button1State == 1 && button2State == 1)
            {
                CLCD_VidDisplayClear();
                CLCD_VidSendString("Motor Stopped");
                DIO_VidSetPinValue(Port_D, Pin_0, low);
                DIO_VidSetPinValue(Port_D, Pin_1, low);
            }
            button1PrevState = button1State;
            button2PrevState = button2State;
        }

        else if (button2State != button2PrevState)
        {
            if (button1State == 1 && button2State == 0)
            {
                CLCD_VidDisplayClear();
                CLCD_VidSendString("Motor rotating");
                CLCD_VidGotoXY(1, 0);
                CLCD_VidSendString("CW");
                DIO_VidSetPinValue(Port_D, Pin_0, high);
                DIO_VidSetPinValue(Port_D, Pin_1, low);
            }
            button2PrevState = button2State;
        }

        else if (button1State != button1PrevState)
        {
            if (button1State == 0 && button2State == 1)
            {
                CLCD_VidDisplayClear();
                CLCD_VidSendString("Motor rotating");
                CLCD_VidGotoXY(1, 0);
                CLCD_VidSendString("CCW");
                DIO_VidSetPinValue(Port_D, Pin_0, low);
                DIO_VidSetPinValue(Port_D, Pin_1, high);
            }
            button1PrevState = button1State;
        }
    }
}
