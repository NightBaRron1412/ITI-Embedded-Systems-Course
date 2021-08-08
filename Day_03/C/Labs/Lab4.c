//Including Libraries
#include <stdio.h>

//Functions declaration
long int factorial(int n);

void main()
{
    //Local variables declarations
    int n;
    printf("Please enter number: ");
    scanf(" %d", &n);

    //calling function
    printf("The factorial of %d is %d", n, factorial(n));
}

//A recursive function to calculate the factorial of a number
long int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return (n * factorial(n - 1));
}