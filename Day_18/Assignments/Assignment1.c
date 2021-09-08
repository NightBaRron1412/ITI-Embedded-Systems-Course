/*
 * main.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Amir Shetaia
 */
#include "Lib/Std_Types.h"
#include "Lib/Bit_Math.h"
#include "Lib/Utils.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/TMR_interface.h"
#include "MCAL/GIE_interface.h"
#include "MCAL/ADC_interface.h"

void main()
{
    DIO_VidSetPinMode(Port_D, Pin_5, output);
    DIO_VidSetPinMode(Port_A, Pin_0, input);

    GIE_VidEnable();
    TMR_VidEnableTimer(1);
    TMR_VidInit();
    ADC_VidInit();

    while (1)
    {
        u16 PotVal = ADC_VidRead(A0);

        u16 PWMVal = map(PotVal, 0, 1023, 1000, 2000);

        TMR_VidSetPWM(PWMVal);
    }
}
