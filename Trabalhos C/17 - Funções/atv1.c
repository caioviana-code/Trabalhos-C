#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pitagoras(int ca, int co);

int main() {

    int ca, co;
    double hip;

    printf("\nDigite o valor dos catetos: ");
    scanf("%i %i", &ca, &co);

    hip = pitagoras(ca, co);

    printf("\n - Hipotenusa: %.1lf", hip);

    printf("\n\n");
    return 0;
}

double pitagoras(int ca, int co) {

    double hip;

    hip = sqrt(ca*ca + co*co);
    return hip;

}