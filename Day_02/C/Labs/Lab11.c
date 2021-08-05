//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int num, fact = 1;

    //User input
        printf("Enter an integer: ");
        scanf(" %d", &num);

    //Calculating factorial
    if (num == 0){
        fact = 1;
    }
    else{
        for(int i = num; i > 1; i--){
        fact = fact * i;
    }
    }

    //printing factorial
    printf("Factorial= %d", fact);
}