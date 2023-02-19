#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define jmlh_pangkat 10

int perpangkatan(int nilai,int pangkat)
{
	return nilai;
}

int akarpangkat(float nilai_akar,int pangkat)
{
	return pow(nilai_akar, 1.0/pangkat);
} 

float logaritma(double nilai_loga, double basis)
{
	return log(nilai_loga)/log(basis);
}

int turunanpolinomial(int pangkats, int koef)
{
	return pangkats;
}

int main()
{
	int i, c, nilai, pangkat, pangkats, koef[jmlh_pangkat+1], koefs[jmlh_pangkat] ;
	double basis, nilai_loga, hasil_loga;
	float nilai_akar, hasil_akar;
	long long total = 1;
	
	printf("Masukan angka yang akan dipangkatkan= ");
	scanf("%i", &nilai);
	printf("Masukan pangkatnya = ");
	scanf("%i", &pangkat);
	
	for(c=1; c<=pangkat; c++) //Membuat perpangkatan
	{
		total = total*nilai;
	}
	printf("Hasil dari %i pangkat %i adalah = %lld \n", nilai,pangkat,total); //Hasil dari perpangkatan

	printf("Masukan bilangan yang akan diakarkan :"); //Membuat nilai akar
	scanf("%f", &nilai_akar);
	
	printf("Masukan nilai pangkatnya :"); //Membuat pangkat dari akarnya
	scanf("%i", &pangkat);
	
	hasil_akar=pow(nilai_akar, 1.0/pangkat);
	
	printf("%.2lf pangkat dari 1/%d = %.2lf \n", nilai_akar, pangkat, hasil_akar); //hasil yang didapat dari akar

	printf("Masukan angka untuk log :"); //Membuat logaritma
	scanf("%lf", &nilai_loga); //Memasukan nilainya
	
	printf("Masukan basis log :");
	scanf("%lf", &basis); //Memasukan basis dari log
	
	hasil_loga = log(nilai_loga)/log(basis);
	printf("log(%.2lf) base %.2lf = %.2lf \n", nilai_loga, basis, hasil_loga); //Hasil logaritma
	
    printf("Masukkan banyak variabel persamaan: "); //Membuat turunan polinomial
    scanf("%d", &pangkats); //Memasukan jumlah dari isinya misal membuat tiga pangkat = (ax^3 + bx^2 + cx + d)

    printf("Masukkan koefisien setiap pangkatnya dari 0 hingga %d: \n", pangkats);
    for (i = 0; i <= pangkats; i++) 
	{
        printf("koefisien untuk pangkat %d: ", i);
        scanf("%d", &koef[i]);
    }

    for (i = 0; i < pangkats; i++)
	{
        koefs[i] = koef[i+1] * (i+1);
    }

    printf("Turunannya adalah: ");
    for (i = 0; i < pangkats; i++) 
	{
        printf("%dx^%d ", koefs[i], i);
        if (i < pangkats-1) 
		{
            printf("+ ");
        }
    }

	return 0;
}
