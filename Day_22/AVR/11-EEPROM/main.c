/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Amir Shetaia
 */

#include "Lib/Std_Types.h"
#include "MCAL/TWI_interface.h"
#include "HAL/EEPROM_interface.h"
#include <util/delay.h>

u8 val[12];

void main()
{
    TWI_VidInit();
    EEPROM_VidWirteBlock(0x00, "Menna Ayman");

    EEPROM_VidReadBlock(0x00, 12, val);

    EEPROM_VidWirteBlock(0x0B, " A7la Ba4mohandesa");
}
