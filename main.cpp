#include <stdio.h>
#include "difa.h"
#include "fathia.h"
#include "jacky.h"
#include "najwan.h"
#include "vico.h"

int calc(int a, int b, char op);

int main(){
    float a, b; char op;
    printf("main file");
    printf("\nmasukkan sebuah operasi : ");
    scanf("%f%c%f", &a, &op, &b);
    printf("Hasil: %d", calc(a,b,op));

    printf("Difa sinus: %f\n", sinus(a));
    printf("Difa sinus: %f\n", cosinus(a));
    printf("Difa sinus: %f\n", tangent(a));
}

int calc(int a, int b, char op){
    int c;
    switch (op)
    {
    case '+':
        c = a+b;
        break;
    case '-':
        c = a-b;
        break;
    case '*':
        c = a*b;
        break;
    case '/':
        c = a/b;
        break;
    default:
        break;
    }
    return c;
}