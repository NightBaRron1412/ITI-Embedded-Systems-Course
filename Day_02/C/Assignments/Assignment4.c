//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int num1, num2;

    while(1){
        //user input
        printf("Please enter first number: ");
        scanf(" %d", &num1);
        
        printf("Please enter second number: ");
        scanf(" %d", &num2);

        printf("The result is %d\n\n", num1 + num2);
    }
}