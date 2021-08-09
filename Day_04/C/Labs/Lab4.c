//Including Libraries
#include <stdio.h>

void main()
{
    //Variables decleration
    int arr[10];
    int sum;
    int *ptr = arr;

    //for loop for getting numbers form the user
    for (int i = 0; i < 10; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr[i]);
    }

    for (int i = 0; i < 10; i++){
        sum += *(ptr + i);
    }
    //Printing the result
    printf("The summation result is: %d", sum);
}