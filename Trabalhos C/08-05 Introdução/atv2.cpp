#include <stdio.h>

int main() {

    int v1, v2, v3, v4, v5, v6;

    v6 = -200;
    v5 = 10;

    v1 = v5 + v6;
    v2 = v5 - v6;
    v3 = v5 * v6;
    v4 = v6 / v5;

    printf("> Valor de (v6) = -200");
    printf("\n> Valor de (v5) = 10");
    printf("\n> Soma: 10 + -200 = %i",v1);
    printf("\n> Subtracao: 10 - -200 = %i",v2);
    printf("\n> Multiplicacao: 10 * -200 = %i",v3);
    printf("\n> Divisao: -200 / 10 = %i",v4);
     
    return 0;
}