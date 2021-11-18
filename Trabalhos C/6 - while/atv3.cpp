#include <stdio.h>

int main(){

    char a, b;

    printf("Digite duas letras: ");
    scanf("%c %c", &a, &b);

    if(a>90){
        a=a-32;
    }
    if(b>90){
        b=b-32;
    }

    while(a < b){
        printf("%c ", a);
        a++;
    }

    printf("%c", b);

    printf("\n\n");
    return 0;
}