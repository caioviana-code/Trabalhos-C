#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;
    char *arquivo, *sequencia, op, c;
    int i, a, b, d, cont_ponteiro, cont_sequencia, cont;

    do{
        
        cont_sequencia = 0;
        cont_ponteiro = 0;
        
        fp = fopen("covid.txt", "a+");

        // Testa se o arquivo foi aberto
        if(fp == NULL){
            printf("[ERRO]!!!\n\n");
            return 0;
        }

        // Iniciando ponteiro
        sequencia = malloc(99 * sizeof(char));

        // Joga o conteúdo do arquivo em um vetor
        i = 0;
        arquivo = malloc(1 * sizeof(char));
        do{
            c = fgetc(fp);
            if(c == '\n'){
                c = fgetc(fp);
                arquivo[i] = c;
                i++;
            }
            else{
                arquivo[i] = c;
                i++;
            }
            
            arquivo = realloc(arquivo, (1+i) * sizeof(char));

        }while(c != EOF);
        arquivo[1+i] = '\0';

        system("clear");
        printf("\n---------------------------------");
        printf("\n- Bases Nitrogenadas => A U C G -");
        printf("\n---------------------------------");
        printf("\n- Digite a sequência: ");
        __fpurge(stdin);
        gets(sequencia);

        // Converte para Maiusculas
        for(a = 0; sequencia[a] != '\0'; a++){
            if(sequencia[a] < 65 || sequencia[a] > 90){
                sequencia[a] = sequencia[a] - 32;
            }
        }

        printf("- Buscando(%s)...",sequencia);

        // Conta quantas letras tem na sequência
        for(a = 0; sequencia[a] != '\0'; a++){
            cont_ponteiro++;
        }

        // Realoca o ponteiro para a quantidade certa de letras
        sequencia = realloc(sequencia, cont_ponteiro * sizeof(char));
        
        // Lógica

        for(a = 0; arquivo[a] != '\0'; a++){

            cont = 0;
            if(arquivo[a] == sequencia[0]){

                for(b = 0, d = a; sequencia[b] != '\0'; b++){

                    if(arquivo[d] == sequencia[b]){
                        d++;
                        cont++;
                    }
                }

                if(cont == cont_ponteiro){
                    cont_sequencia++;
                }
            }
            
        }

        printf("\n- Total de ocorrências [%s] = %i",sequencia,cont_sequencia);
        sleep(3);
        printf("\n---------------------------------");
        printf("\n\nDeseja efetuar uma nova análise (s) ou (n)? ");
        scanf("%c", &op);

        fclose(fp);

    }while(op != 'n');

    printf("\n\n");
    return 0;
}