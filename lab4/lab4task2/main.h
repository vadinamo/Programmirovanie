#ifndef LAB4TASK2_MAIN_H
#define LAB4TASK2_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#define N 128

int length(const char string[N]);
int bracket(char text[N], int begin_num);
int brace(char text[N], int begin_num);
int sq_bracket(char text[N], int begin_num);
int bracket_check(char text[N]);

#endif
