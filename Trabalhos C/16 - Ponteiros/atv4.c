#include <stdio.h>
#include <stdlib.h>

int main() {

    int tam, a, pos;
    char *palavra, *invertida;

    printf("digite o tamanho: ");
    scanf("%i", &tam);

    palavra = malloc(tam * sizeof(char));
    invertida = malloc(tam * sizeof(char));

    printf("Digite a palavra: ");
    fflush(stdin);
    gets(palavra);

    printf(" - Invertida = ");
    for(a=0, pos=tam-1; palavra[a] != '\0'; a++, pos--){
        invertida[a] = palavra[pos];
        printf("%c",invertida[a]);
    }

    printf("\n\n");
    return 0;
}