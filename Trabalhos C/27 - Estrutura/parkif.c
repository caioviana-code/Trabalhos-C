#include "parkif.h"

int main() {

    int op;
    char *placa = malloc(10 * sizeof(char));
    veiculo vei;

    init();

    do{

        system("clear");
        printf("\n---------------------------");
        printf("\n- 1) Entrada de Veículo   -");
        printf("\n- 2) Saída de Veículo     -");
        printf("\n- 3) Visualizar Veículos  -");
        printf("\n- 0) Sair                 -");
        printf("\n---------------------------");
        printf("\n>> ");
        scanf("%i", &op);

        switch (op) {

            case 1:
                printf("\n[ENTRADA DE VEICULO]");
                printf("\n - Marca: ");
                __fpurge(stdin);
                gets(vei.marca);
                printf(" - Modelo: ");
                __fpurge(stdin);
                gets(vei.modelo);
                printf(" - Cor: ");
                __fpurge(stdin);
                gets(vei.cor);
                printf(" - Placa: ");
                __fpurge(stdin);
                gets(vei.placa);
                printf("\n[OK]");
                getchar();
                add(vei);
            break;

            case 2:
                printf("\n[SAIDA DE VEICULO]");
                printf("\n - Placa: ")/
                __fpurge(stdin);
                gets(placa);
                
                if(rem(placa) == -1){
                    printf("\n[ERRO]: Não há carro no estacionamento!");
                    __fpurge(stdin);
                    getchar();
                }
                
            break;

            case 3:
                view();
            break;
        }

    }while(op != 0);
    

    printf("\n");
    return 0;
}