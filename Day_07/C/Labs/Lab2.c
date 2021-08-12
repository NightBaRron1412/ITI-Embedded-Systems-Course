#include <stdio.h>     //including standard input/output library.
#include <stdlib.h>    //including standard library
#include "Std_Types.h" // including standard types

void add_node(u32 value); //Prototype of a function that adds a new node
void print_list();        //Prototype of a function that prints the data inside the linked list

struct node //Creating Node structure
{
    u32 data;          //Data
    struct node *next; //Nodes link
};

u16 list_length = 0;      //A variable to store the length of the list
struct node *head = NULL; //A variable to declare the head of the list

void main()
{
    u32 val;       //A variable to store the value of the node data
    u8 choice; //A variable to store the user input

    while (1) //Creating an infinite loop
    {
        /*-------------------------------User Menu-------------------------------*/

        printf("To add node enter 0\n"
               "To print the linked list enter 1\n"
               "To exit enter 2\n"
               "Your Choice: ");

        scanf(" %d", &choice);

        /*-------------------------------Switch case to perform actions-------------------------------*/

        switch (choice)
        {
        case 0: //Add a new node
            printf("Please Enter Node Value: ");
            scanf(" %d", &val);
            add_node(val);
            break;

        case 1: //Print the linked list data
            print_list();
            break;

        case 2: //Exit
            printf("Thank You\nGood Bye");
            exit(1);
            break;

        default: //Invalid choice
            printf("Invalid Choice please try again\n\n");
            break;
        }
    }
}

void add_node(u32 value)
{
    if (list_length == 0) //Checking if the head node exists
    {
        head = (struct node *)malloc(sizeof(struct node)); //Creating head node
        head->data = value;                                //Assigning value to head node data
        head->next = NULL;                                 //Assigning NULL to head node next link
        list_length++;                                     //Incresing the length of the linked list
    }

    else
    {
        struct node *current = (struct node *)malloc(sizeof(struct node)); //Creating new node
        struct node *ptr = head;                                           //Assigning a pointer to iterate through the linked list

        current->data = value; //Assigning value to current node data
        current->next = NULL;  //Assigning NULL to current node next link

        while (ptr->next != NULL) //Iterating through the linked list till the last node
        {
            ptr = ptr->next; //Moving pointer to next node
        }
        ptr->next = current; //Linking to last nodes
        list_length++;       //Increasing the length of the linked list
    }

    printf("Node Added Thank You\n\n"); //Printing out a message
}

void print_list()
{
    if (list_length > 0) //Checking if the list is not empty
    {
        struct node *ptr = head; //Assigning a pointer to iterate through the linked list
        u16 node_num = 1;        //A variable to track the number of nodes in the linked list

        printf("\n\n-------------------------\n");

        while (ptr->next != NULL) //Iterating through the linked list till the last node
        {
            printf("Node Number %d = %d\n", node_num, ptr->data); //Printing data inside the node
            ptr = ptr->next;                                      //Moving pointer to next node
            node_num++;                                           //Increasing the number of nodes in the linked list
        }

        printf("Node Number %d = %d\n", node_num, ptr->data); //Printing data inside the last node

        printf("-------------------------\n\n");
    }

    else
    {
        printf("\n\n-------------------------\n"
               "List is Empty\n"
               "-------------------------\n\n");
    }
}