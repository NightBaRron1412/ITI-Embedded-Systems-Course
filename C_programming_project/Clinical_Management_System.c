#include <stdio.h>                //Including standard input/output library.
#include <stdlib.h>               //Including standard library
#include "../include/Std_Types.h" // Including standard types header file

/*--------------------------Funtions Prototypes----------------------------------*/

void admin_mode();             //A prototype for a function that contains admin mode password input and menu
void add_new_patient();        // A prototype for a function that adds a new patient
void edit_patient_record();    //A prototype for a function that edits patient record
void doctor_reservation();     //A prototype for a function that reserves a doctor appointment
void cancel_reservation();     //A prototype for a function that cancels a doctor appointment
void user_mode();              //A prototype for a function that contains user mode menu
void view_patient_record();    //A prototype for a function that views patient record with id
void view_today_reservation(); //A prototype for a function that views all today reservations with patients id

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

struct patient_node *head = NULL;   //Creating head pointer for the first node as a global variable to save it's value
u32 list_length = 0;                //Creating a global variable for storing the length of the linked list
u32 entered_password = NOT_ENTERED; //A global variable for storing entered password

void main()
{
    while (1) //Creating an infinite loop
    {
        u16 mode_choice; //A variable to store the user input

        /*----------------------------Mode Menu---------------------*/

        printf("Enter 1 for admin mode\n"
               "Enter 2 for user mode\n"
               "Enter 3 to exit the system\n"
               "Your choice: ");

        scanf(" %hu", &mode_choice);

        switch (mode_choice)
        {
        case 1:
            admin_mode();
            break;

        case 2:
            user_mode();
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Wrong input\n\n");
            break;
        }
    }
}

/*--------------------------Admin Mode--------------------------------------*/

void admin_mode() //A function that contains admin mode password input and menu
{
    u32 tries = 1;               //counter for number of attempts to login
    u8 password_correct = False; //Flag for if password is correct

    if (entered_password == 404) //Asking for password if it hasn't been entered yet
    {
        printf("\nPlease enter your password: ");
        scanf("%d", &entered_password);
    }

    while (tries < 4) //While loop for more 2 tries to login
    {

        if (entered_password == admin_password) // if password has been entered correctly
        {
            /*------------------------------Admin Menu----------------------------*/
            password_correct = True; //Raising a flag for correct password
            u16 feature_choice;

            printf("\nEnter 1 for Adding new patient record\n"
                   "Enter 2 for Editing patient record\n"
                   "Enter 3 for Reserving a slot with the doctor\n"
                   "Enter 4 for Canceling reservation\n"
                   "Your choice: ");

            scanf(" %hu", &feature_choice);

            switch (feature_choice)
            {
            case 1:
                add_new_patient();
                break;

            case 2:
                edit_patient_record();
                break;

            case 3:
                doctor_reservation();
                break;

            case 4:
                cancel_reservation();
                break;

            default:
                printf("Wrong input\n\n");
                break;
            }
            break;
        }

        else if (tries < 3) // if password hasn't been entered correctly
        {
            password_correct = False; //Raising a flag for wrong password
            printf("Try again: ");
            scanf("%d", &entered_password);
        }

        tries++; //incresing the tries count
    }

    if (password_correct == False) //if user entered wrong password for 3 times
    {
        printf("\nIncorrect password for 3 times. No more tries\n");
        exit(0);
    }
}

void add_new_patient() //A prototype for a function that adds a new patient
{
    u8 unique_id = True; //Creating a flag for unique patient id

    if (list_length == EMPTY) //Checking if the head node exists
    {

        head = (struct patient_node *)malloc(sizeof(struct patient_node)); //Creating head node

        /*---------------------------- User data -----------------------------*/
        printf("\nEnter patient's name: ");
        scanf(" %s", &(head->name));
        printf("Enter patient's age: ");
        scanf(" %hu", &(head->age));
        printf("Enter patient's gender (m/f): ");
        scanf(" %c", &(head->gender));
        printf("Enter patient's id: ");
        scanf(" %hu", &(head->id));

        head->next = NULL; //Assigning NULL to head node next link
        list_length++;     //Incresing the length of the linked list
    }

    else
    {
        struct patient_node *current = (struct patient_node *)malloc(sizeof(struct patient_node)); //Creating new node
        struct patient_node *ptr = head;                                                           //Assigning a pointer to iterate through the linked list

        /*---------------------------- User data -----------------------------*/
        printf("\nEnter patient's name: ");
        scanf(" %s", &(current->name));
        printf("Enter patient's age: ");
        scanf(" %hu", &(current->age));
        printf("Enter patient's gender (m/f): ");
        scanf(" %c", &(current->gender));
        printf("Enter patient's id: ");
        scanf(" %hu", &(current->id));

        /*-------------------Checking for unique_id using linear Searching algorithm------------------------------*/

        for (u8 i = 1; i <= list_length; i++)
        {
            if (current->id == ptr->id)
            {
                printf("Id is not unique\n");
                unique_id = False;
                printf("Enter patient's id: ");
                scanf(" %d", &(current->id));
                ptr = head;
                i = 0;
            }

            else
            {
                unique_id = True;
                ptr = ptr->next;
            }
        }

        ptr = head; //Getting pointer back to the head of the linked list

        current->next = NULL; //Assigning NULL to current node next link

        while (ptr->next != NULL) //Iterating through the linked list till the last node
        {
            ptr = ptr->next; //Moving pointer to next node
        }
        ptr->next = current; //Linking to last nodes
        list_length++;       //Increasing the length of the linked list
    }

    printf("\nPatient Added!\n\n"); //Printing out a message
}

