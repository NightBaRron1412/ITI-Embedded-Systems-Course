/** @file RTOS_interface.h
 * 
 * @brief A header file including functions for RTOS
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Sep 6, 2021       
 *
*/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_VidStart();

void RTOS_VidDispatcher();

void RTOS_VidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*func)(void));


#endif /* RTOS_INTERFACE_H */

/*** end of file ***/
