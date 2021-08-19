/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Amir Shetaia
 */
#include "../Lib/Std_Types.h"
#include "../MCAL/DIO_Interface.h"
#include "../HAL/CLCD_interface.h"
#include "../HAL/CLCD_config.h"
#include "../HAL/KPD_interface.h"
#include "../HAL/KPD_config.h"
#include <util/delay.h>

void main()
{

    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_RS_PIN, output);
    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_RW_PIN, output);
    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_EN_PIN, output);

    DIO_VidSetPortMode(CLCD_DATA_PORT, output);

    DIO_VidSetPortMode(KPD_u8PORT, 0b00001111);

    DIO_VidSetPortValue(KPD_u8PORT, 0b11110000);

    CLCD_VidInit();

    u8 Local_u8PassArr[4];
    u8 Local_u8Result;
    u8 Local_u8Tries;

    CLCD_VidSendString("Enter Password: ");

    for (u8 i = 0; i < 4; i++)
    {
        u8 Local_u8KPDResult = KPD_u8GetKey();

        if (Local_u8KPDResult != NOT_PRESSED)
        {
            Local_u8PassArr[i] = Local_u8KPDResult;
            CLCD_VidGotoXY(1, i);
            CLCD_VidSendString("*");
        }
        else
        {
            i--;
        }
    }

    while (Local_u8Tries < 2)
    {

        if (Local_u8PassArr[0] == '1' && Local_u8PassArr[1] == '2' && Local_u8PassArr[2] == '3' && Local_u8PassArr[3] == '4')
        {
            CLCD_VidDisplayClear();
            CLCD_VidSendString("Welcome Amir");
            break;
        }

        else
        {
            CLCD_VidDisplayClear();
            CLCD_VidSendString("Try again: ");

            for (u8 i = 0; i < 4; i++)
            {
                u8 Local_u8KPDResult = KPD_u8GetKey();

                if (Local_u8KPDResult != NOT_PRESSED)
                {
                    Local_u8PassArr[i] = Local_u8KPDResult;
                    CLCD_VidGotoXY(1, i);
                    CLCD_VidSendString("*");
                }
                else
                {
                    i--;
                }
            }
        }

        Local_u8Tries++;
    }

    if (Local_u8Tries >= 2)
    {
        CLCD_VidDisplayClear();
        CLCD_VidSendString("Too many tries");
        CLCD_VidGotoXY(1, 0);
        CLCD_VidSendString("Try again later");
    }

    while (1)
    {
    }
}
