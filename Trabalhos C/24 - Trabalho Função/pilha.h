#ifndef _PILHA_
#define _PILHA_

#include <stdio.h>
#include <stdlib.h>

int pp, *pilha;

int INIT_PILHA() {
    pp = 0;
    pilha = malloc(1 * sizeof(int));
}

int PUSH(int dado) {

    if(pp > 3){
        return -1;
    }
    else{
        if(pp == 0){
            INIT_PILHA();
        }
        pilha[pp] = dado;
        pp++;
        pilha = realloc(pilha, pp * sizeof(int));

        return dado;
    }
    
}

int POP() {

    if(pp == 0){
        return -1;
    }
    else{
        printf("\n[OK] Dado (%i) removido com sucesso!",pilha[pp-1]);
        pp--;
        pilha = realloc(pilha, pp *sizeof(int));

    }

}

void VIEW_LIFO() {

    int a;

    printf("[VISUALIZAR - PILHA]");
    if(pp == 0){
        printf("\n\nPILHA VAZIA!\n");
    }
    else{
        printf("\nPILHA:\n");
        for(a = pp-1; a >= 0; a--){
            printf("%i\n",pilha[a]);
        }
    }
    
    __fpurge(stdin);
    getchar();
}

#endif