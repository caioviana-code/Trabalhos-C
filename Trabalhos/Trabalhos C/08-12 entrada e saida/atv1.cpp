#include <stdio.h>

int main() {

    int x, quadrado, cubo;

    printf("\nDigite um numero:");
    scanf("%i", &x);
    quadrado = x * x;
    cubo = x * x * x;

    printf("- Quadrado = %i", quadrado);
    printf("\n- Cubo = %i", cubo);

    return 0;
}