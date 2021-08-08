//Libraries including
#include <stdio.h>

void main()
{
    //Variables decleration
    int arr_len = 10, search, found = 0;
    int arr[arr_len];

    //For loop for numbers from 1-10
    for (int i = 0; i < arr_len; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr[i]);
    }

    //Asking user for value to search for
    printf("Please Enter number to search for: ");
    scanf(" %d", &search);

    //Using linear search algorithm
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] == search)
        {
            found++;
        }
    }

    //Printing result
    if (found > 0)
    {
        printf("Value Exists %d times\n", found);
    }

    else
    {
        printf("Value Does Not Exist");
    }
}
