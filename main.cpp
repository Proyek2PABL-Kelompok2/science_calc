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
    jacky();
    printf("Hasil: %d", calc(a,b,op));
    najwan();
    vico();
    fathia();
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
