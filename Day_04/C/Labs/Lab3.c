//Headers including
#include <stdio.h>

//Function prototype
void calc(int *sum, int *sub, int num1, int num2);
void main()
{

    //Variables decleration
    int sum, sub, num1, num2;

    //User input
    printf("Please Enter Value 1: ");
    scanf(" %d", &num1);
    printf("Please Enter Value 2: ");
    scanf(" %d", &num2);

    //Function calling
    calc(&sum, &sub, num1, num2);

    //Printing result
    printf("The result of summation: %d\n", sum);
    printf("The result of substraction: %d", sub);
}

//Function to make required calculations
void calc(int *sum, int *sub, int num1, int num2)
{
    *sum = num1 + num2;
    *sub = num1 - num2;
}