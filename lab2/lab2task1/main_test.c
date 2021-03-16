#include <assert.h>
#include <stdio.h>
#include "main.h"

float perimeterCalc_test()
{
    assert(perimeterCalc(2, 3, 4) == 9);
    return 1;
}

float circumscribedRadius_test()
{
    assert(circumscribedRadius(10, 6, 8, 24) == 5);
    return 1;
}

float inscribedRadius_test()
{
    assert(circumscribedRadius(3, 4, 5, 6) == 1);
    return 1;
}

#undef main

int main()
{
    perimeterCalc_test();
    circumscribedRadius_test();
    inscribedRadius_test();
    printf("Test succesfully completed");
    return 0;
}
