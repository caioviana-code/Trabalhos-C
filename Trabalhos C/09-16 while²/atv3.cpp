#include <stdio.h>

int main(){

    printf("\n");
    int base, topo, cont1, cont2, cont3, linhas, esp;

    printf("Base e Topo: ");
    scanf("%i %i", &base, &topo);
    printf("\n");

    cont1 = 0;
    esp = base - topo;
    linhas = base - topo + 1;

    while(cont1 < linhas){
        cont2 = 0;
        cont3 = 0;
        
        while(cont3 < esp){
            printf(" ");
            cont3++;
        }
        
        while(cont2 < topo){
            printf("* ");
            cont2++;
        }
        printf("\n");
        
        cont1++;
        topo++;
        esp = esp - 1;
    }

    
    printf("\n\n");
    return 0;
}