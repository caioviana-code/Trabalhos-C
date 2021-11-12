#include <stdio.h>
#include <stdlib.h>

#define TAM 30

int main() {

    int a, op, dicas, fim, erros, win, lose, flag, flag2;
    char palavra[TAM], dica1[TAM], dica2[TAM], espelho[TAM], resposta[TAM], letra;

    system("cls");
    printf("Palavra: ");
    fflush(stdin);
    gets(palavra);
    printf("1 Dica: ");
    fflush(stdin);
    gets(dica1);
    printf("2 Dica: ");
    fflush(stdin);
    gets(dica2);

    dicas = 0;
    fim = 0;
    erros = 0;
    win = 0;
    lose = 0;

    for(a = 0; palavra[a] != '\0'; a++){
        espelho[a] = '_';
    }
    espelho[a] = '\0';

    do{

        flag2 = 0;
        for(a = 0; palavra[a] != '\0'; a++){
            if(palavra[a] != espelho[a]){
                flag2 = 1;
            }
        }

        if(flag2 == 0){
            win = 1;
        }

        if(win == 1 || lose == 1){
            fim = 1;
        }
        
        system("cls");
        printf("\n\n\t\t\tFORCA");
        printf("\n\n\tTotal de erros: %i | Dicas Disponiveis: %i",erros, 2 - dicas);
        if(dicas > 0){
            printf("\n\n\t1 Dica: [%s]",dica1);
        }
        if(dicas > 1){
            printf("\n\t2 Dica: [%s]",dica2);
        }
        printf("\n\n\tPalavra: ");
        for(a = 0; palavra[a] != '\0'; a++){
            if(fim == 0){
                printf("%c ", espelho[a]);
            }
            else{
                printf("%c ", palavra[a]);
            }
        }
        printf("\n\n\t1) Efetuar jogada");
        printf("\n\t2) Solicitar dica");
        printf("\n\t3) Advinhar palavra");
        printf("\n\t4) Visualizar forca");

        if(fim == 0){

            printf("\n> ");
            fflush(stdin);
            scanf("%i", &op);

            switch(op){

                // Efetuar jogada
                case 1:
                    printf("> Digite uma letra(a-z): ");
                    fflush(stdin);
                    scanf("%c", &letra);

                    // Letra Minúscula
                    if(letra <= 90){
                        letra = letra - 32;
                    }

                    flag = 0;
                    for(a = 0; palavra[a] != '\0'; a++){
                        if(palavra[a] == letra){
                            espelho[a] = palavra[a];
                            flag = 1;
                        }
                    }

                    if(flag == 0){
                        erros++;
                        if(erros == 4){
                            lose = 1;
                        }
                    }

                    break;

                // Solicitar dica
                case 2:
                    if(dicas < 2){
                        dicas++;
                    }
                    break;
                
                // Advinhar palavra
                case 3:
                    printf("> Digite a palavra: ");
                    fflush(stdin);
                    gets(resposta);

                    flag = 0;
                    for(a = 0; palavra[a] != '\0'; a++){
                        if(resposta[a] != palavra[a]){
                            flag = 1;
                        }
                    }

                    if(flag == 1){
                        lose = 1;
                    }
                    else{
                        win = 1;
                    }
                    break;

                case 4:
                    if(erros > 0){
                        printf("\n\t\t\t ___ ");
                        printf("\n\t\t\t  0 ");
                    }
                    if( erros == 2){
                        printf("\n\t\t\t  | ");
                        printf("\n\t\t\t  | ");
                    }
                    else if( erros == 3){
                        printf("\n\t\t\t /|%c ",92);
                        printf("\n\t\t\t  | ");
                    }
                    else if( erros == 4){
                        printf("\n\t\t\t /|%c ",92);
                        printf("\n\t\t\t  | ");
                        printf("\n\t\t\t / %c ",92);
                    }
                    fflush(stdin);
                    getchar();
                    break;
            }    
        }

    }while(fim != 1);

    if(win == 1){
        printf("\n\n\t\t\tVoce Ganhou!!!");
    }
    else{
        printf("\n\n\t\t\tVoce perdeu!!!");
    }

    printf("\n\n");
    return 0;
}