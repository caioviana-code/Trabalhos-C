#include <stdio.h>

int main() {

    int a, b, soma, *pa, *pb;

    printf("\ndigite dois valores inteiros: ");
    scanf("%i %i", &a, &b);

    pa = &a;
    pb = &b;

    soma = *pa + *pb;

    printf("- Soma = %i",soma);

    printf("\n\n");
    return 0;
}