#include <assert.h>
#include <stdio.h>
#include "main.h"

float perimСalculation_test()
{
    assert(perimСalculation(2, 3, 4) == 9);
    return 1;
}

float circumscribedRadius_test()
{
    assert(circumscribedRadius(10, 6, 8, 24) == 5);
    return 1;
}

float inscribedRadius_test()
{
    assert(inscribedRadius(3, 4, 5, 6) == 1);
    return 1;
}

#undef main

int main()
{
    perimСalculation_test();
    circumscribedRadius_test();
    inscribedRadius_test();
    printf("Test succesfully completed");
    return 0;
}
