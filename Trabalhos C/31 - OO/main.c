#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int vetorAposta[6], vetorSorteio[6];
    int acertos;

    acertos = 0;

    // Gerando números aleatórios
    for(int i = 0; i < 6; i++) {

        vetorSorteio[i] = 1 + rand() % 60;

        for(int teste = 0; teste < i; teste++) {

            if(vetorSorteio[teste] == vetorSorteio[i]) {
                
                i--;
                teste = i; // sai do laço
            }
        }
    }
  
    // Pegando números do usuário
    for (int i = 0; i < 6; i++) {

        system("clear");
        printf("\n\nDigite %i número(s) únicos: \n> ", 6-i);
        scanf("%i", &vetorAposta[i]);

        for(int teste = 0; teste < i; teste++) {

            if(vetorAposta[i] < 1 || vetorAposta[i] > 60) {         // Número Invalido

                printf("\n[ERRO]: Número Inválido");
                __fpurge(stdin);
                getchar();
                i--;
                teste = i; // Sai do laço
            } else if(vetorAposta[teste] == vetorAposta[i]) {           // Número Repetido

                printf("\n[ERRO]: Número repetido");
                __fpurge(stdin);
                getchar();
                i--;
                teste = i; // sai do laço
            }
        }
    }

    // verificando acertos
    for(int a = 0; a < 6; a++) {

        for(int b = 0; b < 6; b++) {

            if(vetorAposta[b] == vetorSorteio[a]) {

                acertos++;
            }
        }
    }

    system("clear");
    printf("\nOs números sorteados são: ");
    for(int i = 0; i < 6; i++) {

        printf("%i ",vetorSorteio[i]);

    }

    printf("\nOs números apostados são: ");
    for(int i = 0; i < 6; i++) {

        printf("%i ",vetorAposta[i]);

    }

    printf("\nNúmeros acertados: %i", acertos);

    switch (acertos) {

        case 4:
            printf("\n\nFez a Quadra");
            __fpurge(stdin);
            getchar();
        break;

        case 5:
            printf("\n\nFez a Quina");
            __fpurge(stdin);
            getchar();
        break;

        case 6:
            printf("\n\nFicou rico!! Fez a sena");
            __fpurge(stdin);
            getchar();
        break;

        default:
            printf("\n\nNão ganhou nada, mais sorte na próxima");
            __fpurge(stdin);
            getchar();
        break;
    }

    printf("\n");
    return 0;
}