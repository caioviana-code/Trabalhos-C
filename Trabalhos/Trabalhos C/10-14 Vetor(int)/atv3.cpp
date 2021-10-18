#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    printf("\n");

    int i, vetor[4], media;

    printf("Vetor Aleatorio: ");
    for(i = 0; i < 4; i++){

        vetor[i] = 10 + rand() % 90;
        printf("%i ", vetor[i]);
    }

    media = vetor[0] + vetor[1] + vetor[2] + vetor[3];
    media = media / 4;

    printf("\n- Valor medio: %i",media);

    printf("\n\n");
    return 0;
}