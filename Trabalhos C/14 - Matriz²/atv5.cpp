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

    int l, c, cont = 0, espelho[TAM][TAM];
    char mat[TAM][TAM], p1[TAM], p2[TAM];

    // gerando matriz aleatória
    for(l=0;l<TAM;l++){
        //printf("\n");
        for(c=0;c<TAM;c++){
            mat[l][c] = 65 + (rand()%26);
            espelho[l][c] = 0;
            //printf("%c ",mat[l][c]);
        }
    }

    printf("\nPrimeira Palavra: ");
    fflush(stdin);
    gets(p1);
    printf("Segunda Palavra: ");
    fflush(stdin);
    gets(p2);

    l = rand()%TAM;
    for(c = 0; p1[c] != '\0'; c++){
        mat[l][c] = p1[c];
        espelho[l][c] = 1;
        cont++;
    }
   
    do{
        c = rand()%TAM;
    }while(c <= cont);

    for(l = 0; p2[l] != '\0'; l++){
        mat[l][c] = p2[l];
        espelho[l][c] = 1;
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