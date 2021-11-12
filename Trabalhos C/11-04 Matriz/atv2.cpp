#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main() {

    srand(time(NULL));

    int matriz[TAM][TAM], l, c, maior;

    printf("\nMatriz Aleatoria: ");
    for(l = 0; l < TAM; l++){

        printf("\n");
        for(c = 0; c < TAM; c++){
            
            matriz[l][c] = 10 + rand() % 41;
            printf("%i ",matriz[l][c]);
        }
    }

    maior = 0;
    for(l = 0; l < TAM; l++){

        for(c = 0; c < TAM; c++){

            if(l == c && matriz[l][c] > maior){
                maior = matriz[l][c];
            }
        }
    }

    printf("\n\nMaior valor: %i",maior);

    printf("\n\n");
    return 0;
}