void edit_patient_record() //A prototype for a function that edits patient record

{
    if (list_length == EMPTY) //Checking if the list is empty
    {
        printf("\nNo patient records yet, Add a patient first\n\n");
    }

    else
    {
        struct patient_node *ptr = head;        //Assigning a pointer to iterate through the linked list
        struct patient_node *found_node = NULL; //Assigning a pointer to point to the node to be edited

        u16 entered_id;      //A variable to store entered id
        u8 id_found = False; //Creating a flag for if id has been found or not
        u16 edit_choice;     //a variable to store user edit choice from menu

        /*-------------------checking if entered ID exists-------------------------------*/
        while (id_found == False)
        {
            printf("Enter patient's id: ");
            scanf(" %hu", &entered_id);

            for (u8 i = 1; i <= list_length; i++) //Iterating through the linked list
            {
                if (entered_id == ptr->id) //If entered ID matched the node's id
                {
                    id_found = True;  //Raising flag
                    found_node = ptr; //Pointing to the node to be edited
                    break;            //Getting out of the loop
                }

                else //If entered ID didn't match the node's id
                {
                    id_found = False; //Raising flag
                    ptr = ptr->next;  //Moving pointer to next node
                }
            }

            ptr = head; //Moving pointer back to the head node

            if (id_found == False) //If ID doesn't exist in the linked list'
            {
                printf("ID not found\n"); //Printing out the error message
            }
        }

        /*-------------------Edit options-------------------------------*/

        while (edit_choice != 5)
        {
            printf("Enter 1 to edit patient's name\n"
                   "Enter 2 to edit patient's age\n"
                   "Enter 3 to edit patient's gender (m/f)\n"
                   "Enter 4 to edit patient's id\n"
                   "Enter 5 to go back\n"
                   "Your choice: ");

            scanf(" %hu", &edit_choice);

            switch (edit_choice)
            {
            case 1:
                printf("\nEnter patient's name: ");
                scanf(" %s", &(found_node->name));
                break;

            case 2:
                printf("Enter patient's age: ");
                scanf(" %hu", &(found_node->age));
                break;

            case 3:
                printf("Enter patient's gender (m/f): ");
                scanf(" %c", &(found_node->gender));
                break;

            case 4:
                printf("Enter patient's id: ");
                scanf(" %hu", &(found_node->id));
                break;

            default:
                printf("\nWrong input\n\n");
                break;
            }
            printf("\nData edited successfully\n\n"); //Printing out information
        }
    }
}

void doctor_reservation() //A prototype for a function that reserves a doctor appointment
{
    if (list_length == EMPTY)
    {
        printf("\nNo patient records yet, Add a patient first\n\n");
    }
    else
    {
        struct patient_node *ptr = head;         //Assigning a pointer to iterate through the linked list
        struct patient_node *chosen_node = NULL; //Assigning a pointer to point to the node that the reservation should be made for

        u16 entered_id;      //A variable to store entered id
        u8 id_found = False; //Creating a flag for if id has been found or not
        u16 res_choice;      //a variable to store user reservation choice from menu

        /*-------------------Printing out Avalivable Reservation Slots-------------------*/
        printf("\nAvalivable reservation slots: \n");

        if (reservations[0] == EMPTY)
        {
            printf("Enter 1 for (2pm to 2:30pm)\n");
        }
        if (reservations[1] == EMPTY)
        {
            printf("Enter 2 for (2:30pm to 3pm)\n");
        }
        if (reservations[2] == EMPTY)
        {
            printf("Enter 3 for (3pm to 3:30pm)\n");
        }
        if (reservations[3] == EMPTY)
        {
            printf("Enter 4 for (4pm to 4:30pm)\n");
        }
        if (reservations[4] == EMPTY)
        {
            printf("Enter 5 for (4:30pm to 5pm)\n");
        }

        //Admin reservation choice
        printf("Your choice: ");
        scanf(" %hu", &res_choice);

        while (reservations[res_choice - 1] != EMPTY) //Entering another slot if selected slot is not empty
        {
            printf("Slot not empty\n");
            printf("choose another slot: ");
            scanf(" %d", &res_choice);
        }

        while (id_found == False) //Cheking if ID exists
        {
            printf("Enter patient's id: ");
            scanf(" %hu", &entered_id);

            for (u8 i = 1; i <= list_length; i++) //iterating through the linked list
            {
                if (entered_id == ptr->id) //if ID exists
                {
                    id_found = True;   //Raising flag
                    chosen_node = ptr; //Pointing to the node to be edited
                    break;
                }

                else
                {
                    id_found = False; //Raising Flag
                    ptr = ptr->next;  //Moving flag
                }
            }

            ptr = head; //Moving pointer back to the head node

            if (id_found == False) //If ID didn't exist
            {
                printf("ID not found\n");
            }
        }

        reservations[res_choice - 1] = chosen_node->id; //Saving ID in Reservations array in the right place
    }
    printf("\nSlot reserved successfully\n\n"); //Printing out information
}

