#include <stdio.h>
#include <math.h>

int main() {

    int num, teste;
 
    printf("\nDigite um numero:");
    scanf("%i", &num);

    teste = num % 2;

    if(teste == 0){
        printf("- PAR");
    }
    else{
        printf("- IMPAR");
    }
    
    printf("\n\n");
    return 0;
}