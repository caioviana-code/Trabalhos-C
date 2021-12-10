#include <stdio.h>

int main() {

   int i, *pi;
   char c, *pc;

   printf("\nDigite um numero inteiro e um caractere: ");
   scanf("%i %c", &i, &c);

   pi = &i;
   pc = &c;

   printf("- [Inteiro]: endereco = %p / conteudo = %i",pi, *pi);
   printf("\n- [Caractere]: endereco = %p / conteudo = %c",pc, *pc);

    printf("\n\n");
    return 0;
}