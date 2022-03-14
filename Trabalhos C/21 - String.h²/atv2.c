#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n;
    char *p1, *p2, *p3, *conc;

    p1 = malloc(20 *sizeof(char));
    p2 = malloc(20 *sizeof(char));
    p3 = malloc(20 *sizeof(char));
    conc = malloc(60 * sizeof(char));

    printf("\nDigite o valor inteiro: ");
    scanf("%i", &n);
    getchar();
    printf("Digite três palavras:\n");
    fflush(stdin);
    gets(p1);
    fflush(stdin);
    gets(p2);
    fflush(stdin);
    gets(p3);

    conc = strncpy(conc,p1,n);
    conc = strncat(conc,p2,n);
    conc = strncat(conc,p3,n);

    printf("\n - Concatenado: %s",conc);
    printf("\n\n");
    return 0;
}