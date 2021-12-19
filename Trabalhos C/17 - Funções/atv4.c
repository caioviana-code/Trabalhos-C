#include <stdlib.h>
#include <stdio.h>

void ordenar(char c1, char c2, char c3, char c4, char c5);

int main() {

    char c1, c2, c3, c4, c5;

    printf("\nDigite cinco letras: ");
    scanf("%c %c %c %c %c",&c1, &c2, &c3, &c4, &c5);

    ordenar(c1,c2,c3,c4,c5);

    printf("\n\n");
    return 0;
}

void ordenar(char c1, char c2, char c3, char c4, char c5) {

    int aux;

    if(c1 < 65 || c1 > 90){
        c1 = c1 - 32;
    }
    if(c2 < 65 || c2 > 90){
        c2 = c2 - 32;
    }
    if(c3 < 65 || c3 > 90){
        c3 = c3 - 32;
    }
    if(c4 < 65 || c4 > 90){
        c4 = c4 - 32;
    }
    if(c5 < 65 || c5 > 90){
        c5 = c5 - 32;
    }

    while(c1 > c2 || c2 > c3 || c3 > c4 || c4 > c5) {
		if(c1 > c2) {
			aux = c1;
			c1 = c2;
			c2 = aux;
		}
		if(c2 > c3) {
			aux = c2;
			c2 = c3;
			c3 = aux;
		}
		if(c3 > c4) {
			aux = c3;
			c3 = c4;
			c4 = aux;
		}
		if(c4 > c5) {
			aux = c4;
			c4 = c5;
			c5 = aux;
		}
	}
	printf("- Ordenado: %c %c %c %c %c ", c1, c2, c3, c4, c5);
}