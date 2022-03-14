#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("\n");

    FILE *fp_alunos, *fp_disciplinas;
    char mostrar_alunos[50], mostrar_disciplinas[50];
    int lin;

    fp_alunos = fopen("alunos.txt", "a+");
    fp_disciplinas = fopen("disciplinas.txt", "a+");

    if(fp_alunos == NULL || fp_disciplinas == NULL){
        printf("[ERRO]!!!\n\n");
        return 0;
    }

    printf("ALUNOS CADASTRADOS");
    printf("\n-------------------\n");
    lin = 1;
    while(fgets(mostrar_alunos, 50, fp_alunos) != NULL){
        printf("%i | %s", lin, mostrar_alunos);
        lin++;
    }
    printf("-------------------");
    printf("\nDISCIPLINAS CADASTRADOS");
    printf("\n-------------------\n");
    lin = 1;
    while(fgets(mostrar_disciplinas, 50, fp_disciplinas) != NULL){
        printf("%i | %s", lin, mostrar_disciplinas);
        lin++;
    }
    printf("-------------------");

    fclose(fp_alunos);
    fclose(fp_disciplinas);

    printf("\n\n");
    return 0;
}