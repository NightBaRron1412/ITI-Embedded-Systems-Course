#include <stdio.h>     //Including the standard input/output library
#include <stdlib.h>    //Including the standard library
#include "Std_Types.h" //Including the standard types header file

void main()
{
    u32 dynarr_len; //Declaring variable for dynamic array length

    //User input
    printf("Please Enter the number of numbers: ");
    scanf(" %d", &dynarr_len);

    u32 *dynarr_ptr = (u32 *)malloc(sizeof(u32) * dynarr_len); //Dynamically allocating space in memory

    //Checking for successful allocating
    if (dynarr_ptr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    //for loop for iterating through dynarr
    for (u32 i = 0; i < dynarr_len; i++)
    {
        printf("Please Enter number %d: ", i + 1);
        scanf(" %d", &dynarr_ptr[i]);
    }

    //Bubble sorting the array
    for (u32 i = 0; i < dynarr_len - 1; i++)
    {
        for (u32 j = 0; j < dynarr_len - i - 1; j++) 
        {
            if (dynarr_ptr[j] > dynarr_ptr[j + 1])
            {
                //swapping elements
                dynarr_ptr[j] = dynarr_ptr[j + 1] + dynarr_ptr[j];
                dynarr_ptr[j + 1] = dynarr_ptr[j] - dynarr_ptr[j + 1];
                dynarr_ptr[j] = dynarr_ptr[j] - dynarr_ptr[j + 1];
            }
        }
    }

    //Priniting the values of the array after sorting
    printf("Values after sorting are:\n");

    for (u32 i = 0; i < dynarr_len; i++)
    {
        printf("%d\n", dynarr_ptr[i]);
    }
}