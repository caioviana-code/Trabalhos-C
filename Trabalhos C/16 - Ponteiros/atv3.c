#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int main() {

    int a, pos, t1, t2;
    char *p1, *p2, *conc;

    printf("\nDigite os dois tamanhos: ");
    scanf("%i %i", &t1, &t2);

    p1 = malloc(t1 * sizeof(char));
    p2 = malloc(t2 * sizeof(char));
    conc = malloc((t1+t2+2) * sizeof(char));

    printf("Digite a primeira palavra: ");
    fflush(stdin);
    gets(p1);
    printf("Digite a segunda palavra: ");
    fflush(stdin);
    gets(p2);

    for(a=0, pos=0; p1[a] != '\0'; a++, pos++){
        conc[pos] = p1[a];
    }
    conc[pos] = '-';
    pos++;

    for(a=0; p2[a] != '\0'; a++, pos++){
        conc[pos] = p2[a];
    }
    conc[pos] = '\0';

    printf(" - Concatenada = %s", conc);
   
    printf("\n\n");
    return 0;
}
