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
float hitung_logaritma()
{
	return log(nilai_log)/log(basis);
}

//int main()
void vico()
{
	int i,koef[jmlh_pangkat+1], koefs[jmlh_pangkat] , pangkat_turunan, pilihlah;

	float c, nilai_perpangkatan, pangkat_perpangkatan,pangkat_akar;
	double basis, nilai_loga, hasil_loga;
	float nilai_akar, hasil_akar;
	long long total = 1;
	
	printf("1. Perpangkatan\n");
	printf("2. Akar\n");
	printf("3. Logaritma\n");
	printf("4. Turunan\n");
	printf("Masukan Pilihan anda : ");
	scanf("%d", &pilihlah);
	system("cls");
	switch(pilihlah){
		case 1:
	printf("2. Akar Pangkat\n");
	printf("3. Logaritma\n");
	printf("4. Turunan\n");
	printf("Masukan pilihan anda : ");
	scanf("%d", &pilihlah);
	switch(pilihlah){
		case 1:
			system("cls");

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

			system("cls");
			printf("Masukan bilangan yang akan diakarkan :"); //Membuat nilai akar
			scanf("%f", &nilai_akar);
			
			printf("Masukan nilai pangkatnya :"); //Membuat pangkat dari akarnya
			scanf("%f", &pangkat_akar);
			
			hasil_akar=pow(nilai_akar, 1.0/pangkat_akar);
			
			printf("%g hasil pangkat = %g \n", nilai_akar, hasil_akar); //hasil yang didapat dari akar
			break;
		case 3:
			printf("Masukan angka untuk log :"); //Membuat logaritma
			scanf("%lf", &nilai_loga); //Memasukan nilainya

			system("cls");
			printf("Masukan angka untuk log :"); //Membuat logaritma
			scanf("%lf", &nilai_loga); //Memasukan nilainya.
			
			printf("Masukan basis log :");
			scanf("%lf", &basis); //Memasukan basis dari log
			
			hasil_loga = pembagian(log(nilai_loga),log(basis));
			printf("log(%g) base %g = %g \n", nilai_loga, basis, hasil_loga); //Hasil logaritma
			break;
		case 4:

			system("cls");

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
		    break;
		case 5:
			
			system("cls");
			// Membaca input sebagai string
		    printf("Masukkan basislognilai : ");
		    scanf("%[^\n]", str);
		
		    // Memecah string menjadi basis dan nilai
		    sscanf(str, "%lflog%lf", &basis, &nilai_loga);
		
		    // Menghitung logaritma
		    hasil_loga = pembagian(log(nilai_loga),log(basis));
		
		    // Menampilkan hasil
		    printf("%glog%g = %g\n", basis, nilai_loga, hasil_loga);
			break;
		default:
			printf("Angka yang anda masukan tidak ada");
		    break;
		
	}
}
}
