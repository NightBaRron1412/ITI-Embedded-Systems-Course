//Libraries including
#include <stdio.h>
void main (){
    //Variables declaration
    int a;
    int b;
    //User input
	printf("Enter the first number: ");
    scanf(" %d", &a);
    printf("\nEnter the second number: ");
    scanf(" %d", &b);
    //Printing values
    printf("\na + b = %d\n",a + b);
    printf("\na - b = %d\n",a - b);
    printf("\na * b = %d\n",a * b);
    printf("\na / b = %d\n",a / b);
    printf("\na %% b = %d\n",a % b);
    printf("\na++ = %d\n",a++);
    printf("\n++b = %d\n",++b);
    printf("\na-- = %d\n",a--);
    printf("\n--b = %d\n",--b);
}