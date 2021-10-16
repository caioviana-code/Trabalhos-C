#include <stdio.h>

int main(){

    int num, menor = 0, maior =0;

    printf("Numero:");
    fflush(stdin);
    scanf("%i", &num);

    if(num >= 0){
        maior = num;
        menor = num;
    }

    while(num >= 0){
        printf("Numero:");
        fflush(stdin);
        scanf("%i", &num);

        if(num < maior && num >0){
            maior = num;
        }
        if(num < menor){
            menor = num;
        }
    }

    printf("Maior: %i", maior);
    printf("\nMenor: %i", menor);

    printf("\n\n");
    return 0;
}

