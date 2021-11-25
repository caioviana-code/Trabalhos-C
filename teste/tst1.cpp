#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COR_VERDE       printf("\33[32m");
#define COR_LARANJA     printf("\33[33m");
#define COR_ROXO        printf("\33[35m");
#define COR_BRANCO      printf("\33[37m");

#define TAM 5

int main() {

	srand(time(NULL));

	char mat[TAM][TAM], palavra1[TAM], palavra2[TAM];
	int espelho[TAM][TAM], d1, d2, l, c, erro;

	d1 = rand()%TAM;
	do{
		d2 = rand()%TAM;
	}while(d1 == d2);

	
    printf("\nPrimeira Palavra: ");
    fflush(stdin);
    gets(palavra1);
    printf("Segunda Palavra: ");
    fflush(stdin);
    gets(palavra2);

	// gerando matriz aleatória
    for(l=0;l<TAM;l++){
        //printf("\n");
        for(c=0;c<TAM;c++){
            mat[l][c] = 65 + (rand()%26);
            espelho[l][c] = 0;
            //printf("%c ",mat[l][c]);
        }
    }

	for(c = 0;palavra1[c] != '\0';c++){
       
        mat[d1][c] = palavra1[c];
		espelho[d1][c] = 1;
	}

	do{
		erro = 0;
		for(c = 0; palavra2[c] != '\0'; c++){

			if(espelho[c][d2] == 1){
				if(mat[c][d2] != palavra2[c]){
					erro = 1;
					d2 = rand()%TAM;
				}
			}
		}
	}while(erro == 1);

	for(c = 0; palavra2[c] != '\0'; c++){

		mat[c][d2] = palavra2[c];
		espelho[c][d2] = 1;
	}

	// mostrando a matriz modificada
    for(l=0;l<TAM;l++){
        printf("\n");
        for(c=0;c<TAM;c++){
            COR_BRANCO

            if(espelho[l][c] == 1){ 
                COR_VERDE
            }

            printf("%c ", mat[l][c]);
        }
    }

        


	printf("\n\n");
	return 0;
}

