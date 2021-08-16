/*
 * main.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Amir Shetaia
 */

#include <avr/io.h>     //including standard AVR IO functions
#include <util/delay.h> // including delay function

void main()
{
    DDRA = 0x01; //Setting pins 0 to output mode
    while (1)
    {
        PORTA = 0x01;    //Setting pin A0 to High
        _delay_ms(1000); //Delay for 1 second
        PORTA = 0x00;    // Setting pin A0 to Low
        _delay_ms(1000); //Delay for 1 second
    }
}
