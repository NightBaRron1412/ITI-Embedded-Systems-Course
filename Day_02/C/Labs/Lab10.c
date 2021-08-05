//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int num;

    //User input
        printf("Enter the number to display its multiplication table: ");
        scanf(" %d", &num);
        printf("\n");

    //Printing multiplication table
    for(int i = 1; i<= 10; i++){
        printf("%d x %d = %d", num, i, num*i);
        printf("\n");
    }
}