#include <stdio.h>
#include <stdlib.h>

double fatorial(int num);
double maiorPrimo(int primo);

int main() {

    int num, primo;
    double fat, maior_primo, multi;

    printf("\nFatorial: ");
    scanf("%i",&num);
    printf("Maior Primo: ");
    scanf("%i",&primo);

    fat = fatorial(num);
    maior_primo = maiorPrimo(primo);

    multi = fat * maior_primo;

    printf(" - Resultado: %.0lf x %.0lf = %.0lf",fat,maior_primo,multi);

    printf("\n\n");
    return 0;
}

double fatorial(int num){
    
    int a;
    double fat = 1;
    
    for(a=num; a>=2; a--){
        fat = fat * a;
    }

    return fat;
}

double maiorPrimo(int primo){

    int a,b,cont = 0;
    double maior_primo = 0;

    for(a=2; a<=primo; a++){
        cont = 0;
        for(b=1; b<=a; b++){
            if(a % b == 0){
                cont++;
            }
        }
        if(cont == 2){
            maior_primo = a;
        }
    }
}

