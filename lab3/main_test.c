#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main.h"

int maxNumber_test()
{
    assert(maxNumber(502, 12) == 502);
    assert(maxNumber(28,225) == 225);
    return 1;
}

int elementCalculation_test()
{
    assert(elementCalculation(1, 2, 3, 4, 5) == 3);
    assert(elementCalculation(20,17,42,55,1) == 39);
    assert(elementCalculation(13,42,26,28,11) == 15);
    return 1;
}

#undef main

int main()
{
    maxNumber_test();
    elementCalculation_test();
    printf("Test succesfully completed");
    return 0;
}