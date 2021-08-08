//Including Libraries
#include <stdio.h>

//Function declarations
int Get_Max(int num1, int num2);

void main()
{
    //Variables decleration
    int num1, num2;

    //user input
    printf("Please enter Value 1: ");
    scanf(" %d", &num1);

    printf("Please enter Value 2: ");
    scanf(" %d", &num2);

    //Function call
    printf("The maximum value is %d", Get_Max(num1, num2));
}

//Searching for max number
int Get_Max(int num1, int num2)
{
    int max;
    if (num1 > num2)
    {
        max = num1;
    }

    else if (num1 < num2)
    {
        max = num2;
    }

    return max;
}
