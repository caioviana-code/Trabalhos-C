#include <stdio.h>

int main() {

    char c, o, r;

    printf("Digite tres letras:");
    scanf("%c %c %c",&c, &o, &r);

    printf("- Combinacao 1 = %c %c %c",c, o, r);
    printf("\n- Combinacao 2 = %c %c %c",c, r, o);
    printf("\n- Combinacao 3 = %c %c %c",o, c, r);
    printf("\n- Combinacao 4 = %c %c %c",o, r, c);
    printf("\n- Combinacao 5 = %c %c %c",r, c, o);
    printf("\n- Combinacao 6 = %C %c %c",r, o, c);

    return 0;
}