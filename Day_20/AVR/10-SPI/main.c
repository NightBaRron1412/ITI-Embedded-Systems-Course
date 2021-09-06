/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: amoor
 */

#include "Lib/Std_Types.h"
#include "MCAL/SPI_interface.h"
#include "MCAL/DIO_interface.h"
void callback()
{
}
void main()
{
    DIO_VidSetPinMode(Port_B, Pin_4, output);
    DIO_VidSetPinMode(Port_B, Pin_5, output);
    DIO_VidSetPinMode(Port_B, Pin_6, input);
    DIO_VidSetPinMode(Port_B, Pin_7, output);
    SPI_VidInit();
    SPI_VidSendString("ITI");
    SPI_VidSendByte(0xF4);
}
