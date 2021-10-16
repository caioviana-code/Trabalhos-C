#include <stdio.h>

int main() {

    int numero, n1, n2 ,n3, resultado;

    printf("Digite um numero (3 digitos) :");
    scanf("%i", &numero);

    n1 = numero/100;
	n2 = (numero%100)/10;
	n3 = numero%10;
	resultado = n1+n2+n3;
    
    printf("- Soma = %i + %i + %i = %i", n1, n2, n3, resultado);
    
    return 0;
}