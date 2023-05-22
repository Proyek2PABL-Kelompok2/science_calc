#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "difa.h"
#include "fathia.h"


float hitungTrigono(char *query){
//int angka;
//	if(strstr(query,"sin")){
//    	sscanf(query,"sin(%d)",&angka);
//		return sinus(angka);
//	}
//	if(strstr(query,"cos")){
//    	sscanf(query,"cos(%d)",&angka);
//    	return cosinus(angka);
//	}
//	if(strstr(query,"tan")){
//    	sscanf(query,"tan(%d)",&angka);
//    	return tangent(angka);
//	}
//	if (strstr(query,"sec")){
//		sscanf(query,"sec(%d)",&angka);
//    	return secan(angka);
//	}
//	if (strstr(query,"cot")){
//		sscanf(query,"cot(%d)",&angka);
//    	return cotangent(angka);
//	}
//	if (strstr(query,"cosec")){
//		sscanf(query,"cosec(%d)",&angka);
//    	return cosecan(angka);
//	}

}
double sinus(float angka){
	double result = 0.0;
    int i;

    for (i = 0; i <= 25; ++i) { // Menambah jumlah suku menjadi 25
        int exponent = 2 * i + 1;
        int sign = i % 2 == 0 ? 1 : -1;
        double term = sign * pow(angka, exponent) / faktoril(exponent);
        result += term;
    }

    return result;
}

double cosinus(float angka){
	double result = 0.0;
    int i;

    for (i = 0; i <= 25; ++i) { // Menambah jumlah suku menjadi 25
        int exponent = 2 * i;
        int sign = i % 2 == 0 ? 1 : -1;
        double term = sign * pow(angka, exponent) / faktoril(exponent);
        result += term;
    }

    return result;
}

double tangent(double angka){
	return sinus(angka) / cosinus(angka);
}

double to_radian(double angka) {
//    return angka * PI / 180.0;
}

double sindeg(double angka) {
    double radian = to_radian(angka);
    return sinus(radian);
}

double cosdeg(double angka) {
    double radian = to_radian(angka);
    return cosinus(radian);
}

double tandeg(double angka) {
    double radian = to_radian(angka);
    return tangent(radian);
}

double secan(double angka){
	return 1/cosinus(angka);
}

double cotangent(double angka){
	return cosinus(angka)/sinus(angka);
}
float cosecan(float angka){
	return 1/sinus(angka);
}


//float operasi(char opp,float operandNum1, float operandNum2){
//	float hasil;
//			if (opp=='^'){
//				hasil=pow(operandNum1,operandNum2);
//			}
//			else if (opp=='v'){
//				hasil=akarPangkat(operandNum2,operandNum1);
//			}
//			else if(opp=='*'){
//				hasil = perkalian(operandNum1,operandNum2);
//			}
//			else if(opp=='/'){
//				hasil = pembagian(operandNum1,operandNum2);
//			}
//			else if(opp=='+'){
//				hasil=penjumlahan(operandNum1,operandNum2);
//			}
//			
//			else if(opp=='-'){
//				hasil = pengurangan(operandNum1,operandNum2);
//			}
//	return hasil;
//	
//}

