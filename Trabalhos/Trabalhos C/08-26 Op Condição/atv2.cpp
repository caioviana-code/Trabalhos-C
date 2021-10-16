#include <stdio.h>

int main() {

    int n1, n2, n3;

    printf("\nDigite tres numeros:");
    scanf("%i %i %i", &n1, &n2, &n3);

    if(n1 > n2 && n1 > n3){
        printf("- Maior = %i",n1);
        if(n2 < n3){
            printf("\n- Menor = %i",n2);
        }
        else{
            printf("\n- Menor %i",n3);
        }
    }    
    else if(n2 > n1 && n2 > n3){
        printf("- Maior = %i",n2);
        if(n1 < n3){
            printf("\n- Menor = %i",n1);
        }
        else{
            printf("\n- Menor = %i",n3);
        }
    }
    else{
        printf("- Maior = %i",n3);
        if(n1 < n2){
            printf("\n- Menor = %i",n1);
        }
        else{
            printf("\n- Menor = %i",n2);
        }
    }
   
    printf("\n\n");
    return 0;
}