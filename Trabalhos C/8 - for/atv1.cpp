#include <stdio.h>

int main(){

    printf("\n");
    int num, div, soma = 1;

    printf("Digite um valor inteiro: ");
    scanf("%i", &num);

    printf("\n- Fatorial(%i) = ", num);

    for(num ; num > 1 ; num = num - 1){
        div = num;
        if(div == 2){
            printf("%i =", div);
        }
        else{printf("%i x ",div);}
        
        soma = soma * div;       
    }
    printf(" %i", soma);

    printf("\n\n");
    return 0;
}