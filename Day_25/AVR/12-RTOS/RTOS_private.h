/** @file RTOS_private.h
 * 
 * @brief A header file including functions for RTOS
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Sep 6, 2021       
 *
*/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{

    u16 Periodicity;
    u16 TaskCounter;
    void (*TaskFunc)(void);
    u8 RunMe;

} TaskControlBlock_t;

static void VidAlgorithm();

#endif /* RTOS_PRIVATE_H */

/*** end of file ***/
