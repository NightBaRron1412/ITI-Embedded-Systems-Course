//Including Libraries
#include <stdio.h>

void main()
{
    //Variables decleration
    int arr[10];
    int sum = 0 , avg = 0;

    //for loop for numbers from 1-10
    for (int i = 0; i < 10; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr[i]);
        sum += arr[i];
    }
    
    avg = sum / 10;
    printf("Sum of array elements = %d", sum);
    printf("\nAverage of array elements = %d", avg);
}