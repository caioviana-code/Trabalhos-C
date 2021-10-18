#include <stdio.h>
#include <math.h>

int main()
{

    double a, b, c, r1, r2;
    printf("coeficiente (a, b, c):");
    scanf("%lf %lf %lf", &a, &b, &c);
    fflush(stdin);
    r1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    r2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    printf("\n -raizes=%.1lf %.1lf ", r1, r2);

    return 0;
}