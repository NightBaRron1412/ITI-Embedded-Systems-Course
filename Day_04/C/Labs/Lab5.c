//Including Libraries
#include <stdio.h>

//Function declaration
void scalar(int arr1[], int arr2[], int *scalar_res);

void main()
{
    //Variables decleration
    int arr1[5], arr2[5], scalar_res[5];

    //for loop for getting numbers form the user
    for (int i = 0; i < 5; i++)
    {
        printf("Please Enter number %d of first array: ", i);
        scanf(" %d", &arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Please Enter number %d of second array: ", i);
        scanf(" %d", &arr2[i]);
    }

    //Calling the function
    scalar(arr1, arr2, scalar_res);

    //Printing the result
    printf("Scalar multiplication result is: \n");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d\n", scalar_res[i]);
    }
}

//Function to calculate the Scalar multiplication of 2 given arrays
void scalar(int arr1[], int arr2[], int *scalar_res)
{
    for (int i = 0; i < 5; i++)
    {
        *(scalar_res + i) = (arr1[i] * arr2[i]);
    }
}