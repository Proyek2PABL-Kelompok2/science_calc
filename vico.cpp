#include <stdio.h>
#include <stdlib.h>
#include "vico.h"

void vico()
{
	int x,y,z;
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
	
	return 0;
}
