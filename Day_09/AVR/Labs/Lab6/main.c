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
    PORTB = 0x01; //Activating internal pull up resistor on pin B0

    while (1) //Creating an infinite loop
    {
        if (GET_BIT(PINB, 0) == 0)
        {
            PORTA = 0xff;   //Setting all pins on PORTA to high
            _delay_ms(500); //Delay for 500 milliseconds
            PORTA = 0x00;   //Setting all pins on PORTA to low
            _delay_ms(500); //Delay for 500 milliseconds
        }
        else
        {
            PORTA = 0x00; //Setting all pins on PORTA to low
        }
    }
}
