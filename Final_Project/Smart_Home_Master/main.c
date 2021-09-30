/*
* SmartHome_Master.c
*
* Created: 09/07/2021 9:24:27 PM
* Author : Amir Shetaia
*/

/*-------------------Header files including----------------------*/
#include "Lib/Std_Types.h"
#include "MCAL/SPI_interface.h"
#include "HAL/CLCD_interface.h"
#include "MCAL/USART_interface.h"
#include "MCAL/TMR_interface.h"
#include "MCAL/GIE_interface.h"
#include "MCAL/DIO_interface.h"
#include <util/delay.h>

/*-------------------Functions protoypes----------------------*/
void TMR1_ISR();

/*-------------------Global Variables----------------------*/
u8 TN1 = 0, TN2 = 0, CMD;

int main(void)
{
    /*-------------------Drivers Initializing----------------------*/
    /* USART init */
    USART_VidInit();

    /* SPI Master init */
    DIO_VidSetPinMode(Port_B, Pin_4, output);
    DIO_VidSetPinMode(Port_B, Pin_5, output);
    DIO_VidSetPinMode(Port_B, Pin_7, output);
    DIO_VidSetPinMode(Port_B, Pin_6, input);
    DIO_VidSetPinValue(Port_B, Pin_4, high);
    SPI_VidInit();

    /* Slave EN */
    DIO_VidSetPinValue(Port_B, Pin_4, low);

    /* CLCD init */
    DIO_VidSetPortMode(Port_A, Port_output);
    DIO_VidSetPortMode(Port_C, Port_output);
    CLCD_VidInit();

    CLCD_VidSendString("Welcome :)");
    CLCD_VidGotoXY(1, 0);
    CLCD_VidSendString("Temperature: ");

    /* Timer 1 init */
    GIE_VidEnable();
    TMR_VidInit();
    TMR_VidSetDutyCycle(1, 12);
    TMR_VidSetCallBack(1, TMR1_ISR);

    /* First Temperature Read */
    _delay_ms(200);
    SPI_VidSendByte(0x44);
    _delay_ms(200);
    TN1 = SPI_u8TranceiveByte(0x21);
    _delay_ms(200);
    TN2 = SPI_u8TranceiveByte(0x22);

    CLCD_VidGotoXY(1, 13);
    CLCD_VidSendData(TN1);
    CLCD_VidGotoXY(1, 14);
    CLCD_VidSendData(TN2);

    /*-------------------Program Loop----------------------*/

    while (1)
    {
        CMD = USART_u8ReceiveByte();
        SPI_VidSendByte(CMD);
        _delay_ms(500);
    }
}

/*-------------------Timer 1 ISR----------------------*/

void TMR1_ISR()
{
    /* Reading Tempretaure */
    SPI_VidSendByte(0x44);
    _delay_ms(200);
    TN1 = SPI_u8TranceiveByte(0x21);
    _delay_ms(200);
    TN2 = SPI_u8TranceiveByte(0x22);

    CLCD_VidGotoXY(1, 13);
    CLCD_VidSendData(TN1);
    CLCD_VidGotoXY(1, 14);
    CLCD_VidSendData(TN2);
}
