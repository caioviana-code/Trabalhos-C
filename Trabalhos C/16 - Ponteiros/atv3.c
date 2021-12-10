#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int main() {

    int a;
    int *val;

    val = malloc(TAM * sizeof(int));

    printf("Memoria alocada: ");
    for(a=0; a<TAM; a++){
        val[a] = a * 2;
        printf("%i ",val[a]);
    }

    printf("\n\n");
    return 0;
}