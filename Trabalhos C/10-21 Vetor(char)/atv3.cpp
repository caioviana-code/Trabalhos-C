#include <stdlib.h>
#include <stdio.h>

#define TAM 30

int main() {

    printf("\n");

    int a, b, cont = 0, cont2 = 0;
    char conteudo[TAM], busca[TAM];

    printf("String conteudo: ");
    fflush(stdin);
    gets(conteudo);

    printf("String busca: ");
    fflush(stdin);
    gets(busca);

    for(b = 0; busca[b] != '\0'; b++){

        for(a = 0; conteudo[a] != '\0'; a++){

            if(busca[b] == conteudo[a]){
                cont++;
                b++;
            }
            
        }
    }

    for(b = 0; busca[b] != '\0'; b++){
        cont2++;
    }

    if(cont == cont2){
        printf("- Achou!");
    }
    else{
        printf("- Nao achou");
    }

    printf("\n\n");
    return 0;
}