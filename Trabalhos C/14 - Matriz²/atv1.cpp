#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COR_VERDE       printf("\33[32m");
#define COR_LARANJA     printf("\33[33m");
#define COR_ROXO        printf("\33[35m");
#define COR_BRANCO      printf("\33[37m");

#define TAM 5

int main() {

    int l, c;
    int mat[TAM][TAM];

    srand(time(NULL));


    printf("Matriz Aleatoria: \n");
    for(l = 0; l < TAM; l++){
        printf("\n");
        for(c = 0; c <TAM; c++){
            mat[l][c] = 10 + (rand()%41);
            printf("%i ", mat[l][c]);
        }
    }

    printf("\n\n");
    return 0;
}