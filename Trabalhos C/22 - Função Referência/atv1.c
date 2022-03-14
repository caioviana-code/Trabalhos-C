#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void baskhara(int a, int b, int c, double *x1, double *x2);

int main() {

    int a, b, c;
    double x1, x2;

    printf("\nDigite os coeficientes (a), (b) e (c): ");
    scanf("%i %i %i", &a, &b, &c);

    baskhara(a, b, c, &x1, &x2);

    printf("Raízes: %.1lf %.1lf", x1, x2);

    printf("\n\n");
    return 0;
}

void baskhara(int a, int b, int c, double *x1, double *x2){

    *x1 = (-b + sqrt(b*b - (4*a*c)))/2*a;
    *x2 = (-b - sqrt(b*b - (4*a*c)))/2*a;

}
