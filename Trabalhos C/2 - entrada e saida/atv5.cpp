#include <stdio.h>

int main() {

   float f, c;

    printf("Digite a temperatura em Celsius (C):");
    scanf("%f", &c);

    f = (9 * c + 160) /5;

    printf("- Temperatura em Fahrenheit = %.1f", f);

    return 0;
}