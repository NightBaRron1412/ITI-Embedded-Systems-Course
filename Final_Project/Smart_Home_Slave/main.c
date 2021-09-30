/*
* SmartHome_Slave.c
*
* Created: 09/07/2021 6:59:21 PM
* Author : Amir Shetaia
*/
#include "Lib/Std_Types.h"
#include "MCAL/SPI_interface.h"
#include "HAL/CLCD_interface.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/ADC_interface.h"
#include "HAL/DC_Motor.h"
#include <stdlib.h>
#include <util/delay.h>

int main(void)
{
    /* CLCD init */
    DIO_VidSetPortMode(Port_C, Port_output);
    DIO_VidSetPinMode(Port_A, Pin_5, output);
    DIO_VidSetPinMode(Port_A, Pin_6, output);
    DIO_VidSetPinMode(Port_A, Pin_7, output);
    CLCD_VidInit();

    /* ADC init */
    ADC_VidInit();

    /* DC Motor init */
    DC_Motor_Init();

    /* SPI Master init */
    DIO_VidSetPinMode(Port_B, Pin_4, input);
    DIO_VidSetPinMode(Port_B, Pin_5, input);
    DIO_VidSetPinMode(Port_B, Pin_7, input);
    DIO_VidSetPinMode(Port_B, Pin_6, output);
    SPI_VidInit();

    /* LED Port Mode Set */
    DIO_VidSetPinMode(Port_D, Pin_0, output);

    /*-------------------Local Variables----------------------*/

    u16 Temp = 0;
    s8 buffer[2];
    u8 CMD;

    while (1)
    {
        /* Receive Command from Master */
        CMD = SPI_u8ReceiveByte();
        _delay_ms(100);

        /*-------------------Checking Command----------------------*/

        switch (CMD)
        {

        /* Light ON */
        case '1':
            DIO_VidSetPinValue(Port_D, Pin_0, high);
            CLCD_VidDisplayClear();
            CLCD_VidSendString("Light ON");
            break;

        /* Light OFF */
        case '2':
            DIO_VidSetPinValue(Port_D, Pin_0, low);
            CLCD_VidDisplayClear();
            CLCD_VidSendString("Light OFF");
            break;

        /* DC Motor ON FWD */
        case '3':
            DC_Motor_Direction('F');
            CLCD_VidDisplayClear();
            CLCD_VidGotoXY(0, 0);
            CLCD_VidSendString("DC Motor ON");
            CLCD_VidGotoXY(1, 0);
            CLCD_VidSendString("Forward Dir");
            break;

        /* DC Motor ON BWD */
        case '4':
            DC_Motor_Direction('B');
            CLCD_VidDisplayClear();
            CLCD_VidGotoXY(0, 0);
            CLCD_VidSendString("DC Motor ON");
            CLCD_VidGotoXY(1, 0);
            CLCD_VidSendString("Backward Dir");
            break;

        /* Light ON */
        case 0x44:
            Temp = ADC_u16Read(A0);
            Temp = (Temp * 5.0 / 1023UL) * 100;
            itoa(Temp, buffer, 10);

            if (SPI_u8TranceiveByte(buffer[0]) == 0x21)
            {
                CLCD_VidDisplayClear();
                CLCD_VidGotoXY(0, 0);
                CLCD_VidSendString("Reading");
                CLCD_VidGotoXY(1, 0);
                CLCD_VidSendString("Temperature");
            }

            if (SPI_u8TranceiveByte(buffer[1]) == 0x22)
            {
                CLCD_VidDisplayClear();
            }
            break;
        }
    }
}
