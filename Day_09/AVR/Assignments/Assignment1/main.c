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

    DDRA = 0x07; //Setting pins A0-2 to output mode
    DDRC = 0x7f; //Setting pins C0-6 to output mode ..Sev_Seg 1
    DDRD = 0x7f; //Setting pins C0-6 to output mode ..Sev_Seg 2

    while (1) //Creating an infinite loop
    {
        SET_BIT(PORTA, 2);  //Setting pin A2 to high
        PORTC = Sev_Seg[1]; //Showing 1 on first 7Seg
        PORTD = Sev_Seg[0]; //Showing 0 on second 7Seg
        _delay_ms(1000);    //Waiting for 1 second

        for (s8 i = 0; i >= 0; i--) //Looping to countdown the first 7Seg
        {
            PORTC = Sev_Seg[i];

            for (s8 j = 9; j >= 1; j--) //Looping to countdown the second 7Seg
            {
                PORTD = Sev_Seg[j];
                _delay_ms(1000);
            }
        }

        CLR_BIT(PORTA, 2); //Setting pin A2 to low

        SET_BIT(PORTA, 1);  //Setting pin A1 to high
        PORTC = Sev_Seg[0]; //Showing 0 on first 7Seg
        PORTD = Sev_Seg[3]; //Showing 3 on second 7Seg
        _delay_ms(1000);    //Waiting for 1 second

        for (s8 i = 0; i >= 0; i--) //Looping to countdown the first 7Seg
        {
            PORTC = Sev_Seg[i];

            for (s8 j = 2; j >= 1; j--) //Looping to countdown the second 7Seg
            {
                PORTD = Sev_Seg[j];
                _delay_ms(1000);
            }
        }

        CLR_BIT(PORTA, 1); //Setting pin A1 to low

        SET_BIT(PORTA, 0);  //Setting pin A0 to high
        PORTC = Sev_Seg[1]; //Showing 1 on first 7Seg
        PORTD = Sev_Seg[0]; //Showing 0 on second 7Seg
        _delay_ms(1000);    //Waiting for 1 second

        for (s8 i = 0; i >= 0; i--) //Looping to countdown the first 7Seg
        {
            PORTC = Sev_Seg[i];

            for (s8 j = 9; j >= 1; j--) //Looping to countdown the second 7Seg
            {
                PORTD = Sev_Seg[j];
                _delay_ms(1000);
            }
        }

        CLR_BIT(PORTA, 0); //Setting pin A0 to low
    }
}
