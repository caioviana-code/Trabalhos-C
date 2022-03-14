#include <stdio.h>
#include <stdlib.h>

void desembalharar(char *plvr, char *emba);

int main() {

    char *palavra, *embaralhada;

    palavra = malloc(30 * sizeof(char));
    embaralhada = malloc(30 * sizeof(char));

    printf("\nDigite uma palavra: ");
    fflush(stdin);
    gets(palavra);
    printf("Digite a mesma palavra embaralhada: ");
    fflush(stdin);
    gets(embaralhada);

    desembalharar(palavra,embaralhada);

    printf(" - Desembaralhada: %s", embaralhada);

    printf("\n\n");
    return 0;
}

void desembalharar(char *plvr, char *emba){

    int a,b; 
    char aux;

    for(a = 0; plvr[a] != '\0'; a++){ // |g|i|l| - |i|g|l|
        for(b = 0; emba[b] != '\0'; b++){
            if(plvr[a] == emba[b]){
                aux = emba[a];
                emba[a] = emba[b];
                emba[b] = aux;
            }
        }
    }

}