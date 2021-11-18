#include <stdio.h>

int main() {

    printf("\n");

    int n1, n2, cont, soma = 0;

    printf("Digite dois numeros inteiros: ");
    scanf("%i %i", &n1, &n2);

    printf("%i = %i",n1,n1);

    for(cont = n1 + 1; cont < n2 + 1; cont++){
        soma = n1 + cont;
        printf("\n%i + %i = %i",n1,cont,soma);
        n1 = soma;
    }

    printf("\n\n");
    return 0;
}