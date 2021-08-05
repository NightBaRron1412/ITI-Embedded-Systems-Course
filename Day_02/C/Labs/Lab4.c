//Including Libraries
#include <stdio.h>

// Declaration of variables
int grade;

void main(){
    //User input
    printf("Please enter number: ");
    scanf(" %d", &grade);

    //condition check and statements printing
    if (0 <= grade && grade < 50){
        printf("Your rating is Failed");
    }
    else if (50 <= grade && grade < 65){
        printf("Your rating is Normal");
    }
    else if (65 <= grade && grade < 75){
        printf("Your rating is Good");
    }
    else if (75 <= grade && grade < 85){
        printf("Your rating is Very Good");
    }
    else if (85 <=  grade){
        printf("Your rating is Excellent");
    }
}