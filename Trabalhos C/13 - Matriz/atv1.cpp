#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
int main() {

    srand(time(NULL));

    int matriz[TAM][TAM], l, c;

    printf("\nMatriz Original: ");
    for(l = 0; l < TAM; l++){

        printf("\n");
        for(c = 0; c < TAM; c++){

            matriz[l][c] = 10 + rand() % 41;
            printf("%i ",matriz[l][c]);
        }
    }

    printf("\n\nMatriz Transposta: ");
    for(c = 0; c < TAM; c++){

        printf("\n");
        for(l = 0; l < TAM; l++){
            printf("%i ",matriz[l][c]);
        }
    }

    printf("\n\n");
    return 0;
}