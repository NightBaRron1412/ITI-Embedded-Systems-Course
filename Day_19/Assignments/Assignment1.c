/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "MCAL/USART_interface.h"
#include "MCAL/DIO_interface.h"
u8 str[50];

void main()
{
    USART_VidInit();

    while (1)
    {
        USART_VidSendString("Please Enter your name: ");
        USART_VidReceiveString(str);
        USART_VidSendString("Hello, ");
        USART_VidSendString(str);
        USART_VidSendByte('\r');
    }
}
