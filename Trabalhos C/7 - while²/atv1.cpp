#include <stdio.h>

int main(){

    printf("\n");
    int v1, v2, cont = 0, div;

    printf("Digite dois numeros: ");
    fflush(stdin);
    scanf("%i %i", &v1, &v2);
    
    printf("Numeros primos entres (%i) e (%i): ", v1, v2);
    while(v1 <= v2){
        cont = 0;
        div = 1;
        while(div <= v1){
           if(v1%div == 0){
               cont++;
            }
            div++;
        }

        if(cont == 2){
            printf("%i ", v1);
        }
        v1++;
    }

    printf("\n\n");
    return 0;
}