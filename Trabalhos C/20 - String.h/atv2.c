#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int tam1, tam2, tam3;
    char *n1 = malloc(30 * sizeof(char));
    char *n2 = malloc(30 * sizeof(char));
    char *n3 = malloc(30 * sizeof(char));

    printf("\nDigite três nomes:\n");
    gets(n1);
    gets(n2);
    gets(n3);

    tam1 = strlen(n1);
    tam2 = strlen(n2);
    tam3 = strlen(n3);

    printf("\n - Ordem Crescente: ");
    if(tam1 <= tam2 && tam1 <= tam3){
        printf("%s-",n1);
        if(tam2 <= tam3){
            printf("%s-",n2);
            printf("%s",n3);
        }
        else{
            printf("%s-",n3);
            printf("%s",n2);
        }
    }

    else if(tam2 <= tam1 && tam2 <= tam3){
        printf("%s-",n2);
        if(tam1 <= tam3){
            printf("%s-",n1);
            printf("%s",n3);
        }
        else{
            printf("%s-",n3);
            printf("%s",n1);
        }
    }

    else if(tam3 <= tam2 && tam3 <= tam1){
        printf("%s-",n3);
        if(tam1 <= tam2){
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