#include <stdio.h>

int main(){

    int opcao;

    do{
        printf("\n\n1 - Saque");
        printf("\n2 - Deposito");
        printf("\n3 - Transferencia");
        printf("\n4 - Extrato");
        printf("\n5 - Sair \n>");
        scanf("%i", &opcao);

        if(opcao == 1){
            printf("[SAQUE]");
        }
        if(opcao == 2 ){
            printf("[DEPOSITO]");
        }
        if(opcao == 3){
            printf("[TRANSFERENCIA]");
        }
        if(opcao == 4){
            printf("[EXTRATO]");
        }
        if(opcao == 5){
            printf("[SAIR]");
        }
       
    }while(opcao != 5);

    printf("\n\n");
    return 0;
}