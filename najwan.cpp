#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "najwan.h"
#include <stdio.h>

float penjumlahan(float a,float b){
	float hasil;
	hasil = a + b;
	return hasil;	
}

float pengurangan(float a,float b){
	float hasil;
	hasil = a - b;
	return hasil;	
}

float perkalian(float a,float b){
	float hasil;
	hasil = a * b;
	return hasil;	
}

float pembagian(float a,float b){
	float hasil;
	hasil = a / b;
	return hasil;	
}

float modulus(float a, float b){
	float hasil;
	hasil = fmod(a,b);
	return hasil;	
}

void najwan(){	
	float hasil;
	
	switch(){
		case '+':
			hasil = penjumlahan(a,b);
			
			break;
		case '-':
			hasil = pengurangan(a,b);
			
			break;
		case '*':
			hasil = perkalian(a,b);
			
			break;
		case '/':
			hasil = pembagian(a,b);
			
			break;
		case '%':
			hasil = modulus(a,b);
			
			break;
		default:
			printf("anda salah memasukan operasi hitung");
	}
}

 	

