#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COR_VERDE       printf("\33[32m");
#define COR_LARANJA     printf("\33[33m");
#define COR_ROXO        printf("\33[35m");
#define COR_BRANCO      printf("\33[37m");

#define TAM 5

int main() {

    int l, c, m_diag = 0, m_abaixo = 0, m_acima = 0;
    int mat[TAM][TAM];

    srand(time(NULL));

   
    for(l = 0; l < TAM; l++){ 
        for(c = 0; c <TAM; c++){
            mat[l][c] = 10 + (rand()%41);

            // Diagonal
            if(l == c){
                if(mat[l][c] > m_diag){
                    m_diag = mat[l][c];
                }
            }

            // Acima da Diagonal
            if(c > l){
                if(mat[l][c] > m_acima){
                    m_acima = mat[l][c];
                }
            }

            // Abaixo da Diagonal
            if(l > c){
                if(mat[l][c] > m_abaixo){
                    m_abaixo = mat[l][c];
                }
            }
        }
    }

    printf("\nMatriz Aleatoria: \n");
    for(l = 0; l < TAM; l++){ 
        printf("\n");
        for(c = 0; c <TAM; c++){
            COR_BRANCO

            if(l == c && mat[l][c] == m_diag){
                COR_LARANJA
            }
            else if(c > l && mat[l][c] == m_acima){
                COR_ROXO
            }
            else if(l > c && mat[l][c] == m_abaixo){
                COR_VERDE
            }

            printf("%i ", mat[l][c]);
        }
    }
       
    printf("\n\n");
    return 0;
}