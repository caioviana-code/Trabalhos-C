#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    printf("\n");

    int i, vetor[12], intervalo, maior;

    intervalo = 0;
    maior = 0;

    printf("Vetor Aleatorio: ");
    for(i = 0; i < 12; i++){

        vetor[i] = 10 + rand() % 41;
        printf("%i ",vetor[i]);

        if(vetor[i] >= 20 && vetor[i] <= 40){
            intervalo++;
        }
        if(vetor[i] >= 35){
            maior++;
        }
      
    }

    printf("\n- Quantidade de numeros entre 20 e 40: %i",intervalo);
    printf("\n- Numeros pares: ");

    for(i = 0; i < 12; i++){

        if(vetor[i] % 2 == 0){
            printf("%i ",vetor[i]);
        }
    }
    
    printf("\n- Quantidade de numeros maiores que 35: %i",maior);
  
    printf("\n\n");
    return 0;
}