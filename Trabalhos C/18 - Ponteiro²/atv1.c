#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int main() {

    int a, flag = 0;
    char *palavra1, *palavra2;
    
    palavra1 = malloc(TAM * sizeof(char));
    palavra2 = malloc(TAM * sizeof(char));

    printf("\nPrimeira palavra: ");
    fflush(stdin);
    gets(palavra1);
    printf("Segunda palavra: ");
    fflush(stdin);
    gets(palavra2);

    for(a=0; a<TAM; a++){
        if(palavra1[a] != palavra2[a]){
            printf(" - Diferentes, posição %i: '%c' != '%c' ",a,palavra1[a],palavra2[a]);
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("- Iguais");
    }

    printf("\n\n");
    return 0;
}