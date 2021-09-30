#include "DC_Motor.h"

void DC_Motor_Init()
{
	DDRD |= (1<<1)|(1<<2);
	DDRD |= (1<<1);
	OCR1A = 200;
	TCCR1A =  (1<<WGM10) | (1<<COM1A1);
	TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10);
}

void DC_Motor_Direction(unsigned char Dir)
{
	switch(Dir)
	{
		case 'F':
		PORTD |= (1<<1);
		PORTD &=~ (1<<2);
		break;
		case 'B':
		PORTD |= (1<<2);
		PORTD &=~ (1<<1);
		break;
	}
}