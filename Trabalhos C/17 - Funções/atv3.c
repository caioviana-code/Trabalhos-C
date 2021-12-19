#include <stdio.h>
#include <stdlib.h>

int primo(int num);

int main() {

    int num, retorno;

    printf("\nDigite um valor: ");
    scanf("%i", &num);

    retorno = primo(num);

    if(retorno == 2){
        printf(" - PRIMO");
    }
    else{
        printf(" -  NAO PRIMO");
    }

    printf("\n\n");
    return 0;
}

int primo(int num) {

    int a, cont = 0;

    for(a=1; a<=num; a++){
        if(num % a == 0){
            cont++;
        }
    }

    return cont;

}