/*Напишите программу, которая использует стек для того, чтобы определить, является ли
  строка палиндромом (т.е. одинаково читается справа налево и слева направо). Программа
  должна игнорировать пробелы и знаки пунктуации.
*/
#include "main.h"

int Add(struct stack *stk, char symbol) {
    if(stk -> top < NMAX) {
        stk -> data[stk -> top] = symbol;
        stk -> top++;
        return 1;
    }

    else {
        printf("Стек полон!\n");
        return 0;
    }
}

int Length(const char *string) {
    int l = 0;
    while(string[l] != '\0') {
        l++;
    }
    return l;
}

int Palindrome(struct stack *stk) {
    int i = stk -> top - 2;
    int j = 0;

    while(i >= 0 && j < stk -> top)
    {
        if(stk -> data[i] == stk -> data[j]);
        else return 0;
        i--;
        j++;
    }

    return 1;
}
int ToStack(struct stack *stk, char *string) {
    int i;
    for(i = 0; i < Length(string); i++) {
        if(string[i] != ',' && string[i] != '.' && string[i] != ' ' &&
           string[i] != '!' && string[i] != '?' && string[i] != ';' &&
           string[i] != ':') {
            Add(stk, string[i]);
        }
    }

    switch (Palindrome(stk)) {
        case 0:
            return 0;

        case 1:
            return 1;
    }
    return 0;
}

#ifndef TESTING

int main() {
    struct stack *stk;
    char *str;

    stk = (struct stack*)malloc(sizeof(struct stack));
    str = (char*)malloc(1 * sizeof(char));
    fgets(str, 255, stdin);

    switch (ToStack(stk, str)) {
        case 0:
            printf("Ваша строка не является палиндромом.");
            break;

        case 1:
            printf("Ваша строка является палиндромом.");
            break;
    }
}

#endif
