#include <stdio.h>
#include <math.h>
#include <conio.h>


int main(){
	float pertama, kedua, hasil;
	
	char operasi;
	 	
	printf("masukan 2 angka untuk melakukan operasi hitung aritmatika : \n");
	scanf("%f ", &pertama); 
	
	scanf("%c", &operasi);
	
	scanf("%f", &kedua);
	
	if(operasi == '+'){
		hasil = pertama + kedua;
		printf("hasil = %g", hasil);
	}
	else if(operasi == '-'){
		hasil = pertama - kedua;
		printf("hasil = %g", hasil);
	}
	else if(operasi == '*'){
		hasil = pertama * kedua;
		printf("hasil = %g", hasil);
	}
	else if(operasi == '/'){
		hasil = pertama / kedua;
		printf("hasil = %g", hasil);
	}
	else if(operasi == '%'){
		hasil = fmod(pertama,kedua);
		printf("hasil = %g", hasil);
	}
	else{
		printf("anda salah memasukan operasi hitung");
	}
	

	
	//int penjumlahan(&pertama, )
}