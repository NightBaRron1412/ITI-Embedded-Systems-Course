//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int n, sum = 0;
    float avg = 0;

    printf("Enter the 10 numbers: \n");

    //for loop for numbers from 1-10
    for(int i = 1; i <= 10; i++){
        printf("Enter number %d: ", i);
        scanf(" %d", &n);
        sum +=n;
    }
    avg = sum/10;
    printf("The sum of the 10 numbers is = %d", sum);
    printf("\nThe Average = %f", avg);


}