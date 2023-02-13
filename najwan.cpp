#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "najwan.h"
#include <stdio.h>





int najwan(float a, float b, char c){	
	float hasil;

	if(c == '+'){
		hasil = a + b;
		printf("hasil = %g", hasil);
	}
	else if(c == '-'){
		hasil = a - b;
		printf("hasil = %g", hasil);
	}
	else if(c == '*'){
		hasil = a * b;
		printf("hasil = %g", hasil);
	}
	else if(c == '/'){
		hasil = a / b;
		printf("hasil = %g", hasil);
	}
	else if(c == '%'){
		hasil = fmod(a,b);
		printf("hasil = %g", hasil);
	}
	else{
		printf("anda salah memasukan operasi hitung");
	}
	

 	return hasil;
	//int penjumlahan(&pertama, )
}

