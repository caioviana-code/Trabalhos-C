#include <stdio.h>

int main(){

    int num, cont = 0, div = 1;

    printf("\nDigite um numero:");
    scanf("%i", &num);

    while(div <= num){
        if(num%div == 0){
            cont++;
        }
        div++;
    }

    if(cont == 2){
        printf("- [PRIMO]");
    }
    else{
        printf("- [NAO PRIMO]");
    }

    printf("\n\n");
    return 0;

}