#include <stdio.h>
#include <math.h>

int main() {

    int x, y;
    double result;

    printf("Digite dois valores inteiros:");
    scanf("%i %i", &x, &y);

    result = sqrt(pow(y, x));
    printf("- raiz = %.1lf", result);

    return 0;
}