#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int akarKuadrat(int a)
{
	return sqrt(a);
}

int akarKubik(int a)
{
	return cbrt(a);
}

int logSepuluh(int d)
{
	return log10(d);
}

int main()
{
	int a,b,c;
	float d, hasil;
	int total = 1;
	
	printf("Masukan angka = ");
	scanf("%i", &a);
	printf("Masukan pangkatnya = ");
	scanf("%i", &b);
	
	for(c=1; c<=b; c++) //Membuat perpangkatan
	{
		total = total*a;
	}
	printf("Hasil dari %i pangkat %i adalah = %i \n", a,b,total); //Hasil dari perpangkatan
	
	
	printf("Masukan angka yang akan diakar kuadrat kan = "); //Membuat akar kuadrat
	scanf("%i",&a);
	
	hasil = sqrt(a);
	printf("Hasil dari akar kuadrat %i adalah %g \n",a,hasil); //Hasil akar kuadrat


	printf("Masukan angka yang akan diakar kubik kan = "); //Membuat akar kubik
	scanf("%i",&a);
	
	hasil = cbrt(a);
	printf("Hasil dari akar kubik %i adalah %g \n",a,hasil); //Hasil akar kubik
	
	
	printf("Masukan angka yang akan di log10 = "); //Membuat perhitungan dari log10
	scanf("%f", &d);
	
	hasil = logSepuluh(d);
	printf("Mengubah %g menjadi log10 adalah %g",d,hasil); //Hasil log10
	
	return 0;
}
