//Including Libraries
#include <stdio.h>

//Function declaration
void BS(int *arr, int arr_len);

void main()
{
    //Variables decleration
    int arr_len = 10;
    int arr1[arr_len];

    //for loop for numbers from 1-10
    for (int i = 0; i < arr_len; i++)
    {
        printf("Please Enter number %d: ", i);
        scanf(" %d", &arr1[i]);
    }

    //Calling the function
    BS(arr1, arr_len);

    //Priniting the values of the array after sorting
    printf("Values after sorting are:\n");

    for (int i = 0; i < arr_len; i++)
    {
        printf("%d\n", arr1[i]);
    }
}

//Function to sort a given array using Bubble Sort algorithm
void BS(int *arr, int arr_len)
{
    //Bubble sorting the array
    for (int i = 0; i < arr_len - 1; i++)
    {
        for (int j = 0; j < arr_len - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                //swapping elements
                *(arr + j) = *(arr + j + 1) + *(arr + j);
                *(arr + j + 1) = *(arr + j) - *(arr + j + 1);
                *(arr + j) = *(arr + j) - *(arr + j + 1);
            }
        }
    }
}