#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    srand(time(NULL));

    printf("\n");
    int i, i2, numero[10];

    for(i = 0; i < 10; i++){

        numero[i] = 1 + rand() % 100;
    }

    for(i2 = 0; i2 < 10; i2++){

        printf("%i ",numero[i]);
    }



    printf("\n\n");
    return 0;
}