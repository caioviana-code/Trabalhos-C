#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    printf("\n");

    int i, vetor[12], maior = 0, menor = 0, posicao_maior = 0, posicao_menor = 0;

    printf("Vetor aleatorio: ");
    for(i = 0; i < 12; i++){

        vetor[i] = 10 + rand() % 90;
        printf("%i ", vetor[i]);

        if(vetor[i] > maior){
            maior = vetor[i];
            posicao_maior = i;
        }
        if(menor == 0){
            menor = vetor[i];
            posicao_menor = i;
        }
        if(menor > vetor[i]){
            menor = vetor[i];
            posicao_menor = i;
        }
    }

    printf("\n- Maior elemento: %i / Posicao: %i",maior, posicao_maior);
    printf("\n- Menor elemento: %i / Posicao: %i",menor, posicao_menor);

    printf("\n\n");
    return 0;
}