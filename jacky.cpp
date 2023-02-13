#include <stdio.h>
#include "jacky.h"
#include "difa.h"

void jacky(float *a, float *b, char *op){
    printf("\nmasukkan sebuah operasi : ");
    scanf("%f%c%f", a, op, b);
    // printf("Hasil: %d", calc(*a,*b,*op));

   	printf("\nHasil sinus difa : %f", sinus(*a));
    printf("\nHasil sinus difa : %f", cosinus(*a));
    printf("\nHasil sinus difa : %f", tangent(*a));
}