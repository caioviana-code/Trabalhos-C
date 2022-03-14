#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastrarAlunos();
int cadastrarDisciplinas();
int visualizarAlunosDisciplinas();
int matricularAluno();
int visualizarMatricula();

int main() {

    printf("\n");

    int fim, num;

    fim = 1;

    do{

        system("clear");
        printf("--------------------------------------");
        printf("\n(1) - Cadastrar Aluno");
        printf("\n(2) - Cadastrar Disciplina");
        printf("\n(3) - Visualizar Alunos e Disciplinas");
        printf("\n(4) - Matricular Aluno");
        printf("\n(5) - Visualizar Matrículas");
        printf("\n(0) - Sair");
        printf("\n--------------------------------------");
        printf("\nOpção: ");
        scanf("%i", &num);
        printf("--------------------------------------\n\n");

        switch(num){

            case 0:
                printf("[Tchau]");
                fim = 0;
            break;

            case 1:
                cadastrarAlunos();
            break;

            case 2:
                cadastrarDisciplinas();
            break;

            case 3:
                visualizarAlunosDisciplinas();
            break;

            case 4:
                matricularAluno();
            break;

            case 5:
                visualizarMatricula();
            break;
        }

    }while(fim != 0);

    printf("\n\n");
    return 0;
}

int cadastrarAlunos() {

    getchar();
    char nome[50];
    FILE *fp;

    fp = fopen("alunos.txt", "a+");
    
    if(fp == NULL){
        printf("[ERRO]!!!\n\n");
        return 0;
    }

    printf("Aluno: ");
    fflush(stdin);
    gets(nome);

    fputs(nome, fp);
    fputs("\n", fp);

    system("clear");

    fclose(fp);
    

}

int cadastrarDisciplinas() {

    getchar();
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

    system("clear");

    fclose(fp);

}

int visualizarAlunosDisciplinas() {

    getchar();
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
    getchar();
    system("clear");
}

int matricularAluno() {

    FILE *fp_aluno, *fp_disciplina, *fp_matricula;
    int lin_aluno, lin_disciplina, cont;
    char nome_aluno, nome_disciplina;

    fp_aluno = fopen("alunos.txt", "a+");
    fp_disciplina = fopen("disciplinas.txt", "a+");
    fp_matricula = fopen("matriculas.txt", "a+");

    if(fp_aluno == NULL || fp_disciplina == NULL || fp_matricula == NULL){
        printf("[ERRO]!!!\n\n");
        return 0;
    }

    printf("- Linha Aluno: ");
    scanf("%i", &lin_aluno);
    printf("- Linha Disciplina: ");
    scanf("%i", &lin_disciplina);

    cont = 1;
    do{

        nome_aluno = fgetc(fp_aluno);

        if(cont == lin_aluno){
            if(nome_aluno != '\n'){
                fputc(nome_aluno, fp_matricula);
            }    
        }

        if(nome_aluno == '\n'){
            cont++;
        }

    }while(nome_aluno != EOF);
    fputs("<=>", fp_matricula);
    cont = 1;
    do{

        nome_disciplina = fgetc(fp_disciplina);

        if(cont == lin_disciplina){
            if(nome_disciplina != '\n'){
                fputc(nome_disciplina, fp_matricula);
            }    
        }

        if(nome_disciplina == '\n'){
            cont++;
        }

    }while(nome_disciplina != EOF);
    fputc('\n', fp_matricula);

    printf("\n[OK]");
    getchar();
    getchar();

    fclose(fp_aluno);
    fclose(fp_disciplina);
    fclose(fp_matricula);

}

int visualizarMatricula() {

    FILE *fp_matricula;
    char mostrar_matricula[100];
    int lin;

    fp_matricula = fopen("matriculas.txt", "a+");

    if(fp_matricula == NULL){
        printf("[ERRO]!!!");
        return 0;
    }

    printf("MATRÍCULAS EFETUADAS");
    printf("\n-------------------\n");
    lin = 1;
    while(fgets(mostrar_matricula, 100, fp_matricula) != NULL){
        printf("%i | %s", lin, mostrar_matricula);
        lin++;
    }
    printf("-------------------");

    fclose(fp_matricula);
    getchar();
    getchar();
    system("clear");
}


