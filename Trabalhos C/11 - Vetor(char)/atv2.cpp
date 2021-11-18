#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main() {

    srand(time(NULL));

    printf("\n");
   
    int v, p, rep;
    char vetor[TAM], palavra[TAM], cont;

    printf("Vetor aleatorio: ");

    for(v = 0; v < TAM; v++){

        if(rand() % 2 == 0){
            vetor[v] = 65 + (rand()%26);
        }
        else{
            vetor[v] = 97 + (rand()%26);
        }

        for(cont = 0, rep = 0; rep != v; rep++){
            if(vetor[v] != vetor[rep]){
                cont++;
            }
        }

        if(cont ==  rep){
            printf("%c ",vetor[v]);
        } 
        else{
            v--;
        }
    }
    vetor[v] = '\0';

    printf("\nPalavra: ");
    gets(palavra);

    for(p = 0, v = 0; v < TAM; v++){

        if(palavra[p] == '\0'){
            break;
        }
        else if(vetor[v] == palavra[v]){
            p++;
        }
        else{
            p = 0;
        }
    }

    if(palavra[p] == '\0'){
        printf("\n- [E possivel]");
    }
    else{
        printf("\n- [Nao e possivel]");
    }
    
    printf("\n\n");
    return 0;
}