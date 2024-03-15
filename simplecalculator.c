#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "simplecalculator.h"
#include "operations.h"

int main()
{
    printf("Simple calculator\n");
    
    bool ok = true;
    int result = 0;

    while(ok)
    {
        ok = prompt(&result);
        if(ok)
        {
            printf("Result: %d\n", result);
        }
    }

    return 0;
}

bool prompt(int *ret)
{
    char operation = getoperation();
    int operand1 = getoperand("1");
    int operand2 = getoperand("2");

    int result;

    switch(operation)
    {
        case 'a':
            result = opaddition(operand1, operand2);
            break;
        case 's':
            result = opsubtraction(operand1, operand2);
            break;
        case 'm':
            result = opmultiplication(operand1, operand2);
            break;
        case 'd':
            result = opdivision(operand1, operand2);
            break;
        default:
            return false;
    }
    *ret = result; 
    return true;
}

char getoperation()
{
    char choosen = '\0';
    printf("\nChoose operation:\n"
          "[a] Addition\n"
          "[s] Subtraction\n"
          "[m] Multiplication\n"
          "[d] Division\n"
          ":");
    (void)scanf(" %c", &choosen);
    return choosen;
}

int getoperand(const char *which)
{
    int operand = 0;
    printf("Operand %s: ", which);
    (void)scanf(" %d", &operand);
    return operand;
}