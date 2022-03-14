#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *p1, *p2, *p3;
    int a, cont = 0, qtde = 0;

    p1 = malloc(20 * sizeof(char));
    p2 = malloc(20 * sizeof(char));
    p3 = malloc(20 * sizeof(char));
   
    printf("\nDigite duas palavras:\n");
    fflush(stdin);
    gets(p1);
    gets(p2);

    for(a=0; a<20; a++){
        if(p1[a] == p2[a]){
            cont++;
            p3[a] = p1[a];
        }
        if(strncmp(p1,p2,a) == 0){
           qtde++;
        }
    }

    printf("- Letras iguais: %i / %s",qtde-1, p3);

    printf("\n\n");
    return 0;
}