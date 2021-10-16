#include <stdio.h>

int main(){

    printf("\n");
    int a, b, c, d, e, f, g,teste;

    printf("Digite 7 Numeros: ");
    scanf("%i %i %i %i %i %i %i", &a, &b, &c, &d, &e, &f, &g);
    
    for(;a > b || a > c || a > d || a > e || a > f || a > g;){
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
        else if(a > g){
            teste = a;
            a = g;
            g = teste;
        }
    }
    for(;b > c || b > d || b > e || b > f || b > g;){
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
        else if(b > g){
            teste = b;
            b = g;
            g = teste;
        }
    }
    for(;c > d || c > e || c > f || c > g;){
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
        else if(c > g){
            teste = c;
            c = g;
            g = teste;
        }
    }
    for(;d > e || d > f || d > g;){
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
        else if(d > g){
            teste = d;
            d = g;
            g = teste;
        }
    }
    for(;e > f || e > g;){
        if(e > f){
            teste = e;
            e = f;
            f = teste;
        }
        else if(e > g){
            teste = e;
            e = g;
            g = teste;
        }
    }
    for(;f > g;){
        teste = f;
        f = g;
        g = teste;
    } 
    printf("\n- Ordenado %i %i %i %i %i %i %i",a,b,c,d,e,f,g);

    printf("\n\n");
    return 0;
}