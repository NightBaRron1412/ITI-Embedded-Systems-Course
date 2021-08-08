//Including Libraries
#include <stdio.h>

//Function declarations
void swap();

//Variables decleration
int x, y;

void main()
{

    //user input
    printf("X before swap = ");
    scanf(" %d", &x);

    printf("Y before swap = ");
    scanf(" %d", &y);

    //Function call
    swap(x, y);

    //Printing values after swap
    printf("X after swap = %d", x);
    printf("\nY after swap = %d", y);
}

//Swapping 2 variables
void swap()
{
    x = x + y;
    y = x - y;
    x = x - y;
}
