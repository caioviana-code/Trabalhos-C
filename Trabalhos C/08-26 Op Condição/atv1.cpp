#include <stdio.h>
#include <math.h>

int main() {

    int num;

    printf("Digite um numero inteiro:");
    scanf("%i", &num);

    if(num > 0){
        printf("- Positivo");
    }
    else if(num == 0){
        printf("- Neutro");
    }
    else{
        printf("- Negativo");
    }

    return 0;
}