#include <stdio.h>

int main() {

    float CM, TC, DT;

    printf("Media de consumo (km/l):");
    scanf("%f", &CM);
    printf("Gasolina no tanque (l):");
    scanf("%f", &TC);

    DT = CM * TC;

    printf("- Distancia percorrida = %.1fkm", DT);

     return 0;
}