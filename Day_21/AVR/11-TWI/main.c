/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Amir Shetaia
 */
#include "Lib/Std_Types.h"
#include "MCAL/TWI_interface.h"
#include <util/delay.h>

void main()
{
    TWI_VidInit();
    TWI_VidStart();
    TWI_VidSendAddrres(50, TWI_WRITE);
    TWI_VidWrite(20);
    _delay_ms(1000);
    TWI_VidStop();

    while (1)
    {
    }
}
