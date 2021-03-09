// Найти все натуральные числа, не превосходящие заданного m, двоичная запись которых представляет собой последовательность единиц. Показать десятичную и двоичную запись этих чисел.
#include <stdio.h>

int main()
{
    int arrayLength, numberRemainder, reservedNumber, unitsNumber, enteredNumber = 0, numberOfValues = 0;
    int binaryNumber [100];
    
    printf("Enter your natural number.\nm=");
    while (!scanf("%d", &enteredNumber) || enteredNumber < 1)
    {
            while (getchar() != '\n') {}
            printf("\nError!\n\nEnter your natural number.\nm=");
    }
    printf("\n");
    
    for (int currentNumber = 1; currentNumber < enteredNumber; currentNumber++)
    {
        unitsNumber = 0;
        arrayLength = 0;
        reservedNumber = currentNumber;
        
        while (currentNumber > 0)
        {
            numberRemainder = currentNumber % 2;
            currentNumber /= 2;
            binaryNumber [arrayLength] = numberRemainder;
            arrayLength++;
        }
        
        for (int i = 0; i < arrayLength; i++)
        {
            if (binaryNumber [i] == 1) unitsNumber++;
        }
        
        if (unitsNumber == arrayLength)
        {
            printf("Performed for: %d\tBinary notation: ", reservedNumber);
            for (int i = 0; i < arrayLength; i++)
            {
                printf("%d ", binaryNumber [i]);
            }
            printf("\n\n");
            numberOfValues++;
        }
        currentNumber = reservedNumber;
    }
    if (numberOfValues == 0) printf("No matching values.\n");
}
