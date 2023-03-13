#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "najwan.h"
#define jmlh_pangkat 10

float akarPangkat(float nilai_akar,float pangkat_akar)
{
	return pow(nilai_akar, 1.0/pangkat_akar);
} 

float logaritma(double nilai_loga, double basis)
{
	return log(nilai_loga)/log(basis);
}

int turunanPolinomial(int pangkat_turunan, int koef)
{
	return pangkat_turunan;
}

//int main()
void vico()
{
<<<<<<< HEAD
	int i,koef[jmlh_pangkat+1], koefs[jmlh_pangkat] , pangkat_turunan, pilihan;
=======
	int i,koef[jmlh_pangkat+1], koefs[jmlh_pangkat] , pangkat_turunan, pilihlah;
>>>>>>> 240ce8b903c77af2bab979bc113af2a6c2fc4d81
	float c, nilai_perpangkatan, pangkat_perpangkatan,pangkat_akar;
	double basis, nilai_loga, hasil_loga;
	float nilai_akar, hasil_akar;
	long long total = 1;
	
	printf("1. Perpangkatan\n");
<<<<<<< HEAD
	printf("2. Akar\n");
	printf("3. Logaritma\n");
	printf("4. Turunan\n");
	printf("Masukan Pilihan anda : ");
	scanf("%d", &pilihan);
	system("cls");
	switch(pilihan){
		case 1:
=======
	printf("2. Akar Pangkat\n");
	printf("3. Logaritma\n");
	printf("4. Turunan\n");
	printf("Masukan pilihan anda : ");
	scanf("%d", &pilihlah);
	switch(pilihlah){
		case 1:
			system("cls");
>>>>>>> 240ce8b903c77af2bab979bc113af2a6c2fc4d81
			printf("Masukan angka yang akan dipangkatkan= ");
			scanf("%f", &nilai_perpangkatan);
			printf("Masukan pangkatnya = ");
			scanf("%f", &pangkat_perpangkatan);
			
			for(c=1; c<=pangkat_perpangkatan; c++) //Membuat perpangkatan
			{
				total = perkalian(total, nilai_perpangkatan);
			}
			printf("Hasil dari %g pangkat %g adalah = %lld \n", nilai_perpangkatan, pangkat_perpangkatan,total); //Hasil dari perpangkatan
			break;
		case 2:
<<<<<<< HEAD
=======
			system("cls");
>>>>>>> 240ce8b903c77af2bab979bc113af2a6c2fc4d81
			printf("Masukan bilangan yang akan diakarkan :"); //Membuat nilai akar
			scanf("%f", &nilai_akar);
			
			printf("Masukan nilai pangkatnya :"); //Membuat pangkat dari akarnya
			scanf("%f", &pangkat_akar);
			
			hasil_akar=pow(nilai_akar, 1.0/pangkat_akar);
			
			printf("%g hasil pangkat = %g \n", nilai_akar, hasil_akar); //hasil yang didapat dari akar
			break;
		case 3:
<<<<<<< HEAD
			printf("Masukan angka untuk log :"); //Membuat logaritma
			scanf("%lf", &nilai_loga); //Memasukan nilainya
=======
			system("cls");
			printf("Masukan angka untuk log :"); //Membuat logaritma
			scanf("%lf", &nilai_loga); //Memasukan nilainya.
>>>>>>> 240ce8b903c77af2bab979bc113af2a6c2fc4d81
			
			printf("Masukan basis log :");
			scanf("%lf", &basis); //Memasukan basis dari log
			
			hasil_loga = pembagian(log(nilai_loga),log(basis));
			printf("log(%g) base %g = %g \n", nilai_loga, basis, hasil_loga); //Hasil logaritma
			break;
		case 4:
<<<<<<< HEAD
=======
			system("cls");
>>>>>>> 240ce8b903c77af2bab979bc113af2a6c2fc4d81
		    printf("Masukkan banyak variabel persamaan: "); //Membuat turunan polinomial
		    scanf("%d", &pangkat_turunan); //Memasukan jumlah dari isinya misal membuat tiga pangkat = (ax^3 + bx^2 + cx + d)
		
		    printf("Masukkan koefisien setiap pangkatnya dari 0 hingga %d: \n", pangkat_turunan);
		    for (i = 0; i <= pangkat_turunan; i++) 
			{
		        printf("koefisien untuk pangkat %d: ", i);
		        scanf("%d", &koef[i]);
		    }
		
		    for (i = 0; i < pangkat_turunan; i++)
			{
		        koefs[i] = koef[i+1] * (i+1);
		    }
		
		    printf("Turunannya adalah: ");
		    for (i = 0; i < pangkat_turunan; i++) 
			{
		        printf("%dx^%d ", koefs[i], i);
		        if (i < pangkat_turunan-1) 
				{
		            printf("+ ");
		        }
		    }
<<<<<<< HEAD
			break;
		default:
			printf("Angka yang anda masukan tidak ada");
=======
		    break;
		default:
			printf("Yang anda inputkan tidak ada");
>>>>>>> 240ce8b903c77af2bab979bc113af2a6c2fc4d81
			break;
	}
}
