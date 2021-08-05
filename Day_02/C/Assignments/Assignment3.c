//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int num1, num2, num3, max;

    //user input
    printf("Enter Number 1: ");
    scanf(" %d", &num1);
    
    printf("Enter Number 2: ");
    scanf(" %d", &num2);

    printf("Enter Number 3: ");
    scanf(" %d", &num3);

    //Searching for max number
    if (num1 > num2) {
        if (num1 > num3){
            printf("Maximum number is %d", num1);
        }
        else {
            printf("Maximum number is %d", num3);
        }
    }

    else if (num1 < num2) {
        if (num2 > num3){
            printf("Maximum number is %d", num2);
        }
        else {
            printf("Maximum number is %d", num3);
        }
    }
}