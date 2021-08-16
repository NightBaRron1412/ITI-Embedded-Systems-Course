/*
 * main.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Amir Shetaia
 */

#include <avr/io.h>     //Icluding standard io functions
#include <util/delay.h> //Including delay function

void main()
{
    DDRA = 0x03;     //Setting pins A0, A1 to Output on PORTA
    PORTA = 0x03;    //Setting pins A0, A1 to High on PORTA
    _delay_ms(1000); //Delay for 1000 milliseconds
    PORTA = 0x00;    //Setting pins A0, A1 to Low on PORTA

    while (1)
    {
    }
}
