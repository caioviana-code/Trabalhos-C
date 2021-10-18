#include <stdio.h>

int main(){

    printf("\n");
    int a, b, c, d, e, f, teste;

    printf("Numeros: ");
    scanf("%i %i %i %i %i %i", &a, &b, &c, &d, &e, &f);
    
    while(a > b || a > c || a > d || a > e || a > f){
        if(a > b){
            teste = a;
            a = b;
            b = teste;
        }
        else if(a > c){
            teste = a;
            a = c;
            c = teste;
        }
        else if(a > d){
            teste = a;
            a = d;
            d = teste;
        }
        else if(a > e){
            teste = a;
            a = e;
            e = teste;
        }
        else if(a > f){
            teste = a;
            a = f;
            f = teste;
        }
    }
    while(b > c || b > d || b > e || b > f){
        if(b > c){
            teste = b;
            b = c;
            c = teste;
        }
        else if(b > d){
            teste = b;
            b = d;
            d = teste;
        }
        else if(b > e){
            teste = b;
            b = e;
            e = teste;
        }
        else if(b > f){
            teste = b;
            b = f;
            f = teste;
        }
    }
    while(c > d || c > e || c > f){
        if(c > d){
            teste = c;
            c = d;
            d = teste;
        }
        else if(c > e){
            teste = c;
            c = e;
            e = teste;
        }
        else if(c > f){
            teste = c;
            c = f;
            f = teste;
        }
    }
    while(d > e || d > f){
        if(d > e){
            teste = d;
            d = e;
            e = teste;
        }
        else if(d > f){
            teste = d;
            d = f;
            f = teste;
        }
    }
    while(e > f){
        teste = e;
        e = f;
        f = teste;
    }
    
    
    
    printf("\n- Ordenado %i %i %i %i %i %i",a,b,c,d,e,f);

  
    printf("\n\n");
    return 0;
}