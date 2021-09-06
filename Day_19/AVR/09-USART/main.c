/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "MCAL/USART_interface.h"
#include "MCAL/ADC_interface.h"
#include "MCAL/DIO_interface.h"
#include <stdlib.h>
#include <util/delay.h>
char String[5];

void main()
{
    DIO_VidSetPinMode(Port_A, Pin_2, input);
    USART_VidInit();
    u16 ADCVal;
    ADC_VidInit();
    while (1)
    {
        ADCVal = (ADC_VidRead(A2));
        itoa(ADCVal, String, 10); /* Integer to string conversion */
        USART_VidSendString(String);
        USART_VidSendByte('\r');
        _delay_ms(250);
    }
}
