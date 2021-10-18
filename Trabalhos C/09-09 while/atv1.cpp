#include <stdio.h>

int main(){

    int num, maior = 0, menor;

    do{
        printf("Numero:");
        fflush(stdin);
        scanf("%i", &num);
        if(num <= menor && num >= 1){
            menor = num;
        }   
        if(num >= maior){
            maior = num;
        }
    }while(num > 0);

    printf("- Maior: %i", maior);
    printf("\n- Menor: %i", menor);

    

    printf("\n\n");
    return 0;
}