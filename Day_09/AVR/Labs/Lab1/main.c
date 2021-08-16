/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Amir Shetaia
 */

#include <avr/io.h> //Including standard AVR IO functions

void main()
{
    DDRA = 0x01;  //Setting pin A0 to output
    PORTA = 0x01; //Setting pin A0 to High
}
