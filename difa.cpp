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

float hitungQuery(char query[]){
	char operand1[250], operand2[250];
	int i, j;
	char opp;
	float hasil,operandNum1,operandNum2;
	int iteration;
	char temp[20];
	int k, awal, akhir, penampung, iTemp;
	i = 0;
	j = 0;
		while (strstr(query, "^") || strstr(query, "v"))
	{
		
		k = 0;
		if (query[i] == '^' || (query[i] == 'v' && i>=0))
		{
			memset(operand1,'\0',250);
			memset(operand2,'\0',250);
			
			opp = query[i]; //assign operator
				
			j = i - 1;
		
			while ((isdigit(query[j])||query[j]=='.' ) && j >= 0) // deteksi operand 1
			{
				
				operand1[k] = query[j];
				j--;
				k++;
			}
			
			
			awal = j + 1;//awal adalah variabel yang menunjukan indeks ke berapa operasi dimulai
			j = i + 1;
			k = 0;
			while ((isdigit(query[j])||query[j]=='.' ) && query[j] != '\0') // deteksi operand 2
			{
				operand2[k] = query[j];
				j++;
				k++;
			}
			akhir = j - 1; //akhir adalah variabel yang menunjukkan indeks ke berapa operasi berakhir
			strrev(operand1); //karena operand1 diassign secara terbalik, maka harus di reverse
		
		
			//convert to float
			operandNum1 = atof(operand1); 
			operandNum2 = atof(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			//float to string
			sprintf(temp, "%f", hasil);
		

			
		
			int penampung_akhir; // dibuat untuk menampung nilai akhir
			

			
			penampung_akhir = akhir;
			
			
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
			i=0;
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
			iTemp = 0;
			while (temp[iTemp] != '\0') // loop jika temp tidak null
			{
				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
				iTemp++;
				awal++;
			}
			
			//menggeser ke kiri jika ada char antara 1 operasi dengan operasi lainnya
			iShift=0;
			while(iShift<=strlen(query)-1){
				if(query[iShift]=='='&&query[space+1]!='\0'){
					query[iShift]=query[space+1];
					query[space+1]='=';
					space++;
				}
				iShift++;
				
			}
			
	
			
			awal = penampung;
			penampung = akhir;
			 iawal = awal;
			 iakhir = akhir;
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
		
		
			
			operandNum1 = atof(operand1);
			operandNum2 = atof(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			sprintf(temp, "%f", hasil);
		

			
		
			int penampung_akhir;
			

			
			penampung_akhir = akhir;
			
			
			int panjangTemp,panjangQuery,rangeOperasi,afterOperasi,penSize,iShift;
			iShift=0;
			panjangQuery=strlen(query);
			penSize=panjangQuery;
				rangeOperasi=akhir-awal+1;
				afterOperasi=panjangQuery-akhir-1;
			panjangTemp=strlen(temp);
	
			
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
			i=0;
			penampung = awal;
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
			

			iTemp = 0;
			while (temp[iTemp] != '\0') // loop jika temp tidak null
			{
				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
				iTemp++;
				awal++;
			}
			
			iShift=0;
			while(iShift<=strlen(query)-1){
				if(query[iShift]=='='&&query[space+1]!='\0'){
					query[iShift]=query[space+1];
					query[space+1]='=';
					space++;
				}
				iShift++;
				
			}
			
	
			
			awal = penampung;
			penampung = akhir;
			 iawal = awal;
			 iakhir = akhir;
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
			memset(operand1,'\0',250);
			memset(operand2,'\0',250);
			
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
		

			
			operandNum1 = atof(operand1);
			operandNum2 = atof(operand2);
			
			hasil = operasi(opp,operandNum1,operandNum2);
			
			sprintf(temp, "%f", hasil);


			
		
			int penampung_akhir;
			

			
			penampung_akhir = akhir;
			
		
			int panjangTemp,panjangQuery,rangeOperasi,afterOperasi,penSize,iShift;
			iShift=0;
			panjangQuery=strlen(query);
			penSize=panjangQuery;
				rangeOperasi=akhir-awal+1;
				afterOperasi=panjangQuery-akhir-1;
			panjangTemp=strlen(temp);

			
			while (panjangTemp>rangeOperasi){
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
			i=0;
			penampung = awal;
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
			

			iTemp = 0;
			while (temp[iTemp] != '\0') // loop jika temp tidak null
			{
				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
				iTemp++;
				awal++;
			}

			iShift=0;
			while(iShift<=strlen(query)-1){
				if(query[iShift]=='='&&query[space+1]!='\0'){
					query[iShift]=query[space+1];
					query[space+1]='=';
					space++;
				}
				iShift++;
				
			}
			

			
			awal = penampung;
			penampung = akhir;
			 iawal = awal;
			 iakhir = akhir;
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
		hasil = atof(query);
		
		return hasil;
}

//LINKEDLIST
void viewAsc(address First){ //fungsi untuk print isi linkedlist
	address P;

				P = First;//assign P dengan First (First adalah pointer yang menunjuk list pertama)
				while (P != Nil)//terus loop sampai P == Null
				{

				if(info(P)!=Nil){
					printf("%c |", info(P));//info berisi Operator
				}
				else{
						printf("%g |", angka(P));//angka berisi angka
				}
				P = next(P);//iteration untuk pindah ke next list
				}
}
void insLast(address *P, address *Last,address *First){//merubah pointer dengan behavior insert last
	if(*First==Nil||*Last==Nil){
		
					*First = *P;
					*Last = *P;
	}
	else{
	
	prev(*P) = *Last;
				next(*Last) = *P;
				*Last = *P;
}
}
address LLcreateListOperator(char opp)
{
	address D;
	D = (address)malloc(sizeof(ElmtList)); // alokasi memori sebesar D
	info(D) = opp;					   // assign value operator
	angka(D)=Nil; //angka dibuat nill
	next(D) = Nil;						   // membuat list menunjuk ke nil
	prev(D) = Nil;
	return D;
}

address LLcreateListAngka(char data[])
{
	float angka;
	angka=atof(data);
	address D;
	D = (address)malloc(sizeof(ElmtList)); // alokasi memori sebesar D
	angka(D) = angka;					   // assign value angka
	info(D) = Nil;	//opp dibuat nill
	next(D) = Nil;						   // membuat list menunjuk ke nil
	prev(D) = Nil;
	return D;
}

void LLBuatList(char query[]){
	int iteration,j,i,hitung;
	char data[255],opp;
	address P,First,Last;
	First=Nil;
	Last=Nil;
	P=Nil;
	memset(data,'\0',255);
	hitung=0;
	j=0;

	iteration=0;

	while(query[iteration]!='\0'){
	memset(data,'\0',256);
	opp='\0';
	j=0;
	
	//dibawah untuk catch angka
	while(isdigit(query[iteration])||query[iteration]=='.'||(query[iteration]=='-'&&iteration==0)||(iteration>0&&query[iteration]=='-'&&!isdigit(query[iteration-1]))){
		data[j]=query[iteration];
		iteration++;
		j++;
		
	
	}
	
	if(data!='\0'){//jika var data yang berisi angka tidak null
		P=LLcreateListAngka(data);	//buat list
		insLast(&P,&Last,&First); // sambungkan list dengan behavior insert last
	hitung++;//iteration untuk hitung jumlah node (debugging)
	}
	
		printf("< %s >",data); //print untuk debugging
		
		//dibawah untuk catch operator
	if(query[iteration]=='^'||query[iteration]=='v'||query[iteration]=='*'||query[iteration]=='/'||query[iteration]=='+'||(query[iteration]=='-'&&iteration>0)||(query[iteration]=='-'&&isdigit(query[iteration-1]))){
		opp=query[iteration];//Assign operator
		
		P=LLcreateListOperator(opp);//Buat list 
		insLast(&P,&Last,&First);//sambungkan dengan behavior insert last
		hitung++;//iteration untuk hitung jumlah node (debugging)
		iteration++;

	}
	
}

	printf("\nNode : %d\n",hitung);//jumlah node (debugging)
	viewAsc(First); //print linked List dari awal ke akhir
}
