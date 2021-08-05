//Including Libraries
#include <stdio.h>

void main(){
    //Variables decleration
    int user, id, password, tries = 1;

    //User ID input
    printf("Please enter your ID: ");
    scanf(" %d", &id);

    //ID & Password Check
    switch (id){

        case 1234:
        printf("Please enter your Password: ");
        scanf(" %d", &password);
        
        while(tries < 3){

            if (password == 7788){
                printf("Welcome Ahmed");
                break;
            }

            else{
                printf("Try again: ");
                scanf(" %d", &password);;
            }

            tries++;
        }
        printf("Incorrect password for 3 times. No more tries");
        break;

        case 5678:
        printf("Please enter your Password: ");
        scanf(" %d", &password);
        
        while(tries < 3){

            if (password == 5566){
                printf("Welcome Amr");
                break;
            }

            else{
                printf("Try again: ");
                scanf(" %d", &password);;
            }

            tries++;
        }
        printf("Incorrect password for 3 times. No more tries");
        break;

        case 9870:
        printf("Please enter your Password: ");
        scanf(" %d", &password);
        
        while(tries < 3){

            if (password == 1122){
                printf("Welcome Ahmed");
                break;
            }

            else{
                printf("Try again: ");
                scanf(" %d", &password);;
            }

            tries++;
        }
        printf("Incorrect password for 3 times. No more tries");
        break;

        default:
            printf("You are not registered");
            break;

    }

}
