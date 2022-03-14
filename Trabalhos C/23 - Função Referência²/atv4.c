#include <stdio.h>
#include <stdlib.h>

void piramide(char **pir, int linhas, int colunas);

int main() {

    char **mat;
    int lin, col, a;

    printf("\nAltura da pirâmide: ");
    scanf("%i", &lin);

    mat = malloc(lin * sizeof(char*));

    for(a=0; a<lin; a++){
        mat[a] = malloc(lin * sizeof(char));
    }

    col = lin;

    piramide(mat,lin,col);

    for(int l = 0; l<lin; l++){
        for(int c = 0; c<col; c++){
            printf("%c",mat[l][c]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n\n");
    return 0;
}

void piramide(char **pir, int linhas, int colunas){

    int l, c, esp = colunas - 1;

    for(l=0; l<linhas; l++){
        for(c=0; c<colunas; c++){
            if(c < esp){
            }
            else{
                pir[l][c] = '*';
            }
        }
        esp--;
    }
}