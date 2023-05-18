#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "najwan.h"
#include "vico.h"

bool isRootWorthy(treeNode* root, treeNode* any) {
	return ((root!=NULL && any->oper!=NULL) || (root==NULL && any->oper=='\0'));
}

bool isMathNotation(char keypress, int iteration) {
	if(iteration<0)
	{
		return false;
	}
	else if(keypress!=mathNotations[iteration])
	{
		return isMathNotation(keypress, iteration-1);
	}
	else
	{
		return true;
	}
}

bool isNumberChar(char input) {
	return (input >= '0' && input <= '9');
}

bool isFunctionNameLetter(char input, int iteration) {
	if(iteration<0)
	{
		return false;
	}
	else if(input!=funcNameLetters[iteration])
	{
		return isFunctionNameLetter(input, iteration-1);
	}
	else
	{
		return true;
	}
}

double hitunglogaritma(char *query){
int angka1, angka2;	
	if(strstr(query,"log")){
		sscanf(query,"log%lf(%lf)", &angka1, &angka2);
		return logaritma(angka1,angka2);
	}
}

double hitungakar(char *query){
int angka1, angka2;
	if(strstr(query,"v")){
		sscanf(query,"%dv%lf", &angka1, &angka2);
		return akar(angka1, angka2);
	}
}

double hitungpower(char *query){
int angka1, angka2;
	if(strstr(query,"^")){
		sscanf(query,"%lf^%lf", &angka1 , &angka2);
		return power(angka1, angka2);
	}
}

double hitungln(char *query){
int angka;
	if(strstr(query,"ln")){
		sscanf(query,"ln%d", angka);
		return ln(angka);
	}
}

double ln(double nilai_ln) {
    double hasil = 0.0;
    double y = (nilai_ln - 1) / (nilai_ln + 1);
    double power = y;
    double kententuan = power;
    int hitung = 1;
    while (kententuan > 1e-15 || kententuan < -1e-15) {
        hasil = hasil + kententuan;
        power = power * y * y;
        kententuan = power / (2 * hitung + 1);
        hitung++;
    }
    return 2 * hasil;
}

double logaritma(double nilai_logaritma, double basis_logaritma) {
    double lnX, lnY, hasil;
    lnX = ln(nilai_logaritma);
    lnY = ln(basis_logaritma);
    hasil = lnX / lnY;
    return hasil;
}

double power(double nilai, int pangkat) {
    double hasil = 1.0;
    int i;

    if (pangkat < 0) {
        nilai = 1.0 / nilai;
        pangkat = -pangkat;
    }

    for (i = 0; i < pangkat; i++) {
        hasil *= nilai;
    }

    return hasil;
}

double akar(double nilai_akar, int basis) {
    double hasil = nilai_akar;
    double epsilon = 0.00001;

    while ((power(hasil, basis) - nilai_akar) > epsilon) {
        hasil = ((basis - 1) * hasil + nilai_akar / power(hasil, basis - 1)) / basis;
    }

    return hasil;
}

//int main
void vico() {
	
    double hasil, nilai, nilai_akar, nilai_logaritma, basis_logaritma, nilai_ln, hasil_ln;
    int i, pilih, pangkat, basis, nilai_faktorial, hasil_faktorial;
    long long faktorial = 1;
    char ulang;

	do{
		system("cls");
	    printf("1. perpangkatan\n");
	    printf("2. Akar\n");
	    printf("3. Logaritma\n");
	    printf("4. Logaritma Natural\n");
	    printf("Masukan pilihan anda : ");
	    scanf("%d", &pilih);
	
	    switch (pilih) 
		{
	
		    case 1:
		    	system("cls");
		        printf("Masukkan (nilai)^(pangkat): ");
		        scanf("%lf^%d", &nilai, &pangkat);
		        printf("%g^%d = %g\n", nilai, pangkat, power(nilai, pangkat));
		    break;
		
		    case 2:
		    	system("cls");
		        printf("Masukkan (basis)v(nilai): ");
		        scanf("%dv%lf", &basis, &nilai_akar);
		        printf("Akar pangkat %d dari %g adalah %g\n", basis, nilai_akar, akar(nilai_akar, basis));
		    break;
		
		    case 3:
		    	system("cls");
			    printf("Masukkan nilai logaritma:");
			    getchar();
			    scanf("log%lf(%lf)", &basis_logaritma, &nilai_logaritma);
			    
			    if (nilai_logaritma > 0 && basis_logaritma > 0)
			    {
			        hasil = logaritma(nilai_logaritma, basis_logaritma);
			        printf("log%.lf(%.lf) = %g\n", basis_logaritma, nilai_logaritma,hasil);
			    }
			    else 
			    {
			        printf("\nInvalid input\n");
			    }
		    break;
		    
		    case 4:
				system("cls");
				printf("Masukkan bilangan ln: ");
		    	scanf("log%lf", &nilai_ln);
		   		hasil_ln = ln(nilai_ln);
		   		printf("ln%f = %g\n", nilai_ln, hasil_ln);
	   		break;
		   		
			default:
				printf("Pilihan yang anda masukan tidak ada!");
			break;
			
		}

		printf("Kembali ke menu : ");
		scanf(" %c", &ulang);
	}while (ulang == 'y' || ulang == 'Y');

}
