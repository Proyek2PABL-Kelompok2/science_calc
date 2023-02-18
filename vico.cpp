#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define jmlh_pangkat 10

int main()
{
	int nilai,pangkat,pangkats,c,i,koef[jmlh_pangkat+1],koefs[jmlh_pangkat] ;
	double hasils, basis,nilais;
	float d, hasil;
	int total = 1;
	
	printf("Masukan angka = ");
	scanf("%i", &nilai);
	printf("Masukan pangkatnya = ");
	scanf("%i", &pangkat);
	
	for(c=1; c<=pangkat; c++) //Membuat perpangkatan
	{
		total = total*nilai;
	}
	printf("Hasil dari %i pangkat %i adalah = %i \n", nilai,pangkat,total); //Hasil dari perpangkatan

	printf("Masukan bilangan yang akan diakarkan :"); //Membuat nilai akar
	scanf("%i", &nilai);
	
	printf("Masukan nilai pangkatnya :"); //Membuat pangkat dari akarnya
	scanf("%i", &pangkat);
	
	hasil = pow(nilai, 1.0/pangkat);
	
	printf("%.2lf pangkat dari 1/%d = %.2lf \n", nilai, pangkat, hasil); //hasil yang didapat dari akar

	printf("Masukan angka untuk log :"); //Membuat logaritma
	scanf("%lf", &nilais); //Memasukan nilainya
	
	printf("Masukan basis log :");
	scanf("%lf", &basis); //Memasukan basis dari log
	
	hasils = log(nilais)/log(basis);
	printf("log(%.2lf) base %.2lf = %.2lf \n", nilais, basis, hasils); //Hasil logaritma
	
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
        if (i < pangkat-1) 
		{
            printf("+ ");
        }
    }

	return 0;
}
