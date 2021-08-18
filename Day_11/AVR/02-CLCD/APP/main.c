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
#include <util/delay.h>

void main()
{

    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_RS_PIN, output);
    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_RW_PIN, output);
    DIO_VidSetPinMode(CLCD_CTRL_PORT, CLCD_EN_PIN, output);

    DIO_VidSetPortMode(CLCD_DATA_PORT, output);

    CLCD_VidCreatSpecialChar(Alef, 4);
    CLCD_VidCreatSpecialChar(Meem, 3);
    CLCD_VidCreatSpecialChar(Yaa, 2);
    CLCD_VidCreatSpecialChar(Raa, 1);
    CLCD_VidInit();

    while (1)
    {
        for (u8 i = 0; i < 10; i++)
        {
            CLCD_VidDisplayClear();
            CLCD_VidGotoXY(0, i);
            CLCD_VidSendData(1);
            CLCD_VidSendData(2);
            CLCD_VidSendData(3);
            CLCD_VidSendData(4);
            _delay_ms(200);
        }
    }
}
