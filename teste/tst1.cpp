#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10


int main() {

    srand(time(NULL));
    printf("\n");
    
   int a,;
   char frase[TAM];
   char palavra[TAM];

    printf("Vetor aleatorio: ");
    for(a=0; a<TAM; a++){
      
        //maior
        if(a%2 == 0){
            frase[a] = 65 + (rand()%26);
            printf("%c ", frase[a]);            
        }
        //menor
        else{
            frase[a] = 97 + (rand()%26);
            printf("%c ", frase[a]);
        }
        
    }
   frase[a] = '\0';

    printf("\n\n");
    return 0;
}