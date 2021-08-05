//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int id;

    //User ID input
    printf("Please enter your ID: ");
    scanf(" %d", &id);

    //ID check
    switch(id){
        case 1234:
        printf("Welcome Ahmed");
        break;

        case 5678:
        printf("Welcome Youssef");
        break;

        case 1145:
        printf("Welcome Mina");
        break;

        default:
        printf("Wrong ID");
        break;
    }
    
}