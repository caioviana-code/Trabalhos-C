#include <stdio.h>
#include <math.h>

int main(){

    int lados, n1, n2, n3;

    printf("Lados do triangulo:");
    scanf("%i", &lados);

    n1 = lados/100;
    n2 = (lados%100)/10;
    n3 = lados%10;
   
    if(lados < 100 || lados > 999){
        printf("- Numero Invalido!");
    }
    else{
        
        if(n1 == n2 && n1 == n3){
            printf("- Equilatero"); 
        }     
        
        else if(n1 != n2 && n1!= n3 ){
            printf("- Escaleno");
        }
        else{
            printf("- Isoceles");
        }

    } 
    printf("\n\n");
    return 0;
}
