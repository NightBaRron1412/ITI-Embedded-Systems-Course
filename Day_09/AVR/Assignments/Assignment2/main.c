/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Amir Shetaia
 */

#include <avr/io.h>                     //Including standard AVR IO functions
#include <util/delay.h>                 //Including delay functions
#include "../../../include/Std_Types.h" // Including standard types header
#include "../../../include/Bit_Math.h"  // Including bit math functions header

void main()
{
    DDRA = 0xff;  //Setting all pins on PORTA to output mode
    DDRB = 0x00;  //Setting all pins on PORTB to input mode
    PORTB = 0xff; //Activating internal pull up resistor on all PORTB pins

    while (1) //Creating an infinite loop
    {

        /*--------------------------Flashing every 500 ms-------------------------------*/

        if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 0)
        {
            PORTA = 0xff;   //Setting all pins on PORTA to high
            _delay_ms(500); //Delay for 500 milliseconds
            PORTA = 0x00;   //Setting all pins on PORTA to low
            _delay_ms(500); //Delay for 500 milliseconds
        }

        /*--------------------------Shifting Left every 250 ms-------------------------------*/

        else if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 0)
        {
            for (s8 i = 7; i >= 0; i--)
            {
                SET_BIT(PORTA, i); //Setting pin #i on PORTA to high
                _delay_ms(250);    //Delay for 250 milliseconds
                CLR_BIT(PORTA, i); //Setting pin #i on PORTA to low
            }
        }

        /*--------------------------Shifting Right every 250 ms-------------------------------*/

        else if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 0) //Shifting Right every 250 ms
        {
            for (s8 i = 0; i <= 7; i++)
            {
                SET_BIT(PORTA, i); //Setting pin #i on PORTA to high
                _delay_ms(250);    //Delay for 250 milliseconds
                CLR_BIT(PORTA, i); //Setting pin #i on PORTA to low
            }
        }

        /*--------------------------2-LEDs Converging every 300 ms-------------------------------*/

        else if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 1)
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

        else if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 0)
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

        else if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 1)
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

        else if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 1)
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

        else if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 1)
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
