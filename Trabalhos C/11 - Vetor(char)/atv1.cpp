#include <stdio.h>
#include <stdlib.h>

#define TAM 50

int main() {

    printf("\n");
    int a, cont = 0;
    char frase[TAM];
    char letra;

    printf("Digite a frase: ");
    fflush(stdin);
    gets(frase);

    printf("Digite um caractere: ");
    fflush(stdin);
    scanf("%c",&letra);

    for(a=0; frase[a] != '\0'; a++){
        if(frase[a] == letra){
            cont++;
        }
    }
    printf("- O caractere (%c) foi encontrado (%i) veze(s)",letra,cont);

    printf("\n\n");
    return 0;
}