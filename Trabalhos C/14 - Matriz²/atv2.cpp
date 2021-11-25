#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

int main() {

    srand(time(NULL));

    int l, c, c1, resultado;
    int mat1[TAM][TAM], mat2[TAM][TAM], mr[TAM][TAM];

    // gerando matriz 1 aleatória e mostrando
    for(l=0; l<TAM; l++){
        printf("\n");
        for(c=0; c<TAM; c++){
            mat1[l][c] = 2 + (rand()%4);
            printf("%i ", mat1[l][c]);
        }
    }

    printf("\n\n  X\n");

    // gerando matriz 2 aleatória e mostrando
    for(l=0; l<TAM; l++){
        printf("\n");
        for(c=0; c<TAM; c++){
            mat2[l][c] = 2 + (rand()%4);
            printf("%i ", mat2[l][c]);
        }
    }

    for(l = 0; l < TAM; l++){
        for(c = 0; c < TAM; c++){

            resultado = 0;

            for(c1 = 0; c1 < TAM; c1++){

                resultado = resultado + (mat1[l][c1] * mat2[c1][c]);
            }
            mr[l][c] = resultado;
        }
    }

    printf("\n\n  =\n");

    for(l=0; l<TAM; l++){
        printf("\n");
        for(c=0; c<TAM; c++){
            printf("%i ", mr[l][c]);
        }
    }


    printf("\n\n");
    return 0;
}