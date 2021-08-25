/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/ADC_interface.h"
#include "HAL/CLCD_interface.h"
#include <stdlib.h>
#include <util/delay.h>

void main()
{
    DIO_VidSetPortMode(Port_D, Port_output);
    DIO_VidSetPortMode(Port_C, Port_output);
    DIO_VidSetPinMode(Port_A, Pin_2, input);
    u16 ADCVal;
    ADC_VidInit();
    CLCD_VidInit();
    char String[5];

    while (1)
    {
        CLCD_VidDisplayClear();
        CLCD_VidGotoXY(0, 0);
        CLCD_VidSendString("Volt =");
        CLCD_VidGotoXY(1, 6);
        ADCVal = ((ADC_VidRead(A2) * 5) / 1.024);
        itoa(ADCVal, String, 10); /* Integer to string conversion */
        CLCD_VidSendString(String);
        CLCD_VidSendString("mV");
        _delay_ms(1000);
    }
}
