#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 12
#define RAN 90

int main() {

    srand(time(NULL));
    printf("\n");

    int vetor[TAM];
    int posicao, aux, pos1, pos2;

    printf("\n- Vetor aleatorio: ");
    for(posicao = 0; posicao < TAM; posicao++){
        vetor[posicao] = 10 + rand() % RAN;
        
        printf("%i ", vetor[posicao]);
    }

    for(pos1 = 0; pos1 < TAM; pos1++){

        for(pos2 = pos1 + 1; pos2 < TAM; pos2++){

            if(vetor[pos1] < vetor[pos2]){
                aux = vetor[pos1];
                vetor[pos1] = vetor[pos2];
                vetor[pos2] = aux;
            }
        }
    }

    printf("\n- Vetor ordenado: ");
    for(posicao = 0; posicao < TAM; posicao++){
        printf("%i ", vetor[posicao]);
    }

    printf("\n\n");
    return 0;
}