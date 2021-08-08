//Including Libraries
#include <stdio.h>

void main()
{
    //Variables decleration
    int arr[10];

    //for loop for numbers from 1-10
    for (int i = 0; i < 10; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr[i]);
    }

    //Priniting the values in reversed order
    printf("The values in reversed order\n");

    for (int i = 9; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
}