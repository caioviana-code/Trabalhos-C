#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *n1 = malloc(30 * sizeof(char));
    char *n2 = malloc(30 * sizeof(char));
    char *n3 = malloc(30 * sizeof(char));

    printf("\nDigite três nomes:\n");
    fflush(stdin);
    gets(n1);
    gets(n2);
    gets(n3);

    printf("\n - Ordem Alfabética: ");
    if(strcmp(n1, n2) < 0 && strcmp(n1, n3) < 0){
        printf("%s-",n1);
        if(strcmp(n2, n3) < 0){
            printf("%s-",n2);
            printf("%s",n3);
        }
        else{
            printf("%s-",n3);
            printf("%s",n2);
        }
    }

    else if(strcmp(n2, n3) < 0 && strcmp(n2 ,n1)){
        printf("%s-",n2);
        if(strcmp(n1, n3) < 0){
            printf("%s-",n1);
            printf("%s",n3);
        }
        else{
            printf("%s-",n3);
            printf("%s",n1);
        }
    }

    else if(strcmp(n3, n1) < 0 && strcmp(n3, n2) < 0){
        printf("%s-",n3);
        if(strcmp(n1, n2) < 0){
            printf("%s-",n1);
            printf("%s",n2);
        }
        else{
            printf("%s-",n2);
            printf("%s",n1);
        }
    }

    printf("\n\n");
    return 0;
}

