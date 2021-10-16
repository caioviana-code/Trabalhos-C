#include <stdio.h>

int main(){

    printf("\n");
    int num, div, soma, cont;

    printf("Numero inteiro: ");
    scanf("%i", &num);

    div = 1;
    soma = 0;
    cont = 0;

    printf("- Divisivel por: ");
    while(div < num){
        
        if(num % div == 0){
            if(cont == 0){
                printf("%i ", div);
                cont++;
            }
            else{
                printf("+ %i ",div);
            }
                 
            soma = soma + div;
        }
        div = div + 1;
    }
    printf(" = %i", soma);

    if(soma == num){
        printf(" [PERFEITO]");
    }
    else{
        printf(" [IMPERFEITO]");
    }

    printf("\n\n");
    return 0;
}