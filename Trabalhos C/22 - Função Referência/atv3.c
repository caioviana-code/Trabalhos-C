#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

void transposta(int **mat);

int main() {

    srand(time(NULL));

    int a, l, c;
    int **mat;

    mat = malloc(TAM * sizeof(int*));

    for(a=0; a<TAM; a++){
        mat[a] = malloc(TAM * sizeof(int));
    }

    printf("\nMatriz:\n");
    for(l=0; l<TAM; l++){
        for(c=0; c<TAM; c++){
            mat[l][c] = 10 + rand()%90;
            printf("%i ",mat[l][c]);
        }
        printf("\n");
    }

    transposta(mat);

    printf("\nTransposta:\n");
    for(c=0; c<TAM; c++){
        for(l=0; l<TAM; l++){
            printf("%i ",mat[l][c]);
        }
        printf("\n");
    }

    printf("\n\n");
    return 0;
}

void transposta(int **mat){

    int **mat2;
    int a, l, c;

    mat2 = malloc(TAM * sizeof(int*));

    for(a=0; a<TAM; a++){
        mat2[a] = malloc(TAM * sizeof(int));
    }

    for(l=0; l<TAM; l++){
        for(c=0; c<TAM; c++){
            mat2[l][c] = mat[l][c];
        }
    }

    for(c=0; c<TAM; c++){
        for(l=0; l<TAM; l++){
            mat[l][c] = mat2[l][c];
        }
    }
    
}

