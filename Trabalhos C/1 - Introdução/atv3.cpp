#include <stdio.h>

int main() {

    int a, b, c, d;

    a = 5;
    d = 10;

    b = (a + a) + (d * d);
    c = d * d / b;

    printf("> Valor de (a) = %i",a);
    printf("\n>Valor de (b) = %i",b);
    printf("\nValor de (c) = %i",c);
    printf("\nValor de (d) = %i",d);

    return 0;
}