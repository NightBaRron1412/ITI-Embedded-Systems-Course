//Libraries including
#include <stdio.h>

void main()
{
    //Variables decleration
    int arr_len = 10, search;
    int arr[arr_len];
    int first = 0, last = arr_len - 1;
    int middle = (first + last) / 2;

    //For loop for numbers from 1-10
    for (int i = 0; i < arr_len; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr[i]);
    }

    //Asking user for value to search for
    printf("Please Enter number to search for: ");
    scanf(" %d", &search);

    //Bubble sorting the array
    for (int i = 0; i < arr_len - 1; i++)
    {
        for (int j = 0; j < arr_len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                //swapping elements
                arr[j] = arr[j + 1] + arr[j];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }

    //Using binary search algorithm
    while (first <= last)
    {
        if (arr[middle] == search)
        {
            printf("Value Found");
            break;
        }

        else if (arr[middle] < search)
        {
            first = middle + 1;
        }

        else
        {
            last = middle - 1;
        }

        middle = (first + last) / 2;
    }
    
    if (first > last)
    {
        printf("Value Does Not Exist");
    }
}
