#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

void referencia(char *n);

int main() {

    char *nome = malloc(TAM * sizeof(char));

    printf("\nDigite um nome: ");
    fflush(stdin);
    gets(nome);

    referencia(nome);

    printf("\n\n");
    return 0;
}

void referencia(char *n){

    int a, pue;

    // Acha o último espaço
    for(a=0; n[a]!='\0'; a++) {
        if(n[a] == ' ') {
            pue = a;
        }
    }

    printf("\n - Referência: ");
    // Mostra último nome
    for(a=pue+1; n[a]!='\0'; a++) {
        if(n[a] >= 97) {
            printf("%c", n[a]-32);
        }
        else {
            printf("%c", n[a]);
        }
        
    }
    printf(", ");

    // Mostra primeiro nome
    for(a=0; n[a]!=' '; a++) {
        printf("%c", n[a]);
    }

    printf(" ");
    // Nomes intermediários
    for(a; a<pue; a++) {
        if(n[a] == ' ' && n[a+1] <= 90) {
            printf("%c. ", n[a+1]);
        }
    }
}

