#include <stdio.h>
#include <math.h>

int main(){
    int dia1, dia2;
    printf("Digite os dois dias:");
    scanf("%i %i", &dia1, &dia2);

    if(dia1 < 1 || dia1 > 7){
        printf("[Invalido,");
    }
    if(dia1 == 1){
        printf("[Domingo,");
    }
    if(dia2 == 1){
        printf("Domingo]");
    }
    if(dia1 == 2){
        printf("[segunda,");
    }
    if(dia2 == 2){
        printf("Segunda]");
    }
    if(dia1 == 3){
        printf("[Terca,");
    }
    if(dia2 == 3){
        printf("Terca]");
    }
    if(dia1 == 4){
        printf("[Quarta,");
    }
    if(dia2 == 4){
        printf("Quarta]");
    }
    if(dia1 == 5){
        printf("[Quinta,");
    }
    if(dia2 == 5){
        printf("Quinta]");
    }
    if(dia1 == 6){
        printf("[Sexta,");
    }
    if(dia2 == 6){
        printf("Sexta]");
    }
    if(dia1 == 7){
        printf("[Sabado,");
    }
    if(dia2 == 7){
        printf("Sabado]");
    }
    if(dia2 < 1 || dia2 > 7){
        printf("Invalido]");
    } 
    printf("\n\n");
    return 0;
}

