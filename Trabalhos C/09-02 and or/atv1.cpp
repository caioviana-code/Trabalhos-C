#include <stdio.h>

int main() {

    float t1, t2, t3;

    printf("Digite os tres tempos:");
    fflush(stdin);
    scanf("%f %f %f", &t1, &t2, &t3);

    if(t1 < t2 && t1 < t3){
        printf("- 1 lugar > %.2f", t1);
        if(t2 < t3){
            printf("\n- 2 lugar > %.2f", t2);
        }
        if(t3 > t2){
            printf("\n- 3 lugar > %.2f", t3);
        }
            
    } 
    if(t2 < t1 && t2 < t3){
        printf("- 1 lugar > %.2f", t2);
        if(t1 < t3){
            printf("\n- 2 lugar > %.2f", t1);
        }
        if(t3 > t2){
            printf("\n- 3 lugar > %.2f", t3);
        }
    }
    if(t3 < t1 && t3 < t2){
        printf("- 1 lugar > %.2f", t3);
        if(t2 < t1){
            printf("\n- 2 lugar > %.2f", t2);
        }
        if(t1 > t2){
            printf("\n- 3 lugar > %.2f", t1);
        }
    }

    printf("\n\n");
    return 0;
}