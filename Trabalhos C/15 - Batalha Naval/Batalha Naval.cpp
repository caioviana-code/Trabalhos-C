#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define preto        "\33[30m"
#define vermelho     "\33[31m"
#define verde        "\33[32m"
#define amarelo      "\33[33m"
#define azulclaro    "\33[36m"
#define roxo         "\33[35m"
#define azulescuro   "\33[34m"
#define branco       "\33[37m"

#define TAM 5

int main() {

    srand(time(NULL));

    int fim, jogador, erro, pont_player, pont_computer, mat[TAM][TAM], espelho[TAM][TAM];
    int l, c, cont, flag = 0, num = 0, lin, col;

    // preencher asteriscos
    for(l = 0; l < TAM; l++){
        //printf("\n");
        for(c = 0; c < TAM; c++){
            espelho[l][c] = '#';
            mat[l][c] = 0;
            //printf("%c ",espelho[l][c]);
        }
    }

    // Submarinos
    for(cont = 0; cont < 8; cont++){
        l = rand()%TAM;
        c = rand()%TAM;
        if(mat[l][c] == 0){
            mat[l][c] = 1;
        }
        else{
            cont--;
        }
    }

    // Navios Tanque
    for(cont = 0; cont < 5; cont++){
        l = rand()%TAM;
        c = rand()%TAM;
        if(mat[l][c] == 0){
            mat[l][c] = 3;
        }
        else{
            cont--;
        }
    }

    // Porta Aviões
    for(cont = 0; cont < 2; cont++){
        l = rand()%TAM;
        c = rand()%TAM;
        if(mat[l][c] == 0){
            mat[l][c] = 5;
        }
        else{
            cont--;
        }
    }

   fim = 0;
   pont_computer = 0;
   pont_player = 0;
   jogador = 1;

    do{

        if(fim == 8){
            fim++;
        }

        printf("---------------------------------");
        printf("\n--------- %sBATALHA NAVAL%s ---------",azulescuro,branco);
        printf("\n---------------------------------");
        printf("\n        | 0 | 1 | 2 | 3 | 4 |");
        for(l = 0; l < TAM; l++){
            printf("\n");
            printf("    | %i ",num);
            for(c = 0; c < TAM; c++){
                if(espelho[l][c] == '#'){
                    printf("| %c ",espelho[l][c]);
                }
                else{
                    printf("| %i ",mat[l][c]);
                }    
            }
            if(num <= 4){
                num++;
                if(num == 5){
                    num = 0;
                }
            }
            printf("|");
        }
        printf("\n---------------------------------");
        printf("\n--- %sPlayer:  %i%s | %sComputer:  %i%s ---",roxo,pont_player,branco,verde,pont_computer,branco);
        printf("\n---------------------------------");

        if(fim != 9){

            // Player
            if(jogador == 1){

                erro = 1;
                while(erro == 1){
                    printf("\n%s[Player]:%s ",roxo,branco);
                    fflush(stdin);
                    scanf("%i %i",&lin,&col);

                    if(lin < 0 || lin > 4 || col < 0 || col > 4){
                        erro = 1;
                        printf("%s---------Jogada Invalida---------%s",vermelho,branco);
                    }
                    else if(espelho[lin][col] != '#'){
                        erro == 1;
                        printf("%s---------Jogada Invalida---------%s",vermelho,branco);
                    }
                    else{
                        pont_player = pont_player + mat[lin][col];
                        espelho[lin][col] = mat[lin][col];
                        erro = 0;
                        jogador = 0;
                        fim++;
                        system("cls");
                    }
                }

            }
            // Computer
            else{

                erro = 1;
                printf("\n%s[Computer]:%s ",verde,branco);
                while(erro == 1){
                    lin = rand()%TAM;
                    col = rand()%TAM;
                    if(espelho[lin][col] != '#'){
                        lin = rand()%TAM;
                        col = rand()%TAM;
                        erro = 1;
                    }
                    else{
                        printf("%i %i",lin,col);
                        fflush(stdout);
                        Sleep(3000);
                        pont_computer = pont_computer + mat[lin][col];
                        espelho[lin][col] = mat[lin][col];
                        erro = 0;
                        jogador = 1;
                        fim++;
                        system("cls");
                    }
                }

            }

        }

   }while(fim != 9);

   if(pont_player > pont_computer){
       printf("\n-------- %sPLAYER VENCEU%s ----------",roxo,branco);
       printf("\n---------------------------------");
   }
   else if(pont_player == pont_computer){
       printf("\n----------- %sEMPATE%s -----------",azulclaro,branco);
       printf("\n---------------------------------");
   }
   else{
       printf("\n------  %sCOMPUTER VENCEU%s ---------",verde,branco);
       printf("\n---------------------------------");
   }

    printf("\n\n");
    return 0;
}