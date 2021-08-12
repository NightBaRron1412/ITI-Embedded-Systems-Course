//Headers including
#include <stdio.h>
#include "Std_Types.h"

//Defining a new structure type
typedef struct employees
{
    u16 salary;
    u16 bonus;
    u16 deduction;
} st_employee;

//Creating employee objects
st_employee emp1;
st_employee emp2;
st_employee emp3;

void main()
{
    //Declaration of variables
    u32 total_s = 0, total_b = 0, total_d = 0, total_v = 0;

    //Getting information for first employee
    printf("Please Enter Ahmed Salary: ");
    scanf(" %d", &emp1.salary);
    printf("Please Enter Ahmed Bonus: ");
    scanf(" %d", &emp1.bonus);
    printf("Please Enter Ahmed Deduction: ");
    scanf(" %d", &emp1.deduction);

    //Getting information for second employee
    printf("Please Enter Amr Salary: ");
    scanf(" %d", &emp2.salary);
    printf("Please Enter Amr Bonus: ");
    scanf(" %d", &emp2.bonus);
    printf("Please Enter Amr Deduction: ");
    scanf(" %d", &emp2.deduction);

    //Getting information for third employee
    printf("Please Enter Waleed Salary: ");
    scanf(" %d", &emp3.salary);
    printf("Please Enter Waleed Bonus: ");
    scanf(" %d", &emp3.bonus);
    printf("Please Enter Waleed Deduction: ");
    scanf(" %d", &emp3.deduction);

    //Calculating total value
    total_s = emp1.salary + emp2.salary + emp3.salary;
    total_b = emp1.bonus + emp2.bonus + emp3.bonus;
    total_d = emp1.deduction + emp2.deduction + emp3.deduction;
    total_v = total_s + total_b - total_d;

    //Printing value to be supplied by financial team
    printf("Total Value Needed is %d", total_v);
}