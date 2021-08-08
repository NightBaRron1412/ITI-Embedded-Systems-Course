//Libraries including
#include <stdio.h>

int ops(int op_id);
void main()
{

    //variables decleration
    int op_id;

    //user operation id input
    printf("Please enter the operation ID: ");
    scanf(" %d", &op_id);

    //Function Calling
    printf("The result is: %d", ops(op_id));
}

//Operations Function
int ops(int op_id)
{
    int operand1, operand2, result;
    switch (op_id)
    {

    //Addition operation
    case 1:
        printf("Please enter first operand: ");
        scanf(" %d", &operand1);
        printf("Please enter second operand: ");
        scanf(" %d", &operand2);
        result = operand1 + operand2;
        break;

    //Subtraction operation
    case 2:
        printf("Please enter first operand: ");
        scanf(" %d", &operand1);
        printf("Please enter second operand: ");
        scanf(" %d", &operand2);
        result = operand1 - operand2;
        break;

    //Not operation
    case 7:
        printf("Please enter operand: ");
        scanf(" %d", &operand1);
        result = ~operand1;
        break;

    //Xor operation
    case 8:
        printf("Please Enter first operand: ");
        scanf(" %d", &operand1);
        printf("Please Enter second operand: ");
        scanf(" %d", &operand2);
        result = operand1 ^ operand2;
        break;

    //Reminder operation
    case 9:
        printf("Please Enter first operand: ");
        scanf(" %d", &operand1);
        printf("Please Enter second operand: ");
        scanf(" %d", &operand2);
        result = operand1 % operand2;
        break;

    //Increment operation
    case 10:
        printf("Please enter operand: ");
        scanf(" %d", &operand1);
        result = operand1++;
        break;
    }
}