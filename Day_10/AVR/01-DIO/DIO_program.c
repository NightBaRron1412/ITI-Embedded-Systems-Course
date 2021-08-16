#include "Lib/Bit_Math.h"
#include "Lib/Std_Types.h"
#include "DIO_private.h"
#include "DIO_interface.h"

//Pin functions
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) //Setting pin value to High or Low
{
    if (Copy_u8Value == low)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            CLR_BIT(PORTA, Copy_u8Pin);
            break;
        case (Port_B):
            CLR_BIT(PORTB, Copy_u8Pin);
            break;
        case (Port_C):
            CLR_BIT(PORTC, Copy_u8Pin);
            break;
        case (Port_D):
            CLR_BIT(PORTC, Copy_u8Pin);
            break;
        }
    }
    else if (Copy_u8Value == high)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            SET_BIT(PORTA, Copy_u8Pin);
            break;
        case (Port_B):
            SET_BIT(PORTB, Copy_u8Pin);
            break;
        case (Port_C):
            SET_BIT(PORTC, Copy_u8Pin);
            break;
        case (Port_D):
            SET_BIT(PORTD, Copy_u8Pin);
            break;
        }
    }
}
void DIO_VidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode) //Setting pin mode to Input or Output
{
    if (Copy_u8Mode == input)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            CLR_BIT(DDRA, Copy_u8Pin);
            break;
        case (Port_B):
            CLR_BIT(DDRB, Copy_u8Pin);
            break;
        case (Port_C):
            CLR_BIT(DDRC, Copy_u8Pin);
            break;
        case (Port_D):
            CLR_BIT(DDRD, Copy_u8Pin);
            break;
        }
    }
    else if (Copy_u8Mode == output)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            SET_BIT(DDRA, Copy_u8Pin);
            break;
        case (Port_B):
            SET_BIT(DDRB, Copy_u8Pin);
            break;
        case (Port_C):
            SET_BIT(DDRC, Copy_u8Pin);
            break;
        case (Port_D):
            SET_BIT(DDRD, Copy_u8Pin);
            break;
        }
    }
}
void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8PinValue) //Getting current pin value
{
    switch (Copy_u8Port)
    {
    case (Port_A):
        *Copy_Pu8PinValue = GET_BIT(DDRA, Copy_u8Pin);
        break;
    case (Port_B):
        *Copy_Pu8PinValue = GET_BIT(DDRB, Copy_u8Pin);
        break;
    case (Port_C):
        *Copy_Pu8PinValue = GET_BIT(DDRC, Copy_u8Pin);
        break;
    case (Port_D):
        *Copy_Pu8PinValue = GET_BIT(DDRD, Copy_u8Pin);
        break;
    }
}

//Port functions
void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) //Setting all pins values on port to High or Low
{
    if (Copy_u8Value == low)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            PORTA = 0x00;
            break;
        case (Port_B):
            PORTB = 0x00;
            break;
        case (Port_C):
            PORTC = 0x00;
            break;
        case (Port_D):
            PORTD = 0x00;
            break;
        }
    }
    else if (Copy_u8Value == high)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            PORTA = 0xff;
            break;
        case (Port_B):
            PORTB = 0xff;
            break;
        case (Port_C):
            PORTC = 0xff;
            break;
        case (Port_D):
            PORTD = 0xff;
            break;
        }
    }
}
void DIO_VidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode) //Setting all pins modes on port to Input or Output
{
    if (Copy_u8Mode == input)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            DDRA = 0x00;
            break;
        case (Port_B):
            DDRB = 0x00;
            break;
        case (Port_C):
            DDRC = 0x00;
            break;
        case (Port_D):
            DDRD = 0x00;
            break;
        }
    }
    else if (Copy_u8Mode == high)
    {
        switch (Copy_u8Port)
        {
        case (Port_A):
            DDRA = 0xff;
            break;
        case (Port_B):
            DDRB = 0xff;
            break;
        case (Port_C):
            DDRC = 0xff;
            break;
        case (Port_D):
            DDRD = 0xff;
            break;
        }
    }
}
void DIO_VidGetPortValue(u8 Copy_u8Port, u8 *Copy_Pu8PortValue) //Getting current pins values on port
{
    switch (Copy_u8Port)
    {
    case (Port_A):
        *Copy_Pu8PortValue = PINA;
        break;
    case (Port_B):
        *Copy_Pu8PortValue = PINB;
        break;
    case (Port_C):
        *Copy_Pu8PortValue = PINC;
        break;
    case (Port_D):
        *Copy_Pu8PortValue = PIND;
        break;
    }
}