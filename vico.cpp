#include <stdio.h>
#include <stdlib.h>
#include "vico.h"

void vico()
{
	
	//Perpangkatan
	int x,y,z,n,result;
	int total = 1;
	
	printf("Masukan angka yang akan dipangkatkan :");
	scanf("%i", &y);
	printf("Masukan pangkat :");
	scanf("%i",&z);
	
	for(x=1; x<=z; x++)
	{
		total=total*y;
	}
	
	printf("Hasilnya adalah %d", total);
	
	
	//Log 10
	printf("Masukan angka :");
    scanf("%lf", &n);
    
    result = log10(n);
    printf("%Mengubah %lf  menjadi log10 2= %lf", n ,result);

	
	//akar kuadrat
	    float a, b;

        puts("Masukan bilangan (x akarkuadrat 2):");
        printf("x = ");
        scanf("%f", &a);

        //Menghitug pangkat dengan fungsi sqrt

        z = sqrt(a);

         //Menampilkan hasil pangkat x akarkuadrat 2 = b

        printf("%.2f akarkuadrat 2  = %.2f \n", a, b);

}
