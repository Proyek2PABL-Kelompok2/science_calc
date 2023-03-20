#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "difa.h"
#include "najwan.h"
#include "vico.h"

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
	if (strstr(query,"cosec")){
		sscanf(query,"cosec(%d)",&angka);
    	return cosecan(angka);
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
float cosecan(float angka){
	return 1/sin(angka);
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

float operasi(char opp,float operandNum1, float operandNum2){
	float hasil;
			if (opp=='^'){
				hasil=pow(operandNum1,operandNum2);
			}
			else if (opp=='v'){
				hasil=akarPangkat(operandNum2,operandNum1);
			}
			else if(opp=='*'){
				hasil = perkalian(operandNum1,operandNum2);
			}
			else if(opp=='/'){
				hasil = pembagian(operandNum1,operandNum2);
			}
			else if(opp=='+'){
				hasil=penjumlahan(operandNum1,operandNum2);
			}
			
			else if(opp=='-'){
				hasil = pengurangan(operandNum1,operandNum2);
			}
	return hasil;
	
}

void deteksiOperand1(char query[], char operand1[], int i,int *j){
	int iter,k;
	k=0;
	iter = i - 1;
	while ((isdigit(query[iter])||query[iter]=='.' || (query[iter]=='-' && iter == 0)||(iter>0&&query[iter]=='-'&&!isdigit(query[iter-1]))) && iter >= 0) // deteksi operand 1
			{
				
				operand1[k] = query[iter];
				iter--;
				k++;
			}
	*j=iter;
}

void deteksiOperand2(char query[],char operand2[],int i,int *j){
	int iter,k;
	k=0;
	iter = i + 1;
	
	while ((isdigit(query[iter])||query[iter]=='.'|| (query[iter]=='-' && iter == 0)||(iter>0&&query[iter]=='-'&&!isdigit(query[iter-1]) ) && query[iter] != '\0')) // deteksi operand 2
			{
				operand2[k] = query[iter];
				iter++;
				k++;
			}
	*j=iter;
}

void shiftRight(char query[],char temp[],int awal,int akhir){
	int panjangTemp,panjangQuery,rangeOperasi,afterOperasi,penSize,iShift;
			iShift=0;
			panjangQuery=strlen(query);
			penSize=panjangQuery;
				rangeOperasi=akhir-awal+1;
				afterOperasi=panjangQuery-akhir-1;
			panjangTemp=strlen(temp);
	
			//melakukan geser kanan jika hasil operasi > range operasi
			while (panjangTemp-1>rangeOperasi){
				rangeOperasi=akhir-awal+1;
				iShift=0;
				while(iShift<afterOperasi){
					query[panjangQuery]=query[panjangQuery-1];
					query[panjangQuery-1]='=';
					panjangQuery--;
					iShift++;	
				}
				panjangQuery=penSize+1;
				penSize++;
				akhir++;
			}
	printf("\n\nShiftRight: %s",query);
}

void assignHasil(char query[],char temp[],int awal){
	int iTemp;
	iTemp = 0;
			while (temp[iTemp] != '\0') // loop jika temp tidak null
			{
				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
				iTemp++;
				awal++;
			}
		printf("\nAfterAssign: %s",query);
}

void shiftLeft(char query[],int space){
	//menggeser ke kiri jika ada char antara 1 operasi dengan operasi lainnya
			int iShift;
			iShift=0;
			while(iShift<=strlen(query)-1){
				if(query[iShift]=='='&&query[space+1]!='\0'){
					query[iShift]=query[space+1];
					query[space+1]='=';
					space++;
				}
				iShift++;
				
			}
		printf("\n\nShiftLeft %s",query);
}

void shiftLeftIfNull(char query[],int awal,int akhir){
	int iawal,iakhir;
	iawal=awal;
	iakhir=akhir;
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
		printf("\n\nShiftLeftIFNULLt: %s",query);
}

bool cekMinus(char query[]){
	int iter,jmlMinus;

	jmlMinus=0;
	iter=0;
	while(iter<strlen(query)-1){
		if((query[iter]=='-'&&iter!=0&&isdigit(query[iter-1]))){
			jmlMinus++;
		}
		iter++;
	}

	if(jmlMinus>0){
		return true;
	}
	else{
		return false;
	}
	
	
	
}

void formatTrigono(char query[]){
	int i;
	
	i=0;
	while(i<strlen(query)-1){
			
		if(query[i]>=65&&query[i]<=90){
			query[i]=query[i]+32;
		}
		i++;
	}
}

void trigonoInline(char query[]){
	int awal,akhir,iawal,penampung;
	char temp[255];
	memset(temp,'\0',255);
	float hasil;
	formatTrigono(query);
	iawal=0;
	awal=strstr(query,"sin(")-&query[0];
	

	
	
	while(strstr(query,"sin(")){
			while(query[iawal]!=')'){
		iawal++;
		if(query[iawal]==')'){
			akhir=iawal;
			
		}
	}
	
	
		hasil = hitungTrigono(query);
	sprintf(temp, "%f", hasil);
	shiftRight(query,temp,awal,akhir);
	
	penampung = awal;
			//mengisi range operasi dengan =
			while (awal <= akhir)
			{
				query[awal] = '=';
				awal++;
			}
		
			awal = penampung;
			int penampung_akhir;
			penampung_akhir=akhir;
			int space;
			space=akhir;
	
			akhir=penampung_akhir;
			int index;
			
			//mengisi hasil kedalam array query
			assignHasil(query,temp,awal);
			
			
			shiftLeft(query,space);
	
			
			awal = penampung;
			penampung = akhir;
		
			// dibawah adalah untuk shift query
			shiftLeftIfNull(query,awal,akhir);
			
	}

printf("\nAwal: %d, Akhir: %d ",awal,akhir);
}

float hitungQuery(char query[]){
	char operand1[250], operand2[250];
	int i, j;
	char opp;
	float hasil,operandNum1,operandNum2;
	bool operasiMinus;
	int iteration;
	char temp[200];
	int k, awal, akhir, penampung, iTemp;
	i = 0;
	j = 0;
	
	trigonoInline(query);
	printf("\nAfter TRIG: %s",query);
	while (strstr(query, "^") || strstr(query, "v"))
	{
		k = 0;
		if (query[i] == '^' || (query[i] == 'v' && i>=0))
		{
			memset(operand1,'\0',250);
			memset(operand2,'\0',250);
			
			opp = query[i]; //assign operator
		
			deteksiOperand1(query,operand1,i,&j);
			
			awal = j + 1;//awal adalah variabel yang menunjukan indeks ke berapa operasi dimulai
			
			deteksiOperand2(query,operand2,i,&j);
			
			akhir = j - 1; //akhir adalah variabel yang menunjukkan indeks ke berapa operasi berakhir
			strrev(operand1); //karena operand1 diassign secara terbalik, maka harus di reverse
		
			//convert to float
			operandNum1 = atof(operand1); 
			operandNum2 = atof(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			//float to string
			sprintf(temp, "%f", hasil);
		
			int penampung_akhir; // dibuat untuk menampung nilai akhir
			
			shiftRight(query,temp,awal,akhir);
			
			penampung_akhir = akhir;
			
			penampung = awal;
			//mengisi range operasi dengan =
			while (awal <= akhir)
			{
				query[awal] = '=';
				awal++;
			}
		
			awal = penampung;
			int iawal,iakhir,space;
			space=akhir;
	
			akhir=penampung_akhir;
			int index;
	
			penampung=awal;
			
			//mengisi hasil kedalam array query
			assignHasil(query,temp,awal);
				
			shiftLeft(query,space);
	
			awal = penampung;
			penampung = akhir;
		
			// dibawah adalah untuk shift query
			shiftLeftIfNull(query,awal,akhir);
		}
		else{
			i++;
		}
	}
	i=0;
	j=0;
	while (strstr(query, "*") || strstr(query, "/"))
	{
		k = 0;
		if (query[i] == '*' || (query[i] == '/' && i>=0))
		{
			memset(operand1,'\0',250);
			memset(operand2,'\0',250);
			
			opp = query[i]; //assign operator
		
			deteksiOperand1(query,operand1,i,&j);
			
			awal = j + 1; //awal adalah variabel yang menunjukan indeks ke berapa operasi dimulai
			
			deteksiOperand2(query,operand2,i,&j);
			
			akhir = j - 1; //akhir adalah variabel yang menunjukkan indeks ke berapa operasi berakhir
			strrev(operand1); //karena operand1 diassign secara terbalik, maka harus di reverse
		
			//convert to float
			operandNum1 = atof(operand1); 
			operandNum2 = atof(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			//float to string
			sprintf(temp, "%f", hasil);
		
			int penampung_akhir; // dibuat untuk menampung nilai akhir
			
			shiftRight(query,temp,awal,akhir);
			
			penampung_akhir = akhir;
			
			penampung = awal;
			//mengisi range operasi dengan =
			while (awal <= akhir)
			{
				query[awal] = '=';
				awal++;
			}
		
			awal = penampung;
			int iawal,iakhir,space;
			space=akhir;
	
			akhir=penampung_akhir;
			int index;
	
			penampung=awal;
			
			//mengisi hasil kedalam array query
			assignHasil(query,temp,awal);
				
			shiftLeft(query,space);
	
			awal = penampung;
			penampung = akhir;
		
			// dibawah adalah untuk shift query
			shiftLeftIfNull(query,awal,akhir);
		}
		else{
			i++;
		}
	}
	
	operasiMinus = cekMinus(query);
	i=0;
	j=0;
	while (strstr(query, "+")||(strstr(query, "-") && operasiMinus))
	{
		k = 0;
		if ((query[i] == '+'||query[i] == '-') && i>=0)
		{
			memset(operand1,'\0',250);
			memset(operand2,'\0',250);
			
			opp = query[i]; //assign operator
		
			deteksiOperand1(query,operand1,i,&j);
			
			awal = j + 1;//awal adalah variabel yang menunjukan indeks ke berapa operasi dimulai
			
			deteksiOperand2(query,operand2,i,&j);
			
			akhir = j - 1; //akhir adalah variabel yang menunjukkan indeks ke berapa operasi berakhir
			strrev(operand1); //karena operand1 diassign secara terbalik, maka harus di reverse
		
			//convert to float
			operandNum1 = atof(operand1); 
			operandNum2 = atof(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			//float to string
			sprintf(temp, "%f", hasil);
		
			int penampung_akhir; // dibuat untuk menampung nilai akhir
			
			shiftRight(query,temp,awal,akhir);
			
			penampung_akhir = akhir;
			
			penampung = awal;
			//mengisi range operasi dengan =
			while (awal <= akhir)
			{
				query[awal] = '=';
				awal++;
			}
		
			awal = penampung;
			int iawal,iakhir,space;
			space=akhir;
	
			akhir=penampung_akhir;
			int index;
	
			penampung=awal;
			
			//mengisi hasil kedalam array query
			assignHasil(query,temp,awal);
				
			shiftLeft(query,space);
	
			awal = penampung;
			penampung = akhir;
		
			// dibawah adalah untuk shift query
			shiftLeftIfNull(query,awal,akhir);
		}
		else{
			i++;
		}
		operasiMinus = cekMinus(query);
	}
	hasil = atof(query);	
	return hasil;
}
