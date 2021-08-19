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

    while (1)
    {
        u8 Local_u8KPDResult = KPD_u8GetKey();

        if (Local_u8KPDResult != NOT_PRESSED)
        {

            CLCD_VidSendData(Local_u8KPDResult);
        }
    }
}
