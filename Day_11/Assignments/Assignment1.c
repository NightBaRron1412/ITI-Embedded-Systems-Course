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

    CLCD_VidInit();

    CLCD_VidSendString("I love ITI");

    while (1)
    {
    }
}