#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "najwan.h"
#define jmlh_pangkat 10

int akarPangkat(float nilai_akar,float pangkat_akar)
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
	int i,koef[jmlh_pangkat+1], koefs[jmlh_pangkat] , pangkat_turunan;
	float c, nilai_perpangkatan, pangkat_perpangkatan,pangkat_akar;
	double basis, nilai_loga, hasil_loga;
	float nilai_akar, hasil_akar;
	long long total = 1;
	
	printf("Masukan angka yang akan dipangkatkan= ");
	scanf("%f", &nilai_perpangkatan);
	printf("Masukan pangkatnya = ");
	scanf("%f", &pangkat_perpangkatan);
	
	for(c=1; c<=pangkat_perpangkatan; c++) //Membuat perpangkatan
	{
		total = perkalian(total, nilai_perpangkatan);
	}
	printf("Hasil dari %g pangkat %g adalah = %lld \n", nilai_perpangkatan, pangkat_perpangkatan,total); //Hasil dari perpangkatan

	printf("Masukan bilangan yang akan diakarkan :"); //Membuat nilai akar
	scanf("%f", &nilai_akar);
	
	printf("Masukan nilai pangkatnya :"); //Membuat pangkat dari akarnya
	scanf("%f", &pangkat_akar);
	
	hasil_akar=pow(nilai_akar, 1.0/pangkat_akar);
	
	printf("%g hasil pangkat = %g \n", nilai_akar, hasil_akar); //hasil yang didapat dari akar

	printf("Masukan angka untuk log :"); //Membuat logaritma
	scanf("%lf", &nilai_loga); //Memasukan nilainya
	
	printf("Masukan basis log :");
	scanf("%lf", &basis); //Memasukan basis dari log
	
	hasil_loga = pembagian(log(nilai_loga),log(basis));
	printf("log(%g) base %g = %g \n", nilai_loga, basis, hasil_loga); //Hasil logaritma
	
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

//	return 0;
}
