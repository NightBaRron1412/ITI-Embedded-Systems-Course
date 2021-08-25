/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/ADC_interface.h"

void main()
{
    DIO_VidSetPortMode(Port_C, Port_output);
    DIO_VidSetPinMode(Port_A, Pin_0, input);
    u16 ADCVal;
    ADC_VidInit();

    while (1)
    {
        ADCVal = ((ADC_VidRead(A0) * 5) / 0.255);
        
        if (ADCVal > 0 && ADCVal < 1500)
        {
            DIO_VidSetPinValue(Port_C, Pin_0, high);
            DIO_VidSetPinValue(Port_C, Pin_1, low);
            DIO_VidSetPinValue(Port_C, Pin_2, low);
        }
        else if (ADCVal > 1500 && ADCVal < 3000)
        {
            DIO_VidSetPinValue(Port_C, Pin_0, low);
            DIO_VidSetPinValue(Port_C, Pin_1, high);
            DIO_VidSetPinValue(Port_C, Pin_2, low);
        }
        else if (ADCVal > 3000)
        {
            DIO_VidSetPinValue(Port_C, Pin_0, low);
            DIO_VidSetPinValue(Port_C, Pin_1, low);
            DIO_VidSetPinValue(Port_C, Pin_2, high);
        }
    }
}
