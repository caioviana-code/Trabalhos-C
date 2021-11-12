#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main() {

    srand(time(NULL));

    int matriz[TAM][TAM], l, c, l2, c2, aux;

    printf("\nMatriz Aleatoria: ");
    for(l = 0; l < TAM; l++){

        printf("\n");
        for(c = 0; c < TAM; c++){
            matriz[l][c] = 10 + rand() % 41;
            printf("%i ",matriz[l][c]);
        }
    }

    for(l = 0; l < TAM; l++){
        for(c = 0; c < TAM; c++){

            for(l2 = 0; l2 < TAM; l2++){
                for(c2 = 0; c2 < TAM; c2++){
                    if(matriz[l][c] < matriz[l2][c2]){
                        aux = matriz[l][c];
                        matriz[l][c] = matriz[l2][c2];
                        matriz[l2][c2] = aux; 
                    }
                }
            }
        }
    }

    printf("\n\nMatriz Ordenada: ");
    for(l = 0; l < TAM; l++){
        printf("\n");
        for(c = 0; c < TAM; c++){
            printf("%i ",matriz[l][c]);
        }
    }

    printf("\n\n");
    return 0;
}