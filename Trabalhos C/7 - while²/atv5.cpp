#include <stdio.h>

int main() {

	int cont = 0;
	int n1, n2, n3, n4, n5, n6, aux;

	printf("Numeros: ");
	scanf("%i %i %i %i %i %i", &n1, &n2, &n3, &n4, &n5, &n6);

	while(n1 > n2 || n2 > n3 || n3 > n4 || n4 > n5 || n5 > n6) {
		if(n1 > n2) {
			aux = n1;
			n1 = n2;
			n2 = aux;
		}
		if(n2 > n3) {
			aux = n2;
			n2 = n3;
			n3 = aux;
		}
		if(n3 > n4) {
			aux = n3;
			n3 = n4;
			n4 = aux;
		}
		if(n4 > n5) {
			aux = n4;
			n4 = n5;
			n5 = aux;
		}
		if(n5 > n6) {
			aux = n5;
			n5 = n6;
			n6 = aux;
		}
	}
	printf("- Ordenado: %i %i %i %i %i %i", n1, n2, n3, n4, n5, n6);

	printf("\n");
	return 0;
}