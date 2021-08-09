//Headers including
#include <stdio.h>

//Function prototype
int sum(int *x, int *y);

void main()
{
    //Variables decleration
    int x, y;

    //User input
    printf("Please Enter Value 1: ");
    scanf(" %d", &x);
    printf("Please Enter Value 2: ");
    scanf(" %d", &y);

    //Passing arguments to function by address and printing the result
    printf("The result is: %d", sum(&x, &y));
}

int sum(int *x, int *y)
{
    return *x + *y;
}