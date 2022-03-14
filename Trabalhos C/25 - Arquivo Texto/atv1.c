#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("\n");
    char nome[50];
    FILE *fp;

    fp = fopen("alunos.txt", "a+");
    
    if(fp == NULL){
        printf("[ERRO]!!!\n\n");
    }

    printf("Aluno: ");
    fflush(stdin);
    gets(nome);

    fputs(nome, fp);
    fputs("\n", fp);

    fclose(fp);

    printf("\n\n");
    return 0;
}