//Libraries including
#include <stdio.h>
void main (){
    //Variables declaration
    int integer_num;
    float float_num;
    char character;
    //User input
	printf("Enter an integer value: ");
    scanf(" %d", &integer_num);
    printf("\nEnter a float value: ");
    scanf(" %f", &float_num);
    printf("\nEnter a character value: ");
    scanf(" %c", &character);
    //Printing values
    printf("\nThe integer value you entered is: %d\n",integer_num);
    printf("\nThe float value you entered is: %.2f\n",float_num);
    printf("\nThe character value you entered is: %c\n",character);

}