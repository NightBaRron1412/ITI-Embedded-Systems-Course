#include <stdio.h>     //including standard input/output library.
#include <stdlib.h>    //including standard library
#include "Std_Types.h" // including standard types

void add_node(u32 value);              //Prototype of a function that adds a new node
void print_list();                     //Prototype of a function that prints the data inside the linked list
void delete_node(u16 pos);             //Prototype of a function that deletes a node at a given position
void add_node_pos(u16 pos, u32 value); //Prototype of a function that adds a new node at a given position

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
    u8 choice = 0; //A variable to store the user input
    u16 pos;       //A variable to store the user input for the position of the node

    while (1) //Creating an infinite loop
    {
        /*-------------------------------User Menu-------------------------------*/

        printf("To add node at the end enter            0\n"
               "To add node at a certain position enter 1\n"
               "To print the linked list enter          2\n"
               "To delete a node from the list enter    3\n"
               "To exit enter                           4\n"
               "Your Choice: ");

        scanf(" %d", &choice);

        /*-------------------------------Switch case to perform actions-------------------------------*/

        switch (choice)
        {
        case 0: //Add a new node at the end of the list
            printf("Please Enter Node Value: ");
            scanf(" %d", &val);
            add_node(val);
            break;

        case 1: //Add a new node at the certain position of the list
            printf("Please Enter Node Value: ");
            scanf(" %d", &val);
            printf("Please Enter New Node Position: ");
            scanf(" %d", &pos);
            add_node_pos(pos, val);
            break;

        case 2: //Print the linked list data
            print_list();
            break;

        case 3: //Delete a node from the linked list
            printf("Please Enter Node Position to delete: ");
            scanf(" %d", &pos);
            delete_node(pos);
            break;

        case 4: //Exit
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

        printf("-------------------------\n");

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
        printf("-------------------------\n"
               "List is Empty\n"
               "-------------------------\n\n");
    }
}

void delete_node(u16 pos)
{
    struct node *current = head; //Assigning a pointer to iterate through the linked list and point to the specified node
    struct node *prev = head;    //Assigning a pointer to iterate through the linked list and point to the previous node

    if (head == NULL) //}Checking if list is empty
    {
        printf("List is Empty\n\n"); //Printing out information
    }

    else if (pos > list_length) //Checking if position is out of range
    {
        printf("Position out of range\n\n"); //Printing out information
    }

    else if (pos == 1) //Deleting the head node
    {
        head = current->next; //Moving the head pointer to next node
        free(current);        //Delteting the node
        current = NULL;       // Deleting pointer

        list_length--; //Decreasing the number of nodes in the linked list

        printf("Node deleted\n\n"); //Printing out information
    }

    else //Deleting the node at the specified position
    {
        for (u16 i = 1; i < pos; i++) //Iterating through the linked list to get current & prev pointers in place
        {
            prev = current;          //Moving prev to the previous node to the specified one
            current = current->next; //Moving the current to the specified node
        }

        prev->next = current->next; //letting the node previous to the specified point to the one after it
        free(current);              //Deleting the specified node
        current = NULL;             // Delteting current pointer

        list_length--; //Decreasing the number of nodes in the linked list

        printf("Node deleted\n\n"); //Printing out information
    }
}
void add_node_pos(u16 pos, u32 value)
{
    if (pos < 1 || pos > list_length + 1) //Checking if the position is out of range
    {
        printf("Invalid Position\n\n"); //Printing out information
    }

    else if (pos == 1) //Checking if adding node at the beginning of the list
    {
        struct node *current = (struct node *)malloc(sizeof(struct node)); //Creating new node                                         //Assigning a pointer to iterate through the linked list

        current->data = value; //Assigning value to current node data
        current->next = head;  //Linking current node to head
        head = current;        //Moving head to new node

        list_length++; //Increasing the length of the linked list

        printf("Node added Thank You\n\n"); //Printing out information
    }

    else if (pos == list_length + 1) //Checking if adding node at the end of the list
    {
        add_node(value); //Calling add_node function to add the node to the end of the list
    }

    else
    {
        struct node *current = (struct node *)malloc(sizeof(struct node)); //Creating new node                                         //Assigning a pointer to iterate through the linked list
        struct node *ptr = head;                                           //Assigning a pointer to iterate through the list

        current->data = value; //Assigning value to current node data

        //Moving the pointer to the previous node to the specified position
        for (u16 i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }

        current->next = ptr->next; //Assigning the link of the node next to position to current node
        ptr->next = current;       //Linking the previous node to the new node

        list_length++; //Increasing the length of the linked list

        printf("Node added Thank You\n\n"); //Printing out information
    }
}