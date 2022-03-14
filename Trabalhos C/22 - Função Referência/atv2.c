#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void ordenar(int *ptr);

int main() {

    srand(time(NULL));

    int a, *ptr;

    ptr = malloc(TAM * sizeof(int));

    printf("\nVetor Aleatório: ");
    for(a=0; a<TAM; a++){
        ptr[a] = 10 + rand()%90;
        printf("%i ",ptr[a]);
    }

    ordenar(ptr);

    printf("\n- Vetor Ordenado: ");
    for(a=0; a<TAM; a++){
        printf("%i ",ptr[a]);
    }

    printf("\n\n");
    return 0;
}

void ordenar(int *ptr){

    int a, b, aux;

    for(a=0; a<TAM; a++){
        for(b=a; b<TAM; b++){
            if(ptr[a] > ptr[b]){
                aux = ptr[a];
                ptr[a] = ptr[b];
                ptr[b] = aux;
            }
        }
    }
}