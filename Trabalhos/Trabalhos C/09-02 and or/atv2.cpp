#include <stdio.h>

int main(){

    int idade;

    printf("Digite a idade:");
    scanf("%i", &idade);

    if(idade < 0){
        printf("- Idade Invalida!");
    }

    else{
         
         if(idade >= 0 && idade <= 11){
             printf("- Crianca");
         }
         else if(idade >= 12 && idade <= 17){
             printf("- Adolescente");
         }
         else if(idade >= 18 && idade <= 59){
             printf("- Adulto");
         }
         else{
             printf("- Idoso");
         }
        

    }

    printf("\n\n");
    return 0;
}