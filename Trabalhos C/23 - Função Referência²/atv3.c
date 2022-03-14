#include <stdio.h>
#include <stdlib.h>

void progessao(int *p, int tam, int termo, int razao);

int main() {

    int *pa, tam, termo, razao, a;

    printf("\nTamanho vetor (ímpar): ");
    scanf("%i", &tam);
    printf("Termo inicial e Razão: ");
    scanf("%i %i", &termo, &razao);

    pa = malloc(tam * sizeof(int));
    progessao(pa, tam, termo, razao);

    printf(" - Progressão aritmética: ");
    for(a=0; a<tam; a++) {
        printf("%i ", pa[a]);
    }

    printf("\n\n");
    return 0;
}

void progessao(int *p, int tam, int termo, int razao) {

    int a, b, meio = tam/2;
    
    p[meio] = termo;

    for(a=meio-1, b=meio+1; a>=0; a--, b++) {
        p[a] = p[a+1] - razao;
        p[b] = p[b-1] + razao;
    }
}