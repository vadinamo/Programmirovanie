/* Треугольник. Разработать программу, меню которой позволяет выполнить следующие функции:
1. Ввод координат вершин треугольника.+
2. Определить вид треугольника (правильный, прямоугольный, равнобедренный, произвольного вида).+
3. Вывод периметра треугольника.+
4. Вывод площади треугольника.+
5. Вычислить и вывести радиусы вписанной и описанной вокруг треугольника окружностей.+
6. Информация о версии и авторе программы.+
7. Выход из программы.+ */

#include <stdio.h>
#include <math.h>

void inputCheck(double *enteredNumber)
{
    while (!scanf("%lf", enteredNumber))
    {
            while (getchar() != '\n') {}
            printf("\nError!\n\nEnter your natural number.\nm=");
    }
}

void triangleType(double *AB, double *BC, double *AC)
{
    double biggest, side1, side2;
    if (*AB > *BC && *AB > *AC)
    {
        biggest = *AB;
        side1 = *BC;
        side2 = *AC;
    }
    else if (*BC > *AB && *BC > *AC)
    {
        biggest = *BC;
        side1 = *AB;
        side2 = *AC;
    }
    else
    {
        biggest = *AC;
        side1 = *AB;
        side2 = *BC;
    }
    
    if (*AB == *BC && *AB == *AC)
    {
        printf("Your triangle is regular.\n\n");
    }
    else if ((*AB == *BC && *AB != *AC) || (*AB == *AC && *AB != *BC) || (*BC == *AC && *BC != *AB))
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

void lengthCalculation(double *X1, double *Y1, double *Y2, double *X2, double *side)
{
    *side = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
}

void perimeterСalculation(double *AB, double *BC, double *AC, double* Perimeter)
{
    *Perimeter = *AB + *BC + *AC;
}

void areaCalculation(double *AB, double *BC, double *AC, double *Square)
{
    float p;
    p = (*AB + *BC + *AC) / 2;
    *Square = sqrt(p * (p - *AB) * (p - *BC) * (p - *AC));
}

void radiusCalculation(double *AB, double *BC, double *AC, double *S, double *r, double *R)
{
    *R = (*AB * *BC * *AC) / (4 * *S);
    *r = (2 * *S) / (*AB + *BC + *AC);
}

int main()
{
    printf("Triangle calculator v1.0\nDeveloped by Vadim Yur'ev, 053502, 27 on the list.\n__________________________________________________\n");
    char exit = ' ';
    while (exit != 'y' && exit != 'Y')
    {
        printf("\n");
        double AB, BC, AC, aX, aY, bX, bY, cX, cY, P, S, r, R;
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
        
        lengthCalculation(&aX, &aY, &bX, &bY, &AB);
        lengthCalculation(&bX, &bY, &cX, &cY, &BC);
        lengthCalculation(&aX, &aY, &cX, &cY, &AC);
        
        printf("The coordinates of the vertices of your triangle:\nA(%lf, %lf), B(%lf, %lf), C(%lf, %lf)\nAB=%lf\nBC=%lf\nAC=%lf\n\n", aX, aY, bX, bY, cX, cY, AB, BC, AC);
        
        triangleType(&AB, &BC, &AC);
        
        perimeterСalculation(&AB, &BC, &AC, &P);
        printf("Perimeter of a triangle:\nP=%lf\n\n", P);
        
        areaCalculation(&AB, &BC, &AC, &S);
        printf("Area of a triangle:\nS=%lf\n\n", S);
        
        radiusCalculation(&AB, &BC, &AC, &S, &r, &R);
        printf("Radius of the circumscribed circle:\nR=%lf\n\nInscribed circle radius:\nr=%lf\n\n", R, r);
        
        exit = ' ';
        while (exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N')
        {
            printf("Exit(Y/N)\n");
            scanf("%s", &exit);
            if (exit != 'y' && exit != 'Y' && exit != 'n' && exit != 'N') printf("Invalid input.\n");
        }
    }
}
