//Including Libraries
#include <stdio.h>

// Declaration of variables
int num;

void main(){
    //User input
    printf("Please enter number: ");
    scanf(" %d", &num);

    //condition check
    if((num % 2) == 0){
        printf("Number is Even");
    }
    else{
        printf("Number is Odd");
    }
}