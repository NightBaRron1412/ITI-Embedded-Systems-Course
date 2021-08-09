//Libraries including
#include <stdio.h>

void main() {
    //Variables decleration
    int x =10;

    //Printing the variable values
    printf("X before change is: %d\n", x);

    //Defining a pointer to variable
    int *ptr = &x;

    //Changing variable value through a pointer
    *ptr = 20;

    //Printing the variable value after change
    printf("X after change is: %d\n", x);

}