//float hitungQuery(char query[]){
//	char operand1[250], operand2[250];
//	int i, j;
//	char opp;
//	float hasil,operandNum1,operandNum2;
//	int iteration;
//	char temp[20];
//	int k, awal, akhir, penampung, iTemp;
//	i = 0;
//	j = 0;
//		while (strstr(query, "^") || strstr(query, "v"))
//	{
//		
//		k = 0;
//		if (query[i] == '^' || (query[i] == 'v' && i>=0))
//		{
//			memset(operand1,'\0',250);
//			memset(operand2,'\0',250);
//			
//			opp = query[i]; //assign operator
//				
//			j = i - 1;
//		
//			while ((isdigit(query[j])||query[j]=='.' ) && j >= 0) // deteksi operand 1
//			{
//				
//				operand1[k] = query[j];
//				j--;
//				k++;
//			}
//			
//			
//			awal = j + 1;//awal adalah variabel yang menunjukan indeks ke berapa operasi dimulai
//			j = i + 1;
//			k = 0;
//			while ((isdigit(query[j])||query[j]=='.' ) && query[j] != '\0') // deteksi operand 2
//			{
//				operand2[k] = query[j];
//				j++;
//				k++;
//			}
//			akhir = j - 1; //akhir adalah variabel yang menunjukkan indeks ke berapa operasi berakhir
//			strrev(operand1); //karena operand1 diassign secara terbalik, maka harus di reverse
//		
//		
//			//convert to float
//			operandNum1 = atof(operand1); 
//			operandNum2 = atof(operand2);
//			
//			hasil = operasi(opp,operandNum1,operandNum2);
//			
//			//float to string
//			sprintf(temp, "%f", hasil);
//		
//
//			
//		
//			int penampung_akhir; // dibuat untuk menampung nilai akhir
//			
//
//			
//			penampung_akhir = akhir;
//			
//			
//			int panjangTemp,panjangQuery,rangeOperasi,afterOperasi,penSize,iShift;
//			iShift=0;
//			panjangQuery=strlen(query);
//			penSize=panjangQuery;
//				rangeOperasi=akhir-awal+1;
//				afterOperasi=panjangQuery-akhir-1;
//			panjangTemp=strlen(temp);
//	
//			//melakukan geser kanan jika hasil operasi > range operasi
//			while (panjangTemp-1>rangeOperasi){
//				rangeOperasi=akhir-awal+1;
//				iShift=0;
//				while(iShift<afterOperasi){
//					query[panjangQuery]=query[panjangQuery-1];
//					query[panjangQuery-1]='=';
//					panjangQuery--;
//					iShift++;	
//				}
//				panjangQuery=penSize+1;
//				penSize++;
//				akhir++;
//			}
//			i=0;
//			penampung = awal;
//			//mengisi range operasi dengan =
//						while (awal <= akhir)
//			{
//				query[awal] = '=';
//				awal++;
//			}
//		
//			awal = penampung;
//			int iawal,iakhir,space;
//			space=akhir;
//	
//			akhir=penampung_akhir;
//			int index;
//		
//			
//		
//
//		penampung=awal;
//			
//			//mengisi hasil kedalam array query
//			iTemp = 0;
//			while (temp[iTemp] != '\0') // loop jika temp tidak null
//			{
//				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
//				iTemp++;
//				awal++;
//			}
//			
//			//menggeser ke kiri jika ada char antara 1 operasi dengan operasi lainnya
//			iShift=0;
//			while(iShift<=strlen(query)-1){
//				if(query[iShift]=='='&&query[space+1]!='\0'){
//					query[iShift]=query[space+1];
//					query[space+1]='=';
//					space++;
//				}
//				iShift++;
//				
//			}
//			
//	
//			
//			awal = penampung;
//			penampung = akhir;
//			 iawal = awal;
//			 iakhir = akhir;
//			// dibawah adalah untuk shift query
//			while (awal <= akhir)
//			{
//				if (query[iawal] == '\0')
//				{
//					while (query[iakhir + 1] != '\0')
//					{
//						query[iawal] = query[iakhir + 1];
//						query[iawal + 1] = '\0';
//						iawal++;
//
//						iakhir++;
//					}	
//				}			
//				iawal++;
//				awal++;
//			}
//		}
//		else{
//			i++;
//		}
//		}
//		i=0;
//		j=0;
//			while (strstr(query, "*") || strstr(query, "/"))
//	{
//		
//		k = 0;
//		if (query[i] == '*' || (query[i] == '/' && i>=0))
//		{
//			memset(operand1,'\0',250);
//			memset(operand2,'\0',250);
//			
//			opp = query[i]; //assign operator
//				
//			j = i - 1;
//		
//			while ((isdigit(query[j])||query[j]=='.' ) && j >= 0) // deteksi operand 1
//			{
//				
//				operand1[k] = query[j];
//				j--;
//				k++;
//			}
//			
//			
//			awal = j + 1;
//			j = i + 1;
//			k = 0;
//			while ((isdigit(query[j])||query[j]=='.' ) && query[j] != '\0') // deteksi operand 2
//			{
//				operand2[k] = query[j];
//				j++;
//				k++;
//			}
//			akhir = j - 1;
//			strrev(operand1);
//		
//		
//			
//			operandNum1 = atof(operand1);
//			operandNum2 = atof(operand2);
//			
//			hasil = operasi(opp,operandNum1,operandNum2);
//			
//			sprintf(temp, "%f", hasil);
//		
//
//			
//		
//			int penampung_akhir;
//			
//
//			
//			penampung_akhir = akhir;
//			
//			
//			int panjangTemp,panjangQuery,rangeOperasi,afterOperasi,penSize,iShift;
//			iShift=0;
//			panjangQuery=strlen(query);
//			penSize=panjangQuery;
//				rangeOperasi=akhir-awal+1;
//				afterOperasi=panjangQuery-akhir-1;
//			panjangTemp=strlen(temp);
//	
//			
//			while (panjangTemp-1>rangeOperasi){
//				rangeOperasi=akhir-awal+1;
//				iShift=0;
//				while(iShift<afterOperasi){
//					query[panjangQuery]=query[panjangQuery-1];
//					query[panjangQuery-1]='=';
//					panjangQuery--;
//					iShift++;	
//				}
//				panjangQuery=penSize+1;
//				penSize++;
//				akhir++;
//			}
//			i=0;
//			penampung = awal;
//						while (awal <= akhir)
//			{
//				query[awal] = '=';
//				awal++;
//			}
//		
//			awal = penampung;
//			int iawal,iakhir,space;
//			space=akhir;
//	
//			akhir=penampung_akhir;
//			int index;
//		
//			
//		
//
//		penampung=awal;
//			
//
//			iTemp = 0;
//			while (temp[iTemp] != '\0') // loop jika temp tidak null
//			{
//				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
//				iTemp++;
//				awal++;
//			}
//			
//			iShift=0;
//			while(iShift<=strlen(query)-1){
//				if(query[iShift]=='='&&query[space+1]!='\0'){
//					query[iShift]=query[space+1];
//					query[space+1]='=';
//					space++;
//				}
//				iShift++;
//				
//			}
//			
//	
//			
//			awal = penampung;
//			penampung = akhir;
//			 iawal = awal;
//			 iakhir = akhir;
//			// dibawah adalah untuk shift query
//			while (awal <= akhir)
//			{
//				if (query[iawal] == '\0')
//				{
//					while (query[iakhir + 1] != '\0')
//					{
//
//						query[iawal] = query[iakhir + 1];
//						query[iawal + 1] = '\0';
//						iawal++;
//
//						iakhir++;
//					}
//					
//				}
//				
//				iawal++;
//				awal++;
//			}
//
//		}
//		else{
//			i++;
//		}
//		}
//	i = 0;
//	j = 0;
//	while (strstr(query, "+") || strstr(query, "-"))
//	{
//		
//		k = 0;
//		if (query[i] == '+' || (query[i] == '-' && i>=0))
//		{
//			memset(operand1,'\0',250);
//			memset(operand2,'\0',250);
//			
//			opp = query[i]; //assign operator
//
//			j = i - 1;
//
//			while ((isdigit(query[j])||query[j]=='.' ) && j >= 0) // deteksi operand 1
//			{
//			
//				operand1[k] = query[j];
//				j--;
//				k++;
//			}
//			
//			
//			awal = j + 1;
//			j = i + 1;
//			k = 0;
//			while ((isdigit(query[j])||query[j]=='.' ) && query[j] != '\0') // deteksi operand 2
//			{
//				operand2[k] = query[j];
//				j++;
//				k++;
//			}
//			akhir = j - 1;
//			strrev(operand1);
//		
//
//			
//			operandNum1 = atof(operand1);
//			operandNum2 = atof(operand2);
//			
//			hasil = operasi(opp,operandNum1,operandNum2);
//			
//			sprintf(temp, "%f", hasil);
//
//
//			
//		
//			int penampung_akhir;
//			
//
//			
//			penampung_akhir = akhir;
//			
//		
//			int panjangTemp,panjangQuery,rangeOperasi,afterOperasi,penSize,iShift;
//			iShift=0;
//			panjangQuery=strlen(query);
//			penSize=panjangQuery;
//				rangeOperasi=akhir-awal+1;
//				afterOperasi=panjangQuery-akhir-1;
//			panjangTemp=strlen(temp);
//
//			
//			while (panjangTemp>rangeOperasi){
//				rangeOperasi=akhir-awal+1;
//				iShift=0;
//				while(iShift<afterOperasi){
//					query[panjangQuery]=query[panjangQuery-1];
//					query[panjangQuery-1]='=';
//					panjangQuery--;
//					iShift++;	
//				}
//				panjangQuery=penSize+1;
//				penSize++;
//				akhir++;
//			}
//			i=0;
//			penampung = awal;
//						while (awal <= akhir)
//			{
//				query[awal] = '=';
//				awal++;
//			}
//
//			awal = penampung;
//			int iawal,iakhir,space;
//			space=akhir;
//
//			akhir=penampung_akhir;
//			int index;
//		
//			
//
//		penampung=awal;
//			
//
//			iTemp = 0;
//			while (temp[iTemp] != '\0') // loop jika temp tidak null
//			{
//				query[awal] = temp[iTemp]; // assign isi temp ke query dengan indeks var awal
//				iTemp++;
//				awal++;
//			}
//
//			iShift=0;
//			while(iShift<=strlen(query)-1){
//				if(query[iShift]=='='&&query[space+1]!='\0'){
//					query[iShift]=query[space+1];
//					query[space+1]='=';
//					space++;
//				}
//				iShift++;
//				
//			}
//			
//
//			
//			awal = penampung;
//			penampung = akhir;
//			 iawal = awal;
//			 iakhir = akhir;
//			// dibawah adalah untuk shift query
//			while (awal <= akhir)
//			{
//				if (query[iawal] == '\0')
//				{
//					while (query[iakhir + 1] != '\0')
//					{
//
//						query[iawal] = query[iakhir + 1];
//						query[iawal + 1] = '\0';
//						iawal++;
//
//						iakhir++;
//					}
//					
//				}
//				
//				iawal++;
//				awal++;
//			}
//
//		}
//		else{
//			i++;
//		}
//		}
//		hasil = atof(query);
//		
//		return hasil;
//}

