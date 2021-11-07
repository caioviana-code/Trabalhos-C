#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define TAM 15

int main() {

    srand(time(NULL));

    printf("\n");

    int a, b, flag;
    char vetor[TAM];

    flag = 1;

    printf("Vetor aleatorio: ");
    for(a = 0; a<TAM; a++){
        vetor[a] = 65 + (rand()%26);
        printf("%c ", vetor[a]);
    }
    vetor[a] = '\0';

    // |S|G|X|T|Z|G|O|K|F|S|J|F|V|V|N|\0|
    // vetor a = S
    // vetor b = S
   
    printf("\n- Vetor alterado: ");
    for(a = 0; vetor[a] != '\0'; a++){
        
        for(b = a + 1; vetor[b] != '\0'; b++){

            if(vetor[b] == vetor[a]){
                vetor[b] = 64;
            }
        }
    }

    for(a = 0; vetor[a] != '\0'; a++){
        printf("%c ", vetor[a]);
    }

   
    printf("\n\n");
    return 0;
}