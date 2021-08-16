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
    u8 Sev_Seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    DDRC = 0xff; //Setting all pins on PORTA to output mode

    while (1) //Creating an infinite loop
    {
        for (u8 i = 0; i < 10; i++) //Looping through the seven segments numbers
        {
            PORTC = Sev_Seg[i]; //Setting port to show number
            _delay_ms(1000);    //Delay for 1 second
        }
    }
}
