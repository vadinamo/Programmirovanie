#include <stdio.h>
#include <math.h>
#include "main.h"

void inputCheck(float *enteredNumber)
{
    while (!scanf("%f", enteredNumber))
    {
        while (getchar() != '\n') {}
        printf("\nError!\n\nEnter your natural number.\n");
    }
}

int factorialCalc(int number)
{
    if (number < 0) return 0;
    else if (number == 0) return 1;
    else return number * factorialCalc(number - 1);
}

#ifndef TESTING

int main()
{
    float x, e, result, formula = 0;
    int n = 1;
    printf("x=");
    inputCheck(&x);
    printf("e=");
    inputCheck(&e);
    do
    {
        formula += (pow(-1, n - 1) * pow(x, 2 * n - 1)) / factorialCalc(2 * n - 1);
        result = fabs(sin(x) - formula);
        n++;
    } while (result > e);
    printf("Result : %d", --n);
}

#endif