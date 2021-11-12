#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 5

int main() {

    srand(time(NULL));

    int matriz[TAM][TAM], l, c, linha_escolhida, valor_escolhido;

    printf("\nmatriz Aleatoria: ");
    for(l = 0; l < TAM; l++){

        printf("\n");
        for(c = 0; c < TAM; c++){

            matriz[l][c] = 10 + rand() % 41;
            printf("%i ",matriz[l][c]);
        }
    }

    printf("\n\n- Escolha uma linha: ");
    fflush(stdin);
    scanf("%i",&linha_escolhida);
    printf("- Escolha um valor: ");
    fflush(stdin);
    scanf("%i",&valor_escolhido);

    printf("\nMatriz Modificada: ");
    for(l = 0; l < TAM; l++){

        printf("\n");
        for(c = 0; c < TAM; c++){

            if(l != linha_escolhida){
                printf("%i ",valor_escolhido);
            }
            else{
                printf("%i ",matriz[l][c]);
            }
        }
    }

    printf("\n\n");
    return 0;
}