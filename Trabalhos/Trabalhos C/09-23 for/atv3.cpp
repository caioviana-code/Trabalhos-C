#include <stdio.h>

int main(){

    printf("\n");
    int v1, v2, soma = 0, flag = 1;

    printf("\tDigite 2 valores inteiros: ");
    scanf("%i %i",&v1, &v2);

    if(v1 >= v2){
        printf("\n\tValores incorretos.");
    }

    else{

        printf("\n\tSomando valores pares: ");
    
        for( v1 = v1 + 1 ; v1 < v2 ; v1++){
        
            if(v1 % 2 == 0 && flag == 1){
                printf("%i ",v1);
                flag = 0;
                soma = v1;
            }
            else if(v1 % 2 == 0){
                printf("+ %i ", v1);
                soma = soma + v1;
            }
       
        } 
        printf("= %i", soma); 
    }   
    
    printf("\n\n");
    return 0;
}