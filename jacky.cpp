#include <stdio.h>
#include <stdlib.h>
#include "jacky.h"
#include "vico.h"
#include "fathia.h"
#include "difa.h"

void otherCalcs(){
	int choice;
	char s[250];
	system("cls");
	printf("What do you want to calculate ");
	printf("\n1. Exponentials, Logarithms, Differentials");
	printf("\n2. Matrices, Sequence and Series");
	printf("\n3. Trigonometry");
	printf("\nChoose: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			system("cls");
			vico(); // kekurangan: masih pakai void function, fungsi-fungsi hitung belum atomized
			break;
		case 2:
			system("cls");
			fathia(); // kekurangan: masih pakai void function, fungsi-fungsi hitung belum atomized
			break;
		case 3:
			system("cls");
			printf("\nTrigonometri");
			printf("\nMasukkan input: ");
			scanf("%s", s);
			printf("Hasil: %f", hitungTrigono(s));
			break;
		default:
			break;
	}
}
