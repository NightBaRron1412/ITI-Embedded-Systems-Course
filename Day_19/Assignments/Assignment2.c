/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "Lib/Bit_Math.h"
#include "MCAL/USART_interface.h"
#include "MCAL/DIO_interface.h"
#include <avr/io.h>
#include <util/delay.h>

u8 option;

void main()
{
    USART_VidInit();
    DDRA = 0xff;  //Setting all pins on PORTA to output mode
    DDRB = 0x00;  //Setting all pins on PORTB to input mode
    PORTB = 0xff; //Activating internal pull up resistor on all PORTB pins

    while (1)
    {
        option = USART_u8ReceiveByte();

        /*--------------------------Flashing every 500 ms-------------------------------*/

        if (option == 'a')
        {
            PORTA = 0xff;   //Setting all pins on PORTA to high
            _delay_ms(500); //Delay for 500 milliseconds
            PORTA = 0x00;   //Setting all pins on PORTA to low
            _delay_ms(500); //Delay for 500 milliseconds
        }

        /*--------------------------Shifting Left every 250 ms-------------------------------*/

        else if (option == 'b')
        {
            for (s8 i = 7; i >= 0; i--)
            {
                SET_BIT(PORTA, i); //Setting pin #i on PORTA to high
                _delay_ms(250);    //Delay for 250 milliseconds
                CLR_BIT(PORTA, i); //Setting pin #i on PORTA to low
            }
        }

        /*--------------------------Shifting Right every 250 ms-------------------------------*/

        else if (option == 'c') //Shifting Right every 250 ms
        {
            for (s8 i = 0; i <= 7; i++)
            {
                SET_BIT(PORTA, i); //Setting pin #i on PORTA to high
                _delay_ms(250);    //Delay for 250 milliseconds
                CLR_BIT(PORTA, i); //Setting pin #i on PORTA to low
            }
        }

        /*--------------------------2-LEDs Converging every 300 ms-------------------------------*/

        else if (option == 'd')
        {
            for (u8 i = 0; i <= 3; i++)
            {
                SET_BIT(PORTA, i);     //Setting pin #i on PORTA to high
                SET_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to high
                _delay_ms(300);        //Delay for 250 milliseconds
                CLR_BIT(PORTA, i);     //Setting pin #i on PORTA to low
                CLR_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to low
            }
        }

        /*--------------------------2-LEDs Diverging every 300 ms-------------------------------*/

        else if (option == 'e')
        {
            for (s8 i = 3; i >= 0; i--)
            {
                SET_BIT(PORTA, i);     //Setting pin #i on PORTA to high
                SET_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to high
                _delay_ms(300);        //Delay for 250 milliseconds
                CLR_BIT(PORTA, i);     //Setting pin #i on PORTA to low
                CLR_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to low
            }
        }

        /*--------------------------Ping Pong effect every 250 ms-------------------------------*/

        else if (option == 'e')
        {
            for (u8 i = 0; i <= 3; i++)
            {
                SET_BIT(PORTA, i);     //Setting pin #i on PORTA to high
                SET_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to high
                _delay_ms(250);        //Delay for 250 milliseconds
            }

            for (s8 i = 3; i >= 0; i--)
            {
                CLR_BIT(PORTA, i);     //Setting pin #i on PORTA to low
                CLR_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to low
                _delay_ms(250);        //Delay for 250 milliseconds
            }
        }

        /*--------------------------Incrementing (Snake effect) every 300 ms-------------------------------*/

        else if (option == 'f')
        {
            for (u8 i = 0; i <= 7; i++)
            {
                SET_BIT(PORTA, i); //Setting pin #i on PORTA to high
                _delay_ms(300);    //Delay for 250 milliseconds
            }
            PORTA = 0x00;   //Setting all pins on PORTA to low
            _delay_ms(300); //Delay for 250 milliseconds
        }

        /*--------------------------2-LEDs Converging/Diverging every 300 ms-------------------------------*/

        else if (option == 'g')
        {
            for (u8 i = 0; i <= 3; i++)
            {
                SET_BIT(PORTA, i);     //Setting pin #i on PORTA to high
                SET_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to high
                _delay_ms(300);        //Delay for 250 milliseconds
                CLR_BIT(PORTA, i);
                CLR_BIT(PORTA, 7 - i);
            }

            for (s8 i = 2; i >= 1; i--)
            {
                SET_BIT(PORTA, i);     //Setting pin #i on PORTA to high
                SET_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to high
                _delay_ms(300);        //Delay for 250 milliseconds
                CLR_BIT(PORTA, i);     //Setting pin #i on PORTA to low
                CLR_BIT(PORTA, 7 - i); //Setting pin #7 - i on PORTA to low
            }
        }
    }
}