void cancel_reservation() //A prototype for a function that cancels a doctor appointment
{
    if (list_length == EMPTY) //Checking if list is empty
    {
        printf("\nNo patient records yet, Add a patient first\n\n"); //Printing out information
    }
    else
    {
        u16 entered_id;        //A variable to store entered id
        u16 res_found = False; //Creating a flag for if reservation has been found or not

        printf("Enter patient's id: ");
        scanf(" %hu", &entered_id);

        for (u16 i = 0; i <= 4; i++) //iterating through the reservations array
        {
            if (entered_id == reservations[i]) //If ID found
            {
                reservations[i] = EMPTY;                          //Deleting reservation
                printf("\nReservation deleted successfully\n\n"); //Printing out information
                res_found = True;                                 //Raising a flag
            }
        }
        if (res_found == False) //If ID not found
        {
            printf("\nNo reservations found for entered id\n\n"); //Printing out information
        }
    }
}

/*--------------------------User Mode--------------------------------------*/

void user_mode() //A prototype for a function that contains user mode menu
{
    u16 feature_choice; //A variable to store feature chose by user

    /*-----------------------User main menu-----------------------------*/

    printf("\nEnter 1 for Viewing patient record\n"
           "Enter 2 for Viewing today's reservations.\n"
           "Your choice: ");

    scanf(" %hu", &feature_choice);

    switch (feature_choice)
    {
    case 1:
        view_patient_record();
        break;

    case 2:
        view_today_reservation();
        break;

    default:
        printf("Wrong input\n\n");
        break;
    }
}

void view_patient_record() //A prototype for a function that views patient record with id
{
    if (list_length == EMPTY) //Checking if list is
    {
        printf("\nNo patient records yet, Add a patient first\n\n"); //Printing out information
    }

    else
    {
        struct patient_node *ptr = head;        //Assigning a pointer to iterate through the linked list
        struct patient_node *found_node = NULL; //Assigning a pointer to point to the node to be edited

        u16 entered_id;      //A variable to store entered id
        u8 id_found = False; //Creating a flag for if id has been found

        while (id_found == False) //Checking if id has been found
        {
            printf("Enter patient's id: ");
            scanf(" %hu", &entered_id);

            for (u8 i = 1; i <= list_length; i++) //Iterating through the linked list
            {
                if (entered_id == ptr->id) //If ID has been found
                {
                    id_found = True;  //Rasing Flag
                    found_node = ptr; //Pointing to the node to be edited
                    break;
                }

                else //If ID has not been found
                {
                    id_found = False; //Raising flag
                    ptr = ptr->next;  //Moving pointer to next node
                }
            }

            ptr = head; //Moving pointer back to the head node

            if (id_found == False) //If ID has not been found
            {
                printf("ID not found\n"); //Printing out information
            }
        }

        /*--------------------------Printing patient record-------------------------------------*/

        printf("\n-----------------------\n"
               "Patient record:\n"
               "Name:   %s\n"
               "Age:    %hu\n"
               "Gender: %c\n"
               "ID:     %hu\n"
               "-----------------------\n\n",
               found_node->name, found_node->age, found_node->gender, found_node->id);
    }
}

void view_today_reservation()
{
    u8 empty_reservation_num = EMPTY; //A variable to store number of empty reservation slots

    for (u8 i = 0; i <= 4; i++) //Iterating over the reservation slots
    {
        if (reservations[i] == EMPTY) //Check if slot is empty
        {
            empty_reservation_num++; //Increcing the number of empty slots
        }
    }

    /*-----------------------Printing reserved slots--------------------*/

    if (reservations[0] != EMPTY)
    {
        printf("\n(2pm to 2:30pm), Patient ID: %hu\n", reservations[0]);
    }
    if (reservations[1] != EMPTY)
    {
        printf(" (2:30pm to 3pm), Patient ID: %hu\n", reservations[1]);
    }
    if (reservations[2] != EMPTY)
    {
        printf(" (3pm to 3:30pm), Patient ID: %hu\n", reservations[2]);
    }
    if (reservations[3] != EMPTY)
    {
        printf(" (4pm to 4:30pm), Patient ID: %hu\n", reservations[3]);
    }
    if (reservations[4] != EMPTY)
    {
        printf(" (4:30pm to 5pm), Patient ID: %hu\n\n", reservations[4]);
    }

    if (empty_reservation_num == 5) //If all slots are empty
    {
        printf("\nThere are no reservations\n\n"); //Printing out information
    }
    else
    {
        printf("\n\n"); //Printing New lines after printing all reserved slots
    }
}