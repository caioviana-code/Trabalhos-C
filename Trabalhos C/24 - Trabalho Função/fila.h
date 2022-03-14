#ifndef _FILA_
#define _FILA_

#include <stdio.h>
#include <stdlib.h>

int pf, *fila;

int INIT_FILA() {
    pf = 0;
    fila = malloc(1 * sizeof(int));
}

int ENQUEUE(int dado) {

    if(pf > 3){
        return -1;
    }
    else{
        if(pf == 0){
            INIT_FILA();
        }
        fila[pf] = dado;
        pf++;
        fila = realloc(fila, pf * sizeof(int));

        return dado;
    }
}

int DEQUEUE() {

    int a;

    if(pf == 0){
        return -1;
    }
    else{
        printf("\n[OK] Dado (%i) removido com sucesso!",fila[0]);
        for(a = 0; a < pf; a++){
            fila[a] = fila[a+1];
        }
        pf--;
        fila = realloc(fila, pf * sizeof(int));
    }

}

int VIEW_FIFO() {

    int a;

    printf("[VISUALIZAR - FILA]");
    if(pf == 0){
        printf("\n\nFILA VAZIA!\n");
    }
    else{
        printf("\nFILA:\n");
        for(a = 0; a < pf; a++){
            printf("%i ",fila[a]);
        }
    }

    __fpurge(stdin);
    getchar();
}

#endif