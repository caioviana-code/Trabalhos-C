#include <stdio.h>
#include <math.h>

int main() {
    
    int co, ca;
    double hip;

    printf("Catetos (CO CA):");
    scanf("%i %i", &co, &ca);

    hip = sqrt(pow(co,2) + pow(ca,2));
    
    printf("- Hipotenusa: %.1lf",hip );
    
    return 0;
}