#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("\n");
    char disciplinas[50];
    FILE *fp;

    fp = fopen("disciplinas.txt", "a+");
    
    if(fp == NULL){
        printf("[ERRO]!!!\n\n");
        return 0;
    }

    printf("Disciplina: ");
    fflush(stdin);
    gets(disciplinas);

    fputs(disciplinas, fp);
    fputs("\n", fp);

    fclose(fp);

    printf("\n\n");
    return 0;
}