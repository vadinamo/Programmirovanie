#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int maxNumber(int firstNumber, int secondNumber)
{
    if (firstNumber > secondNumber) return firstNumber;
    else return secondNumber;
}

void inputCheck(int *enteredNumber)
{
    while (!scanf("%d", enteredNumber) || *enteredNumber < 0)
    {
        while (getchar() != '\n') {}
        printf("\nError!\n\nEnter your natural number.\nm=");
    }
    printf("\n");
}

void matrixSize(int *linesNumber, int *columnsNumber)
{
    printf("Enter your matrix size a(m, n)\nm=");
    inputCheck(linesNumber);
    printf("n=");
    inputCheck(columnsNumber);
}

void elementCoordinates(int *elementLine, int *elementColumn)
{
    printf("Enter your element coordinates a[k, l]\nk=");
    inputCheck(elementLine);
    --*elementLine;
    printf("l=");
    inputCheck(elementColumn);
    --*elementColumn;
}

int elementCalculation(int i, int j, int elementLine, int elementColumn, int arrayElement)
{
    arrayElement = 1 + maxNumber(abs(i-elementLine), abs(j-elementColumn));
    return arrayElement;
}

#ifndef TESTING

int main(void)
{
    int linesNumber, columnsNumber, elementLine, elementColumn, i, j;
    int **array;

    matrixSize(&linesNumber, &columnsNumber);
    array = (int**) malloc(linesNumber * sizeof(int*));

    for (i = 0; i < linesNumber; i++) {
        array[i] = (int*) malloc(columnsNumber * sizeof(int));
    }

    elementCoordinates(&elementLine, &elementColumn);

    for (i = 0; i < linesNumber; ++i)
    {
        for (j = 0; j < columnsNumber; ++j)
        {
            printf("%d ", elementCalculation(i, j, elementLine, elementColumn, array[i][j]));
        }
        printf("\n");
    }
}

#endif