#include <stdio.h>

int main(){

    float media;

    printf("Digite a nota media:");
    scanf("%f", &media);

    if(media >= 6.0){
        printf("- Aprovado");
    }
    else if(media < 5.9 && media > 4.0){
        printf("- Recuperacao");
    }
    else{
        printf("- Reprovado");
    }
    return 0;
}