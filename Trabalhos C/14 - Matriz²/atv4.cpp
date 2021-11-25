#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COR_VERDE       printf("\33[32m");
#define COR_LARANJA     printf("\33[33m");
#define COR_ROXO        printf("\33[35m");
#define COR_BRANCO      printf("\33[37m");

#define TAM 5

int main() {

    srand(time(NULL));

    int l, c, dir;
    int espelho[TAM][TAM];
    char p[TAM];
    char mat[TAM][TAM];

    // gerando matriz aleatória
    for(l=0;l<TAM;l++){
        for(c=0;c<TAM;c++){
            mat[l][c] = 65 + (rand()%26);
            espelho[l][c] = 0;
        }
    }

    printf("\nPalavra: ");
    fflush(stdin);
    gets(p);
    printf("Direcao (1-Horiz / 2-Vert): ");
    fflush(stdin);
    scanf("%i",&dir);

    if(dir == 1){
        // linha aleatória
        l = rand()%TAM;
        for(c = 0; p[c] != '\0'; c++){
            mat[l][c] = p[c];
            espelho[l][c] = 1;
        }
    }
    else{
        // coluna aleatória
        c = rand()%TAM;
        for(l = 0; p[l] != '\0'; l++){
            mat[l][c] = p[l];
            espelho[l][c] = 1;
        }
    }

    // mostrando a matriz modificada
    for(l=0;l<TAM;l++){
        printf("\n");
        for(c=0;c<TAM;c++){
            COR_BRANCO

            if(espelho[l][c] == 1){
                COR_VERDE
            }

            printf("%c ", mat[l][c]);
        }
    }

    printf("\n\n");
    return 0;
}