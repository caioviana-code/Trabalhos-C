#ifndef _PARKIF_
#define _PARKIF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char marca[50];
    char modelo[50];
    char cor[20];
    char placa[10];
} veiculo;

veiculo *db;
int pos;

void init() {
    pos = 0;
    db = malloc(1 * sizeof(veiculo));
}

void add(veiculo v) {
    
    if(pos == 0){
        init();
    }

    db[pos] = v;
    pos++;
    db = realloc(db, (pos+1) * sizeof(veiculo));
    
}

int rem(char *placa) {

    int i, a, j, seq;

    j = 0;
    seq = 0;

    if(pos == 0){
        return -1;
    }

    for(i = 0; i < pos; i++){

        do{

            if(placa[j] == db[i].placa[j]){
                seq++;
            }
            j++;

            if(seq == 8){

                do{
                    db[i] = db[i+1];
                    i++;
                }while(i < pos);

                pos--;
                db = realloc(db, pos * sizeof(veiculo));
                printf("\n[OK]");
                __fpurge(stdin);
                getchar();
                return 0;
            }

        }while(placa[j] == db[i].placa[j]);
    }

    printf("\n[ERRO]: Placa não encontrada!");
    __fpurge(stdin);
    getchar();
    return -2;
    
}

void view() {

    int a, lin = 1;

    printf("\n[VISUALIZAÇAO DE VEICULOS]\n");
    for(a=0; a<pos; a++){
        printf("%i | %s / %s / %s / %s\n",lin, db[a].marca, db[a].modelo, db[a].cor, db[a].placa);
        lin++;
    }
    if(pos == 0){
        printf("\nNão há carros no estacionamento!\n");
    }
    printf("\n[OK]");
    __fpurge(stdin);
    getchar();
    
}

#endif