//Headers including
#include <stdio.h>
#include "Std_Types.h"

//Defining a new structure type
typedef struct class
{
    u16 id;
    u8 math;
    u8 language;
    u8 physics;
    u8 chemistry;
} Students;

//Creating employee objects & initializing values of STD
Students STD_students[10] = {{8871, 30, 69, 45, 27},
                             {8560, 30, 60, 28, 75},
                             {8086, 44, 95, 22, 39},
                             {8280, 40, 40, 73, 41},
                             {6839, 93, 46, 56, 36},
                             {8799, 50, 99, 95, 74},
                             {6941, 61, 38, 45, 38},
                             {6090, 24, 38, 37, 21},
                             {8119, 15, 56, 35, 77},
                             {1051, 22, 19, 30, 69}};

void main()
{
    //Variables decleration
    u16 id;
    u8 found = 0;

    //User input
    printf("Please Enter Students ID: ");
    scanf(" %d", &id);

    //for loop for accessing STD structure array
    for (u8 i = 0; i < 10; i++)
    {
        if (id == STD_students[i].id)
        {
            printf("Math Grade:      %d\n", STD_students[i].math);
            printf("language Grade:  %d\n", STD_students[i].language);
            printf("Physics Grade:   %d\n", STD_students[i].physics);
            printf("Chemistry Grade: %d\n", STD_students[i].chemistry);
            found = 1;
        }
    }

    //Checking if id found
    if (found != 1)
    {
        printf("Student ID is not correct");
    }
}