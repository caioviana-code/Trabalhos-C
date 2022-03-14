#include "pilha.h"
#include "fila.h"

int main() {

    int op = -1, val;

    INIT_PILHA();
    INIT_FILA();

    while(op != 0){
        system("clear");
        printf("\n------------------------------");
        printf("\n1 - Inserir dados na pilha");
        printf("\n2 - Inserir dados na fila");
        printf("\n3 - Remover dados da pilha");
        printf("\n4 - Remover dados da fila");
        printf("\n5 - Visualizar os dados da pilha");
        printf("\n6 - Visualizar os dados da fila");
        printf("\n0 - Sair");
        printf("\n------------------------------");
        printf("\n> ");
        scanf("%i", &op);

        switch(op) {

            // PUSH
            case 1:
                printf("[INSERIR - PILHA]");
                printf("\nValor: ");
                scanf("%i", &val);

                if(PUSH(val) == val){
                    printf("\n[OK] Dado inserido com sucesso!");
                }
                else{
                    printf("\n[ERRO] Pilha Cheia!");
                }

                __fpurge(stdin);
                getchar();
            break;

            // ENQUEUE
            case 2:
                printf("[INSERIR - FILA]");
                printf("\nValor: ");
                scanf("%i", &val);

                if(ENQUEUE(val) == val){
                    printf("\n[OK] Dado inserido com sucesso!");
                }
                else{
                    printf("\n[ERRO] Fila Cheia!");
                }

                __fpurge(stdin);
                getchar();
            break;

            // POP
            case 3:
                printf("[REMOVER - PILHA]");

                if(POP() == -1){
                    printf("\n[ERRO] Pilha Vazia!");
                }

                __fpurge(stdin);
                getchar();  
            break;

            // DEQUEUE
            case 4:
                printf("[REMOVER - FILA]");

                if(DEQUEUE() == -1){
                    printf("\n[ERRO] Fila Vazia!");
                }

                __fpurge(stdin);
                getchar();
            break;

            // VIEW_LIFO
            case 5:
                VIEW_LIFO();
            break;

            // VIEW_FIFO
            case 6:
                VIEW_FIFO();
            break;
        }
    }

    printf("\n\n");
    return 0;
}