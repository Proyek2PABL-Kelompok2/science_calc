#include <stdio.h>
#include <stdlib.h>
#include "difa.h"
#include "fathia.h"
#include "jacky.h"
#include "najwan.h"
#include "vico.h"

int main(){
	char s[250], prompt;
	int res, choice;
	do{
		system("cls");
		printf("Scientific Calculator");
		printf("\n1. Enter arithmetic expression");
		printf("\n2. Perform other calculations");
		printf("\n3. Perform conversions");
		printf("\nChoose: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
//				printf("You chose 1");
				printf("Masukkan ekspresi aritmatika: ");
				scanf("%s", s);
				res = hitungQuery(s);
				printf("Hasil: %d", res);
				break;
			case 2:
//				printf("You chose 2");
				printf("Ingin hitung apa? ");
				printf("\n1. Eksponensial, Logaritma, Turunan");
				printf("\n2. Matriks");
				printf("\n3. Trigonometri");
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
				break;
			case 3:
//				printf("You chose 3");
				printf("Ingin konversi apa? ");
//				printf("\n1. Eksponensial, Logaritma, Turunan");
//				printf("\n2. Matriks");
//				printf("\n3. Trigonometri");
				printf("\nChoose: ");
				scanf("%d", &choice);
				switch(choice){
					case 1:
						system("cls");
						break;
					case 2:
						system("cls");
						break;
					case 3:
						system("cls");
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		printf("\nWould you like to try again? (y/n) ");
		scanf("\n%c", &prompt);
		if(prompt=='n'||prompt=='N'){
			printf("Goodbye!");
			break;
		}
	}while(prompt=='y'||prompt=='Y');
}
