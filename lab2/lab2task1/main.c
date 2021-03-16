#include <stdio.h>
#include <math.h>
#include "main.h"

void inputCheck(float *enteredNumber)
{
    while (!scanf("%f", enteredNumber))
    {
        while (getchar() != '\n') {}
        printf("\nError!\n\nEnter your natural number.\nm=");
    }
}

void triangleType(float AB, float BC, float AC)
{
    float biggest, side1, side2;
    if (AB > BC && AB > AC)
    {
        biggest = AB;
        side1 = BC;
        side2 = AC;
    }
    else if (BC > AB && BC > AC)
    {
        biggest = BC;
        side1 = AB;
        side2 = AC;
    }
    else
    {
        biggest = AC;
        side1 = AB;
        side2 = BC;
    }

    if (AB == BC && AB == AC)
    {
        printf("Your triangle is regular.\n\n");
    }
    else if ((AB == BC && AB != AC) || (AB == AC && AB != BC) || (BC == AC && BC != AB))
    {
        printf("Your triangle is isosceles.\n\n");
    }
    else if (biggest == (pow(side1, 2) + pow(side2, 2)))
    {
        printf("Your triangle is rectangular.\n\n");
    }
    else
    {
        printf("Your triangle is arbitrary.\n\n");
    }
}

void lengthCalculation(float X1, float Y1, float Y2, float X2, float *side)
{
    *side = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
}

float PCalc(float AB, float BC, float AC)
{
    float Perimeter = AB + BC + AC;
    return Perimeter;
}

void areaCalculation(float AB, float BC, float AC, float *Square)
{
    float p;
    p = (AB + BC + AC) / 2;
    *Square = sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

float circumscribedRadius(float AB, float BC, float AC, float S)
{
    float R = (AB * BC * AC) / (4 * S);
    return R;
}

float inscribedRadius(float AB, float BC, float AC, float S)
{
    float r = (2 * S) / (AB + BC + AC);
    return r;
}

#ifndef TESTING

int main()
{
    char exit = ' ';
    printf("Triangle calculator v1.0\nDeveloped by Vadim Yur'ev, 053502, 27 on the list.\n__________________________________________________\n");
    while (exit != 'y' && exit != 'Y')
    {
        float AB, BC, AC, aX, aY, bX, bY, cX, cY, S;
        printf("\n");
        printf("Enter the coordinates of the vertices of the triangle.\n");
        printf("A coordinates:\nX=");
        inputCheck(&aX);
        printf("Y=");
        inputCheck(&aY);
        printf("B coordinates:\nX=");
        inputCheck(&bX);
        printf("Y=");
        inputCheck(&bY);
        printf("C coordinates:\nX=");
        inputCheck(&cX);
        printf("Y=");
        inputCheck(&cY);
        printf("\n");

        lengthCalculation(aX, aY, bX, bY, &AB);
        lengthCalculation(bX, bY, cX, cY, &BC);
        lengthCalculation(aX, aY, cX, cY, &AC);

        printf("The coordinates of the vertices of your triangle:\nA(%f, %f), B(%f, %f), C(%f, %f)\nAB=%f\nBC=%f\nAC=%f\n\n", aX, aY, bX, bY, cX, cY, AB, BC, AC);

        triangleType(AB, BC, AC);

        printf("Perimeter of a triangle:\nP=%f\n\n", PCalc(AB, BC, AC));

        areaCalculation(AB, BC, AC, &S);
        printf("Area of a triangle:\nS=%f\n\n", S);

        printf("Circumscribed circle radius:\nR=%f\n\nInscribed circle radius:\nr=%f\n\n", circumscribedRadius(AB, BC, AC, S), inscribedRadius(AB, BC, AC, S));

        exit = ' ';
        while (exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
        {
            printf("Exit(Y/N)\n");
            scanf("%s", &exit);
            if (exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N') printf("Invalid input.\n");
        }
    }
}

#endif
