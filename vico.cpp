#include <stdio.h>
#include <stdlib.h>
#include "vico.h"

void vico()
{
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
	
	printf("Masukan angka :");
    scanf("%lf", &n);
    
    result = log10(n);
    printf("%Mengubah %lf  menjadi log10 2= %lf", n ,result);

    return 0;
	return 0;
}