//===================LINKEDLIST==================
//void viewAsc(address First){ //fungsi untuk print isi linkedlist
//	address P;
//
//				P = First;//assign P dengan First (First adalah pointer yang menunjuk list pertama)
//				while (P != Nil)//terus loop sampai P == Null
//				{
//
//				if(info(P)!=Nil){
//					printf("%c |", info(P));//info berisi Operator
//				}
//				else{
//						printf("%g |", angka(P));//angka berisi angka
//				}
//				P = next(P);//iteration untuk pindah ke next list
//				}
//}
//address searchValue(address Q, address First, char operator1,char operator2){
//	Q=First;
//		while((info(Q)!=operator1&&info(Q)!=operator2)&&next(Q)!=NULL){
//						Q=next(Q);
//					}
//	if(next(Q)==Nil){
//		return next(Q);
//	}
//	else{
//		return Q;
//	}
//	
//		
//	
//}
//void insLast(address *P, address *Last,address *First){//merubah pointer dengan behavior insert last
//	if(*First==Nil||*Last==Nil){
//		
//					*First = *P;
//					*Last = *P;
//	}
//	else{
//	
//	prev(*P) = *Last;
//				next(*Last) = *P;
//				*Last = *P;
//}
//
//}
//address LLcreateListOperator(char opp)
//{
//	address D;
//	D = (address)malloc(sizeof(ElmtList)); // alokasi memori sebesar D
//	info(D) = opp;					   // assign value operator
//	angka(D)=Nil; //angka dibuat nill
//	next(D) = Nil;						   // membuat list menunjuk ke nil
//	prev(D) = Nil;
//	return D;
//}
//
//address LLcreateListAngka(char data[])
//{
//	float angka;
//	angka=atof(data);
//	address D;
//	D = (address)malloc(sizeof(ElmtList)); // alokasi memori sebesar D
//	angka(D) = angka;					   // assign value angka
//	info(D) = Nil;	//opp dibuat nill
//	next(D) = Nil;						   // membuat list menunjuk ke nil
//	prev(D) = Nil;
//	return D;
//}
//
//float MenentukanRumusHitung(address P){
////	if(info(P)=='+'){
////	return penjumlahan(angka(prev(P)),angka(next(P)));
////	}
////	else if(info(P)=='-'){
////	return pengurangan(angka(prev(P)),angka(next(P)));
////	}
////	else if(info(P)=='*'){
////	return perkalian(angka(prev(P)),angka(next(P)));
////	}
////	else if(info(P)=='/'){
////	return pembagian(angka(prev(P)),angka(next(P)));
////	}
////	else if(info(P)=='^'){
////	return pow(angka(prev(P)),angka(next(P)));
////	}
////	else if(info(P)=='v'){
////	return akarPangkat(angka(next(P)),angka(prev(P)));
////	}
//}
//
//void HitungOperasi(address P, address First,char operator1, char operator2){
//	address awalOperasi,akhirOperasi,Q;
//	P=searchValue(P,First,operator1,operator2);
//	while(P!=Nil){
//	
//	awalOperasi=prev(P);
//	akhirOperasi=next(P);
//
//	next(awalOperasi)=next(akhirOperasi);
//	if(next(akhirOperasi)!=Nil){
//		
//	Q=next(akhirOperasi);
//	prev(Q)=awalOperasi;
//	angka(prev(P))=MenentukanRumusHitung(P);
//	}
//
//	
//	free(P);
//	free(akhirOperasi);
//	P=searchValue(P,First,operator1,operator2);
//}
//}
//
//float HitungHasil(address First,address Last){
//	address P,Q,adaOperator,awalOperasi,akhirOperasi;
//	float operand1,operand2;
//	viewAsc(First);
//	P=First;
//	//*/
//	HitungOperasi(P,First,'*','/');
//	//+-
//	HitungOperasi(P,First,'+','-');
//	viewAsc(First);
// return angka(First);
//	
//}
//
//void LLBuatList(char query[], address *First, address *Last){
//	int iteration,j,i,hitung;
//	char data[255],opp;
//	float hasil;
//	address P;
//	*First=Nil;
//	*Last=Nil;
//	P=Nil;
//	memset(data,'\0',255);
//	hitung=0;
//	j=0;
//
//	iteration=0;
//
//	while(query[iteration]!='\0'){
//	memset(data,'\0',256);
//	opp='\0';
//	j=0;
//	while(isdigit(query[iteration])||query[iteration]=='.'||(query[iteration]=='-'&&iteration==0)||(iteration>0&&query[iteration]=='-'&&!isdigit(query[iteration-1]))){
//		data[j]=query[iteration];
//		iteration++;
//		j++;
//		
//	
//	}
//	
//	if(data!='\0'){
//		P=LLcreateListAngka(data);	
//		insLast(&P,Last,First);
//	hitung++;
//	}
//	
//		printf("< %s >",data);
//	if(query[iteration]=='^'||query[iteration]=='v'||query[iteration]=='*'||query[iteration]=='/'||query[iteration]=='+'||(query[iteration]=='-'&&iteration>0)||(query[iteration]=='-'&&isdigit(query[iteration-1]))){
//		opp=query[iteration];//CATATAN: cek ulang untuk operator -
//		iteration++;
//		P=LLcreateListOperator(opp);
//		insLast(&P,Last,First);
//		hitung++;
//
//	}
//	
//}
//	P=LLcreateListOperator('+');
//	insLast(&P,Last,First);
//	P=LLcreateListAngka(0);
//	insLast(&P,Last,First);
//
//
//	printf("\nNode : %d\n",hitung);
//	
//}


//Tree

double evaluate(treeNode* root) {
    if (root == NULL) {
        return 0.0;
    }

    // Evaluate the left and right subtrees recursively
    double left_val = evaluate(root->left);
    double right_val = evaluate(root->right);

    // Perform the operation based on the operator character
    switch (root->oper) {
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            return left_val / right_val;
        case '^':
            return pow(left_val, right_val);
        default:
            return root->num;
    }
}

int getPrecedence(char oper)
{
	switch (oper) {
        case '+':
        case '-':
        	return 1;
//            return ADDITION;
        case '*':
        case '/':
        	return 2;
//            return MULTIPLICATION;
        case '^':
        case 'v':
        	return 3;
//            return EXPONENT;
		case '\0':
        default:
        	return 0;
//            return PRECEDENCE_LOWEST;
    }
}

