#ifndef _PARKIF_
#define _PARKIF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char marca[30];
    char modelo[30];
    char cor[20];
    char placa[10];
} veiculo;

FILE *fp;

void init() {
    fp = fopen("db.bin", "a+");
}

void add(veiculo v) {
    fp = fopen("db.bin", "a+");

    if(fp != NULL){
        fwrite(&v, sizeof(veiculo), 1, fp);
    }   

    fclose(fp);
}

int rem(char *placa) {
    FILE *fp_backup;
    int retorno, a, flag = 1;
    veiculo car;

    fp = fopen("db.bin", "a+");

    retorno = fread(&car, sizeof(veiculo), 1, fp);

    if(retorno == 0){
        return -1;
    }

    else{

        fp_backup = fopen("backup.bin", "a+");

        if(fp != NULL && fp_backup != NULL){

            while(retorno == 1){
                if(strcmp(car.placa, placa) == 0){
                    retorno = fread(&car, sizeof(veiculo), 1, fp);
                    flag = 0;
                }
                else{
                    fwrite(&car, sizeof(veiculo), 1, fp_backup);
                    retorno = fread(&car, sizeof(veiculo), 1, fp);

                }        
            }

            if(flag == 1){
                fclose(fp);
                remove("db.bin");
                fclose(fp_backup);
                rename("backup.bin", "db.bin");
                return -2;
            }
            else{
                fclose(fp);
                remove("db.bin");
                fclose(fp_backup);
                rename("backup.bin", "db.bin");
                return 0;
            }
           
        }

    }
}

void view() {
    
    fp = fopen("db.bin", "a+");

    int a, retorno, lin = 1;
    veiculo car;

    if(fp != NULL){

        printf("\n[VISUALIZAÇÃO DE VEICULOS]\n");

        retorno = fread(&car ,sizeof(veiculo), 1, fp);

        if(retorno == 0){
            printf("\n[ERRO]: Não há carros no estacionamento");
        }

        while(retorno == 1){

            if(retorno == 1){
                printf("%i | %s / %s / %s / %s\n",lin, car.marca, car.modelo, car.cor, car.placa);
                lin++;
            }

            retorno = fread(&car ,sizeof(veiculo), 1, fp);
            
        }

        printf("\n[OK]");
        __fpurge(stdin);
        getchar();
        fclose(fp);
    }

}

#endif
