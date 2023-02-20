#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "difa.h"

float hitungTrigono(char *query){
int angka;
	if(strstr(query,"sin")){
    	sscanf(query,"sin(%d)",&angka);
		return sinus(angka);
	}
	if(strstr(query,"cos")){
    	sscanf(query,"cos(%d)",&angka);
    	return cosinus(angka);
	}
	if(strstr(query,"tan")){
    	sscanf(query,"tan(%d)",&angka);
    	return tangent(angka);
	}
	if (strstr(query,"sec")){
		sscanf(query,"sec(%d)",&angka);
    	return secan(angka);
	}
	if (strstr(query,"cot")){
		sscanf(query,"cot(%d)",&angka);
    	return cotangent(angka);
	}
	if (strstr(query,"asin")){
		sscanf(query,"asin(%d)",&angka);
    	return asinus(angka);
	}
	if (strstr(query,"acos")){
		sscanf(query,"acos(%d)",&angka);
    	return acosinus(angka);
	}
	if (strstr(query,"atan")){
		sscanf(query,"atan(%d)",&angka);
    	return atangent(angka);
	}
}
float sinus(float angka){
	return sin(angka);
}

float cosinus(float angka){
	return cos(angka);
}

float tangent(float angka){
	return tan(angka);
}

float secan(float angka){
	return 1/cos(angka);
}

float cotangent(float angka){
	return cos(angka)/sin(angka);
}

float asinus(float angka){
	return asin(angka);
}

float acosinus(float angka){
	return acos(angka);
}

float atangent(float angka){
	return atan(angka);
}

int operasi(char opp,int operandNum1, int operandNum2){
	int hasil;
			if(opp=='*'){
				hasil = operandNum1 * operandNum2;
			}
			else if(opp=='/'){
				hasil = operandNum1 / operandNum2;
			}
			else if(opp=='+'){
				hasil = operandNum1 + operandNum2;
			}
			
			else if(opp=='-'){
				hasil = operandNum1 - operandNum2;
			}
	return hasil;
	
}

int hitungQuery(char query[]){
	char operand1[250], operand2[250];
	int i, j;
	char opp;
	int hasil,operandNum1,operandNum2;
	int iteration;
	char temp[20];
	int k, awal, akhir, penampung, iTemp;
	i = 0;
	j = 0;
		while (strstr(query, "*") || strstr(query, "/"))
	{
		k = 0;
		if (query[i] == '*'|| query[i] == '/')
		{
			memset(operand1,'\0',7);
			memset(operand2,'\0',7);
			opp = query[i]; //assign operator
			j = i - 1;
			while ((isdigit(query[j])||query[j]=='.' )&& j >= 0) // deteksi operand 1
			{

				operand1[k] = query[j];
				j--;
				k++;
			}
			
			
			awal = j + 1;
			j = i + 1;
			k = 0;
			while ((isdigit(query[j])||query[j]=='.' ) && query[j] != '\0') // deteksi operand 2
			{
				operand2[k] = query[j];
				j++;
				k++;
			}
			akhir = j - 1;
			strrev(operand1);
			operandNum1 = atoi(operand1);
			operandNum2 = atoi(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			sprintf(temp, "%d", hasil);


			penampung = awal;
			
			while (awal <= akhir) // done
			{
				query[awal] = '\0';
				awal++;
			}

			awal = penampung;

			iTemp = 0;
			while (temp[iTemp] != '\0') // loop jika temp tidak null
			{
				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
				iTemp++;
				awal++;
			}

			awal = penampung;
			penampung = akhir;
			int iawal = awal;
			int iakhir = akhir;
			// dibawah adalah untuk shift query
			while (awal <= akhir)
			{
				if (query[iawal] == '\0')
				{
					while (query[iakhir + 1] != '\0')
					{

						query[iawal] = query[iakhir + 1];
						query[iawal + 1] = '\0';
						iawal++;

						iakhir++;
					}
					
				}
				
				iawal++;
				awal++;
			}

		}
		else{
			i++;
		}
		
		
	}
	i = 0;
	j = 0;
	while (strstr(query, "+") || strstr(query, "-"))
	{
		k = 0;
		if (query[i] == '+' || (query[i] == '-' && i>=0))
		{
			memset(operand1,'\0',7);
			memset(operand2,'\0',7);
			opp = query[i]; //assign operator

			j = i - 1;
			while ((isdigit(query[j])||query[j]=='.' ) && j >= 0) // deteksi operand 1
			{

				operand1[k] = query[j];
				j--;
				k++;
			}
			
			
			awal = j + 1;
			j = i + 1;
			k = 0;
			while ((isdigit(query[j])||query[j]=='.' ) && query[j] != '\0') // deteksi operand 2
			{
				operand2[k] = query[j];
				j++;
				k++;
			}
			akhir = j - 1;
			strrev(operand1);

			
			operandNum1 = atoi(operand1);
			operandNum2 = atoi(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			sprintf(temp, "%d", hasil);


			penampung = awal;
		
			while (awal <= akhir)
			{
				query[awal] = '\0';
				awal++;
			}

			awal = penampung;

			iTemp = 0;
			while (temp[iTemp] != '\0') // loop jika temp tidak null
			{
				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
				iTemp++;
				awal++;
			}

			awal = penampung;
			penampung = akhir;
			int iawal = awal;
			int iakhir = akhir;
			// dibawah adalah untuk shift query
			while (awal <= akhir)
			{
				if (query[iawal] == '\0')
				{
					while (query[iakhir + 1] != '\0')
					{

						query[iawal] = query[iakhir + 1];
						query[iawal + 1] = '\0';
						iawal++;

						iakhir++;
					}
					
				}
				
				iawal++;
				awal++;
			}

		}
		else{
			i++;
		}
		}
		hasil = atoi(query);
		return hasil;
}
