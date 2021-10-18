#include <stdio.h>

int main(){

    printf("\n");
    int num, cont, t1, t2, t3;

    printf("Numero de termos: ");
    scanf("%i", &num);

    printf("\n- Serie de Fibonacci[%i]: ", num);

    t1 = 1;
    t2 = 1;
    t3 = 1;

    printf("%i %i ", t1, t2);
    for(cont = 1 ; cont <= num - 2 ; cont++){
        
        t3 = t1 + t2;
        printf("%i ",t3);
        t1 = t2;
        t2 = t3;
    }
    
    printf("\n\n");
    return 0;
}