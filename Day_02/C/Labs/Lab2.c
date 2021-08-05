//Including Libraries
#include <stdio.h>

// Declaration of variables
int salary, working_hours;

void main(){
    //User input
    printf("Please enter your working hours: ");
    scanf(" %d", &working_hours);

    //Salary calculation

    salary = working_hours * 50;

    //10% deduction condition check
    if(working_hours < 40){
        salary = (salary - (0.1 * salary));
    }

    //Printing Statements
    printf("Your salary is %d", salary);
}