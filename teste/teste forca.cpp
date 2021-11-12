#include <stdio.h>
#include <stdlib.h>

#define TAM 30

int main() {

    int a, op;
    int fim, erros, dicas, flag, flag2, win, lose;
    char palavra[TAM], dica1[TAM], dica2[TAM], espelho[TAM], letra, resposta[TAM];

    // Inicio
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

    for(a = 0; palavra[a] != '\0'; a++){
        espelho[a] = '_';
    }
    espelho[a] = '\0';

    // Começa o jogo
    fim = 0;
    erros = 0;
    dicas = 0;
    win = 0;
    lose = 0;

    do{
        system("cls");
        printf("\n\t\t\tFORCA");
        printf("\n\n\tTotal de Erros: %i | Dicas Disponiveis: %i",erros,2 - dicas);
        if(dicas > 0){
            printf("\n\n\t1 Dica: [%s]",dica1);
        }
        if(dicas > 1){
            printf("\n\t2 Dica: [%s]",dica2);
        }

        printf("\n\n\tPalavra: ");
        for(a = 0; palavra[a] != '\0';a++){
            if(fim == 0){
                printf("%c ",espelho[a]);
            }
            else if(fim == 1){
                printf("%c ",palavra[a]);
            }
        }
    
        if(fim == 0){
            
            printf("\n\n\t1) Efetuar jogada");
            printf("\n\t2) Solicitar dica");
            printf("\n\t3) Advinhar palavra");
            printf("\n\t4) Visualizar forca");
            printf("\n\n> ");
            fflush(stdin);
            scanf("%i",&op);

            switch(op){
                
                // Efetuar jogada
                case 1:
                    printf("> Digite uma letra (a-z): ");
                    fflush(stdin);
                    scanf("%c", &letra);
                    
                    if(letra <= 90){
                        letra = letra - 32;
                    }

                    flag = 0;
                    flag2 = 0;
                    for(a = 0; palavra[a] != '\0'; a++){
                        if(palavra[a] == letra){
                            espelho[a] = palavra[a];
                            flag = 1;
                        }
                    }

                    for(a = 0; palavra[a] != '\0'; a++){
                        if(palavra[a] != espelho[a]){
                            flag2 = 1;
                        }
                    }

                    if(flag == 0){
                        erros++;
                        if(erros == 4){
                            fim = 1;
                            lose = 1;
                        }
                    }

                    if(flag2 == 0){
                        fim = 1;
                        win = 1;
                    }
                    break;
                    
                // Solicitar dica
                case 2:
                    if(dicas < 2){
                        dicas++;
                    }
                    break;

                // Adivinhar palavra
                case 3:
                    printf("> Digite a palavra: ");
                    fflush(stdin);
                    gets(resposta);

                    flag = 1;
                    for(a = 0; palavra[a] != '\0'; a++){
                        if(palavra[a] != resposta[a]){
                            flag = 0;
                        }
                    }

                    if(flag == 1){
                        fim = 1;
                        win = 1;
                    }
                    else{
                        fim = 1;
                        lose = 1;
                    }
                    break;

                    // Visualizar forca
                    case 4:
                        if(erros > 0){
                            printf("\t\t\t ___");
                            printf("\n\t\t\t  0 ");
                        }
                        if(erros == 2){
                            printf("\n\t\t\t  | ");
                            printf("\n\t\t\t  | ");
                        }
                        else if(erros == 3){
                            printf("\n\t\t\t /|%c ", 92);
                            printf("\n\t\t\t  | ");
                        }
                        else if(erros > 4){
                            printf("\n\t\t\t /  %c ", 92);
                        }
                        fflush(stdin);
                        getchar();
                        break;
            }

            
        }

    }while(fim != 1);

    if(win == 1){
        printf("\n\t\t\tVOCE VENCEU!!!");
    }
    else if(lose == 1){
        printf("\n\t\t\tVOCE PERDEU!!!");
    }



    printf("\n\n");
    return 0;
}