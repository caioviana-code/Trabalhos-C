#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *n1 = malloc(30 * sizeof(char));
    char *n2 = malloc(30 * sizeof(char));
    char *n3 = malloc(30 * sizeof(char));

    printf("\nDigite três palavras:\n");
    gets(n1);
    gets(n2);
    gets(n3);

    strcat(n1, n2);
    strcat(n1, n3);

    printf("\n - Concatenado: %s",n1);
    printf("\n\n");
    return 0;
}