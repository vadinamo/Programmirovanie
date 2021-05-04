#ifndef LAB5_MAIN_H
#define LAB5_MAIN_H
#define NMAX 128
#include <stdio.h>
#include "stdlib.h"

struct stack {
    char data[NMAX];
    int top;
};

int Add(struct stack *stk, char symbol);
int Length(const char *string);
int Palindrome(struct stack *stk);
int ToStack(struct stack *stk, char *string);

#endif
