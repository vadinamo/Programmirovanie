//
#ifndef main_h
#define main_h

#include <stdio.h>
#include <math.h>

void inputCheck(float *enteredNumber);
void triangleType(float AB, float BC, float AC);
void lengthCalculation(float X1, float Y1, float Y2, float X2, float *side);
float perimeterСalculation(float AB, float BC, float AC);
float circumscribedRadius(float AB, float BC, float AC, float S);
float inscribedRadius(float AB, float BC, float AC, float S);

#endif /* main_h */
