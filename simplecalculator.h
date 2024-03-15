#include <stdbool.h>

bool prompt(int *result);
char getoperation();
int getoperand(const char *which);
int opaddition(int op1, int op2);
int opsubtraction(int op1, int op2);
int opmultiplication(int op1, int op2);
int opdivision(int op1, int op2);