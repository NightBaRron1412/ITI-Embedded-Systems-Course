/******************************************************************************
 * Copyright (C) 2021 by Amir Shetaia
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. 
 * Amir Shetaia are not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Clinical_Management_System.h
 * @brief Header file for Clinical Management System
 *
 * Header file that contains important functions prototypes, 
 * Linked List nodes strucure declration and Enum for avoiding use of magic numbers
 * for a clinical management system
 *
 * @author Amir Shetaia
 * @date 21 Aug 2021
 *
 */

#ifndef __CLINICAL_MANAGEMENT_SYSTEM_H__
#define __CLINICAL_MANAGEMENT_SYSTEM_H__

/*--------------------------Funtions Prototypes----------------------------------*/

void admin_mode();
/**
 * @brief A function that contains admin mode password input and menu
 *
 * @param void
 *
 * @return void
 */

void add_new_patient();
/**
 * @brief A function that adds a new patient
 *
 * @param void
 *
 * @return void
 */

void edit_patient_record();
/**
 * @brief A function that edits patient record
 *
 * @param void
 *
 * @return void
 */

void doctor_reservation();
/**
 * @brief A function that reserves a doctor appointment
 *
 * @param void
 *
 * @return void
 */

void cancel_reservation();
/**
 * @brief A function that cancels a doctor appointment
 *
 * @param void
 *
 * @return void
 */

void user_mode();
/**
 * @brief A function that contains user mode menu
 *
 * @param void
 *
 * @return void
 */

void view_patient_record();
/**
 * @brief A function that views patient record with id
 *
 * @param void
 *
 * @return void
 */

void view_today_reservation();
/**
 * @brief A function that views all today reservations with patients id
 *
 * @param void
 *
 * @return void
 */

/*----------------------User defined types----------------------------------------*/

typedef enum // Enum data type for storing boolean values
{
    True,
    False,
    NOT_ENTERED = 404,
    admin_password = 1234,
    EMPTY = 0
} Enut_CMS;

struct patient_node //a node structure for patients linked list
{
    u8 name[20];
    u16 age;
    u8 gender;
    u16 id;
    struct patient_node *next;
};

//An array containing reservations and patient IDs associated with every slot
u16 reservations[] = {0 /*2pm to 2:30pm*/, 0 /*2:30pm to 3pm*/, 0 /*3pm to 3:30pm*/, 0 /*4pm to 4:30pm*/, 0 /*4:30pm to 5pm*/};

#endif /*__CLINICAL_MANAGEMENT_SYSTEM_H__*/