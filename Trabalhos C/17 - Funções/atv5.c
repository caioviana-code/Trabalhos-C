#include <stdio.h>
#include <stdlib.h>

int agregar(int num1, int num2);

int main() {

    int num1, num2, soma;
    
    printf("\nDigite dois numeros com 3 digitos: ");
    scanf("%i %i", &num1, &num2);

    soma = agregar(num1,num2);

    printf("\n\n");
    return 0;
}

int agregar(int num1, int num2) {

    int c1, c2, d1, d2, u1, u2, cent, dez, uni;

    c1 = num1/100;
    d1 = (num1%100)/10;
    u1 = num1%10;

    c2 = num2/100;
    d2 = (num2%100)/10;
    u2 = num2%10;

    cent = c1 + c2; if(cent > 9){cent = 0;}
    dez = d1 + d2; if(dez > 9){dez = 0;}
    uni = u1 + u2; if(uni > 9){uni = 0;}

    printf(" - Resultado: %i%i%i",cent,dez,uni);
}