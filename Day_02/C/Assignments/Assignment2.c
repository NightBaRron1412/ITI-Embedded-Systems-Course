//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int id, password;

    //User ID input
    printf("Please enter your ID: ");
    scanf(" %d", &id);

    //Check ID
    if (id == 800168303){
        //User Password input
        printf("Please enter your Password: ");
        scanf(" %d", &password);

        if (password == 1412){
            printf("Amir Shetaia");
        }

        else{
            printf("Incorrect password");
        }
    }

    else{
        printf("Incorrect id");
    }
}