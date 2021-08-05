//Libraries including
#include <stdio.h>
void main(){
    //Variables decletaion
   int i, space, rows, k = 0;

    //User input
    printf("Please enter the height of the pyramid: ");
    scanf(" %d", &rows);

    //Printing the pyramid
    for (i = 1; i <= rows; ++i, k = 0) {
        for (space = 1; space <= rows - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("* ");
            ++k;
        }
        printf("\n");
    }

}