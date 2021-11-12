#include <stdio.h>

int main(){

    int num, maior, menor;

    do{
        printf("\n\nNumero: ");
        fflush(stdin);
        scanf("%i",num );

        if( num >= maior ){
            maior = num;
        }
        if( num <= menor ){
            menor = num;
        }
    }while(num > 0 );

    printf(" - Maior: %i", maior);
    printf("\n - Menor: %i", menor);

    printf("\n\n");
    
    return 0;
}