#include <stdio.h>

int main(){

    printf("\n");
    int largura, altura, cont, cont2;

    printf("Largura e Altura: ");
    scanf("%i %i", &largura, &altura);
    printf("\n");
    
    cont2 = 1;
    while(cont2 <= altura){
        cont = 1;
        while(cont <= largura){
            printf("* ");
            cont++;
        }
        printf("\n");
        cont2++;
    }

    printf("\n\n");
    return 0;
}