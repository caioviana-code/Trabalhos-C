#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, l, c;

    printf("\nNumero Impar: ");
    fflush(stdin);
    scanf("%i",&num);

    int mat[num][num];

    for(l=0; l < num; l++){
        printf("\n");
        for(c=0; c < num; c++){
            
            if(l == 0 || c == 0 || l == num - 1 || c == num - 1){
                printf("* ");
            }
            else if(l == num/2 && c == num/2){
                printf("* ");
            }
            else{
                printf("  ");
            }
           
        }
    }
    printf("\n\n");
    return 0;
}