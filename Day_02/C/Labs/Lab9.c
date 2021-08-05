//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int answer;

    //User Answer
        printf("Enter the answer of 4 x 3: ");
        scanf(" %d", &answer);

    //Answer Check
        while(answer != 12){
        printf("Wrong answer please try again: ");
        scanf(" %d", &answer);
        }

        printf("Thank You!");
}