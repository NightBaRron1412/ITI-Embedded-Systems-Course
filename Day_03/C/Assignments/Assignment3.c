//Libraries including
#include <stdio.h>

void main()
{
    //Variables decleration
    int arr_len = 10;
    int arr[arr_len];

    //For loop for numbers from 1-10
    for (int i = 0; i < arr_len; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr[i]);
    }

    // Finding maximum
    int max = arr[0];

    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Finding Minimum
    int min = arr[0];

    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    //Printing results
    printf("The maximum value is: %d\n", max);
    printf("The minimum value is: %d", min);
}
