#include <stdlib.h>
#include <stdio.h>

double fatorial(int num);

int main() {

    int num;
    double fat;

    printf("\nDigite um valor: ");
    scanf("%i", &num);

    fat = fatorial(num);

    printf(" - Fatorial: %.0lf", fat);
    
    printf("\n\n");
    return 0;
}

double fatorial(int num) {

    int a;
    double fat = 1;
    
    for(a=num; a>=2; a--){
        fat = fat * a;
    }

    return fat;

}