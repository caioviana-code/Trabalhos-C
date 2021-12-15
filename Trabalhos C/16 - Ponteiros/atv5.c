#include <stdlib.h>
#include <stdio.h>

int main() {

    int a, tam;
    char *palavra;

    printf("\nDigite o tamanho: ");
    scanf("%i", &tam);

    palavra = malloc(tam * sizeof(char));

    printf("Digite uma palavra: ");
    fflush(stdin);
    gets(palavra);

    printf(" - Posicoes Impares: ");
    for(a=0; palavra[a] != '\0'; a++){
        if(a % 2 != 0){
            printf("%c",palavra[a]);
        }
    }

    printf("\n\n");
    return 0;
}