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
    DDRA = 0xff; //Setting all pins on PORTA to output mode

    while (1) //Creating an infinite loop
    {
        for (s8 i = 0; i <= 7; i++) //Looping through PORTA pins
        {
            SET_BIT(PORTA, i); //Setting pin #i to High
            _delay_ms(200);    //Delay for 100 milliseconds
        }

        for (s8 i = 7; i >= 0; i--) //Looping through PORTA pins
        {
            CLR_BIT(PORTA, i); //Setting pin #i to Low
            _delay_ms(200);    //Delay for 100 milliseconds
        }
    }
}
