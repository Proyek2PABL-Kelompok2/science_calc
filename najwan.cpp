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

float konverter_panjang_dan_massa(int o, int p, float y){
	// o = pilihan_panjang
	// p = pilihan_panjang2
	// y = angka yang dimasukan untuk dikonvert
	int i; //untuk penampung
	int x = 1; // untuk penampung perkalian 10
	if(o < p){ //contohnya dari km ke m
		i = p - o; 
		while(i>0){
			x = x*10;
			i = i - 1;
		}
		y = y*x;
	}
	else if(o > p){		
		i = o - p;
		while(i>0){
			x = x*10;
			i = i - 1;
		}
		y = y/x;
	}
	else{
		i = 1;	
	}
	return y;
}

double konverter_luas(float c, float d, double e){
	int i; //untuk penampung
	double x = 1;//untuk penampung perkalian 100
	if(c < d){ //contohnya dari km ke m
		i = d - c; //nilai i adalah 3
		while(i>0){
			x = x*100;
			i = i - 1;
		}
		e = e*x;
	}
	else if(c > d){		
		i = c - d;
		while(i>0){
			x = x*100;
			i = i - 1;
		}
		e = e/x;	
	}
	else{
		e = e;
	}
	return e;
}

double konverter_volume(float c, float d, double e){
	int i; //untuk penampung
	double x = 1;//untuk penampung perkalian 
	if(c < d){ //contohnya dari km ke m
		i = d - c; //nilai i adalah 3
		while(i>0){
			x = x*1000;
			i = i - 1;
		}
		e = e*x;
	}
	else if(c > d){		
		i = c - d;
		while(i>0){
			x = x*1000;
			i = i - 1;
		}
		e = e/x;
	}
	else{
		e = e;	
	}
	return e;
}

//konvert dari detik	
int secToMin(float angka){
	float detik, menit;
	detik = angka;
	menit = detik / 60;
	
	return menit;
}

int secToHour(float angka){
	float detik, jam;
	detik = angka;
	jam = detik / 3600;
	
	return jam;
}

int secToDay(float angka){
	float detik, hari;
	detik = angka;
	hari = detik / 86400;
	
	return hari;
}

int secToWeek(float angka){
	float detik, minggu;
	detik = angka;
	minggu = detik/604800;
	
	return minggu;
}

int secToMounth(float angka){
	float detik, bulan;
	detik = angka;
	bulan = detik/2592000;
	
	return bulan;
}

int secToYear(float angka){
	float detik, tahun;
	detik = angka;
	tahun = detik/31104000;
	
	return tahun;
}

//konvert dari menit
int minToSec(float angka){
	float menit, detik;
	menit = angka;
	detik = menit*60;
	
	return detik;
}

int minToHour(float angka){
	float menit, jam;
	menit = angka;
	jam = menit / 60;
	
	return jam;
}

int minToDay(float angka){
	float menit, hari;
	menit = angka;
	hari = menit / 1440;
	
	return hari;
}

int minToWeek(float angka){
	float menit, minggu;
	menit = angka;
	minggu = menit/10080;
	
	return minggu;
}

int minToMounth(float angka){
	float menit, bulan;
	menit = angka;
	bulan = menit/43200;
	
	return bulan;
}

int minToYear(float angka){
	float menit, tahun;
	menit = angka;
	tahun = menit/518400;
	
	return tahun;
}

//konvert dari jam
int hourToSec(float angka){
	float jam, detik;
	jam = angka;
	detik = jam * 3600;
	
	return detik;
}

int hourToMin(float angka){
	float jam, menit;
	jam = angka;
	menit = jam * 60;
	
	return menit;
}

int hourToDay(float angka){
	float jam, hari;
	jam = angka; 
	hari = jam/24;
	
	return hari;
}

int hourToWeek(float angka){
	float jam, minggu;
	jam = angka;
	minggu = jam/168;
	
	return minggu;
}

int hourToMounth(float angka){
	int jam, bulan;
	jam = angka;
	bulan = jam/672;
	
	return bulan;
}

int hourToYear(float angka){
	float jam, tahun;
	jam = angka;
	tahun = jam/8064;
	
	return tahun;
}

//konvert dari hari
int dayToSec(float angka){
	float hari, detik;
	hari = angka;
	detik = hari*86400;
	
	return detik;
}

int dayToMin(float angka){
	float hari, menit;
	hari = angka;
	menit = hari * 1440;
	
	return menit;
}

int dayToHour(float angka){
	float hari, jam;
	hari = angka;
	jam = hari*24;	
	
	return jam;
}

int dayToWeek(float angka){
	float hari, minggu;
	hari = angka;
	minggu = hari / 7;
	
	return minggu;
}

int dayToMounth(float angka){
	float hari, bulan;
	hari = angka;
	bulan = hari /30;
	
	return bulan;
}

int dayToYear(float angka){
	float hari, tahun;
	hari = angka;
	tahun = hari / 365;
	
	return tahun;
}

//konvert dari minggu
int weekToSec(float angka){
	float minggu, detik;
	minggu = angka;
	detik = minggu*604800;
	
	return detik;
}

int weekToMin(float angka){
	float minggu, menit;
	minggu = angka;
	menit = minggu*10080;
	
	return menit;
}

int weekToHour(float angka){
	float minggu, jam;
	minggu = angka;
	jam = minggu*168;	
	
	return jam;
}

int weekToDay(float angka){
	float minggu, hari;
	minggu = angka;
	hari = minggu*7;
	
	return hari;
}

int weekToMounth(float angka){
	float minggu, bulan;
	minggu = angka; 
	bulan = minggu/4;
	
	return bulan;
}

int weekToYear(float angka){
	float minggu, tahun;
	minggu = angka;
	tahun = minggu/52;
	
	return tahun;
}

//konvert dari bulan
int mounthToSec(float angka){
	float bulan, detik;
	bulan = angka;
	detik = bulan*2592000;
	
	return detik;
}

int mounthToMin(float angka){
	float bulan, menit;
	bulan = angka;
	menit = bulan*43200;
	
	return menit;
}

int mounthToHour(float angka){
	float bulan, jam;
	bulan = angka;
	jam = bulan*720;
	
	return jam;
}

int mounthToDay(float angka){
	float bulan, hari;
	bulan = angka;
	hari = bulan*30;
	
	return hari;
}

int mounthToWeek(float angka){
	float bulan, minggu;
	bulan = angka;
	minggu = bulan*4;
	
	return minggu;
}

int mounthToYear(float angka){
	float bulan, tahun;
	bulan = angka;
	tahun = bulan / 12;
	
	return tahun;
}

//konvert dari tahun
int yearToSec(float angka){
	float tahun, detik;
	tahun = angka;
	detik = tahun*31104000;
	
	return detik;
}

int yearToMin(float angka){
	float tahun, menit;
	tahun = angka;
	menit = tahun*518400;
	
	return menit;
}

int yearToHour(float angka){
	float tahun, jam;
	tahun = angka;
	jam = tahun*8640;
	
	return jam;
}

int yearToDay(float angka){
	float tahun, hari;
	tahun = angka; 
	hari = tahun*365;	
	
	return hari;
}

int yearToWeek(float angka){
	float tahun, minggu;
	tahun = angka; 
	minggu = tahun*52;
	
	return minggu;
}

int yearToMounth(float angka){
	float tahun,bulan;
	tahun = angka;
	bulan = tahun*12;
	
	return bulan;
}

float celciToFar(float angka){
	float c,f;
	c = angka;
	f = (c*1.8)+32;
	
	return f;	
}

float celciToKel(float angka){
	float c,k;
	c = angka;
	k = c + 273.15;
	
	return k;	
}

float celciToRea(float angka){
	float c,r;
	c = angka;
	r = (c*4)/5;

	return r;
}

float farToCelci(float angka){
	float f,c;
	f = angka;
	c = (f-32)*5/9;
	
	return c;
}

float farToKel(float angka){
	float f,c,k;
	f = angka;
	c = (f-32)*5/9;
	k = c + 273.15;

	return k;	
}

float farToRea(float angka){
	float f,r;
	f = angka;
	r = (f-32)*4/9;

	return r;
}

float kelToCelci(float angka){
	float k,c;
	k = angka;
	c = k-273.15;

	return c;
}

float kelToFar(float angka){
	float k,c,f;
	k = angka;
	c = k-273.15;
	f = (c*1.8)+32; 

	return f;
}

float kelToRea(float angka){
	float r,k;
	k = angka;
	r = (k-273.15)*4/5;
	
	return r;
}

float reaToCelci(float angka){
	float r,c;
	r = angka;
	c = r*5/4;

	return c;
}

float reaToFar(float angka){
	float r,c,f;
	r = angka;
	c = r*5/4;
	f = (c*1.8)+32;

	return f;
}

float reaToKel(float angka){
	float k, r;
	r = angka;
	k = (r*5/4)+273.15;

	return k;
}

//void utama
void najwan(){
	float hasil,n, a,b,c,d,e,angka,pilihan_dari,pilihan_ke;
	float pilihan_jawaban,pilihan_jawaban2;
	int pilihan;
	char operasi;
	int detik, menit, jam, hari, minggu, bulan, tahun;
	int f,k,r,q,w;
	
	
	printf("masukan operasi aritmatika \n");
	scanf("%f",a);scanf("%c",operasi);scanf("%f",b);
	switch(operasi){
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

void untuk_pemilihan_konverter(){
	int pilihan;	
	printf("==========Satuan apa yang ingin anda konversi?========== \n");
	printf("\t\t1. Satuan Panjang \n");
	printf("\t\t2. Satuan Luas \n");
	printf("\t\t3. Satuan Volume \n");
	printf("\t\t4. Satuan Kapasitas \n");
	printf("\t\t5. Satuan Massa \n");
	printf("\t\t6. Satuan Waktu \n");
	printf("\n\t\tjawab : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		
		case 1:
			panjang();
		case 2:
			luas();
		case 3:
			volume();
		case 4:
			massa();
		case 5:;
			waktu();
		case 6:
			suhu();
		default:
			printf("masukan angka dengan benar");
			
	}
	
}

void panjang(){
	int pilihan_panjang,pilihan_panjang2;
	float angka,n;
	printf("\n\n===========Pilih satuan yang akan anda konversikan===========\n");
	printf("\t\t1. Km\n");
	printf("\t\t2. Hm\n");
	printf("\t\t3. Dam\n");
	printf("\t\t4. M\n");
	printf("\t\t5. dm\n");
	printf("\t\t6. cm\n");
	printf("\t\t7. mm\n");
	printf("dari : ");scanf("%d", &pilihan_panjang);
	printf("ke : ");scanf("%d", &pilihan_panjang2);
	printf("masukan angka ");scanf("%lf", &angka);
	
	n = konverter_panjang_dan_massa(pilihan_panjang,pilihan_panjang2,angka);
	printf("-----hasil dari konverter : %.6f -----",n);	
}

//	
//	switch(){
//		case '+':
//			hasil = penjumlahan(a,b);
//			
//			break;
//		case '-':
//			hasil = pengurangan(a,b);
//			
//			break;
//		case '*':
//			hasil = perkalian(a,b);
//			
//			break;
//		case '/':
//			hasil = pembagian(a,b);
//			
//			break;
//		case '%':
//			hasil = modulus(a,b);
//			
//			break;
//		default:
//			printf("anda salah memasukan operasi hitung");
//	}
//	
//	switch(){
//		
//		case 1:
//			n = konverter_panjang_dan_massa(pilihan_dari,pilihan_ke,angka);
//		case 2:
//			n = konverter_luas(c,d,e);
//		case 3:
//			n = konverter_volume(c,d,e);
//		case 4:
//			n = konverter_panjang_dan_massa(pilihan_dari,pilihan_ke,angka);
//		case 5:
//			waktu();
//		case 6:
//			suhu();
//			
//	}
//	
//}

//void waktu(int jawaban, int jawaban2, int detik, int menit, int jam, int hari, int minggu, int bulan, int tahun, int angka){
void luas(){
	int pilihan_panjang,pilihan_panjang2;
	long double angka,n;
	printf("\n\n===========Pilih satuan yang akan anda konversikan===========\n");
	printf("\t\t1. Km\n");
	printf("\t\t2. Hm\n");
	printf("\t\t3. Dam\n");
	printf("\t\t4. M\n");
	printf("\t\t5. dm\n");
	printf("\t\t6. cm\n");
	printf("\t\t7. mm\n");
	printf("dari : ");scanf("%d", &pilihan_panjang);
	printf("ke : ");scanf("%d", &pilihan_panjang2);
	printf("masukan angka ");scanf("%Lf", &angka);
	
	n = konverter_luas(pilihan_panjang,pilihan_panjang2,angka);
	printf("-----hasil dari konverter : %.12Lf -----",n);	
}

void volume(){
	int pilihan_panjang,pilihan_panjang2;
	long double angka,n;
	printf("\n\n===========Pilih satuan yang akan anda konversikan===========\n");
	printf("\t\t1. Km\n");
	printf("\t\t2. Hm\n");
	printf("\t\t3. Dam\n");
	printf("\t\t4. M\n");
	printf("\t\t5. dm\n");
	printf("\t\t6. cm\n");
	printf("\t\t7. mm\n");
	printf("dari : ");scanf("%d", &pilihan_panjang);
	printf("ke : ");scanf("%d", &pilihan_panjang2);
	printf("masukan angka ");scanf("%Lf", &angka);	
	
	n = konverter_volume(pilihan_panjang,pilihan_panjang2,angka);
	printf("-----hasil dari konverter : %.16Lf -----",n);
}

void massa(){
	int pilihan_panjang,pilihan_panjang2;
	float angka,n;
	printf("\n\n===========Pilih satuan yang akan anda konversikan===========\n");
	printf("\t\t1. Kg\n");
	printf("\t\t2. Hg\n");
	printf("\t\t3. Dag\n");
	printf("\t\t4. gram\n");
	printf("\t\t5. dg\n");
	printf("\t\t6. cg\n");
	printf("\t\t7. mg\n");
	printf("dari : ");scanf("%d", &pilihan_panjang);
	printf("ke : ");scanf("%d", &pilihan_panjang2);
	printf("masukan angka ");scanf("%lf", &angka);
	
	n = konverter_panjang_dan_massa(pilihan_panjang,pilihan_panjang2,angka);
	printf("-----hasil dari konverter : %.6f -----",n);	
}

void waktu(){
	int detik = 0,
		menit = 0,
		jam = 0,
		hari = 0,
		minggu = 0,
		bulan = 0, 
		tahun = 0;
	int jawaban,jawaban2;
	float angka; 
	
	printf("==========konversi satuan waktu==========\n");
	printf("\t\t1. Detik\n");
	printf("\t\t2. Menit\n");	
	printf("\t\t3. Jam\n");
	printf("\t\t4. Hari\n");
	printf("\t\t5. Minggu\n");
	printf("\t\t6. Bulan\n");
	printf("\t\t7. Tahun\n");
	printf("dari : ");scanf("%d",&jawaban);
	printf("ke : ");scanf("%d",&jawaban2);
	printf("masukan angka yang akan di konversikan : ");scanf("%f",&angka);
	
	if(jawaban==1 && jawaban2==2){
		//detik ke menit
		detik = angka;
		menit = secToMin(detik);
		
	}
	else if(jawaban==1 && jawaban2==3){
		//detik ke jam
		detik = angka;
		jam = secToHour(detik);
		detik = detik%3600;
		menit = secToMin(detik);
		detik = detik%60;
	}
	
	else if(jawaban==1 && jawaban2==4){
		//detik ke hari
		detik = angka;
		hari = secToDay(angka);
		detik = detik%86400;
		jam = secToHour(detik);
		detik = detik%3600;
		menit = secToMin(detik);
		detik = detik%60;
	}
	
	else if(jawaban==1 && jawaban2==5){
		//detik ke minggu
		detik = angka;
		minggu = secToWeek(detik);
		detik = detik%604800;
		hari = secToDay(detik);
		detik = detik%86400;
		jam = secToHour(detik);
		detik = detik%3600;
		menit = secToMin(detik);
		detik = detik%60;
	}
	
	else if(jawaban==1 && jawaban2==6){
		//detik ke bulan
		detik = angka;
		bulan = secToMounth(detik);
		detik = detik%2592000;
		minggu = secToWeek(detik);
		detik = detik%604800;
		hari = secToDay(detik);
		detik = detik%86400;
		jam = secToHour(detik);
		detik = detik%3600;
		menit = secToMin(detik);
		detik = detik%60;
	}
	
	else if(jawaban==1 && jawaban2==7){
		//detik ke tahun
		detik = angka;
		tahun = secToYear(detik);
		detik = detik%31104000;
		bulan = secToMounth(detik);
		detik = detik%2592000;
		minggu = secToWeek(detik);
		detik = detik%604800;
		hari = secToDay(detik);
		detik = detik%86400;
		jam = secToHour(detik);
		detik = detik%3600;
		menit = secToMin(detik);
		detik = detik%60;
	}		
	
	else if(jawaban==2 && jawaban2==1){
		//menit ke detik
		menit = angka;
		detik = minToSec(menit);
		menit = 0;
	}
	
	else if(jawaban==2 && jawaban2==3){
		//menit ke jam
		menit = angka;
		jam = minToHour(menit);
		menit = menit%60;
	}
	
	else if(jawaban==2 && jawaban2==4){
		//menit ke hari
		menit = angka;
		hari = minToDay(menit);
		menit = menit%1440;
		jam = minToHour(menit);
		menit = menit%60;
	}
	
	else if(jawaban==2 && jawaban2==5){
		//menit ke minggu
		menit = angka;
		minggu = minToWeek(menit);
		menit =menit%10080;
		hari = minToDay(menit);
		menit = menit%1440;
		jam = minToHour(menit);
		menit = menit%60;
	}
	
	else if(jawaban==2 && jawaban2==6){
		//menit ke bulan
		menit = angka;
		bulan = minToMounth(menit);
		menit = menit%43200;
		minggu = minToWeek(menit);
		menit =menit%10080;
		hari = minToDay(menit);
		menit = menit%1440;
		jam = minToHour(menit);
		menit = menit%60;
	}
	
	else if(jawaban==2 && jawaban2==7){
		//menit ke tahun
		menit = angka;
		tahun = minToYear(menit);
		menit = menit%518400;
		bulan = minToMounth(menit);
		menit = menit%43200;
		minggu = minToWeek(menit);
		menit =menit%10080;
		hari = minToDay(menit);
		menit = menit%1440;
		jam = minToHour(menit);
		menit = menit%60;
	}	
		
	else if(jawaban==3 && jawaban2==1){
		//jam ke detik
		detik = hourToSec(angka);
		jam = 0;
	}
	
	else if(jawaban==3 && jawaban2==2){
		//jam ke menit
		menit = hourToMin(angka);
		jam = 0;
		
	}
	
	else if(jawaban==3 && jawaban2==4){
		//jam ke hari
		jam = angka;
		hari = hourToDay(jam);
		jam = jam%24;	
	}
	
	else if(jawaban==3 && jawaban2==5){
		//jam ke minggu
		jam = angka;
		minggu = hourToWeek(jam);
		jam = jam%168;
		hari = hourToDay(jam);
		jam = jam%24;
	}
	
	else if(jawaban==3 && jawaban2==6){
		//jam ke bulan
		jam = angka;
		bulan = hourToMounth(jam);
		jam = jam%672;
		minggu = hourToWeek(jam);
		jam = jam%168;
		hari = hourToDay(jam);
		jam = jam%24; 
	}
	
	else if(jawaban==3 && jawaban2==7){
		////jam ke tahun
		jam = angka;
		tahun = hourToYear(jam);
		jam = jam%8064;
		bulan = hourToMounth(jam);
		jam = jam%672;
		minggu = hourToWeek(jam);
		jam = jam%168;
		hari = hourToDay(jam);
		jam = jam%24; 
		
	}
	
	else if(jawaban==4 && jawaban2==1){
		//hari ke detik
		detik = dayToSec(angka);
		hari = 0;
	}
	
	else if(jawaban==4 && jawaban2==2){
		//hari ke menit
		menit = dayToMin(angka);
		hari = 0;
	}

	else if(jawaban==4 && jawaban2==3){
		//hari ke jam
		jam = dayToHour(angka);
		hari = 0;
	}
	
	else if(jawaban==4 && jawaban2==5){
		//hari ke minggu
		hari = angka;
		minggu = dayToWeek(hari);
		hari = hari%7;
	}
	
	else if(jawaban==4 && jawaban2==6){
		//hari ke bulan
		hari = angka;
		bulan = dayToMounth(hari);
		hari = hari%30;
		minggu = dayToWeek(hari);
		hari = hari%7;
	}
	
	else if(jawaban==4 && jawaban2==7){
		//hari ke tahun
		hari = angka;
		tahun = dayToYear(hari);
		hari = hari%365;
		bulan = dayToMounth(hari);
		hari = hari%30;
		minggu = dayToWeek(hari);
		hari = hari%7;
	}

	else if(jawaban==5 && jawaban2==1){
		//minggu ke detik
		detik = weekToSec(angka);
		minggu = 0;
	}

	else if(jawaban==5 && jawaban2==2){
		//minggu ke menit
		menit = weekToMin(angka);
		minggu = 0;
	}
	
	else if(jawaban==5 && jawaban2==3){
		//minggu ke jam
		jam = weekToHour(angka);
		minggu = 0;
	}
	
	else if(jawaban==5 && jawaban2==4){
		//minggu ke hari
		hari = weekToDay(angka);
		minggu = 0;
	}
	
	else if(jawaban==5 && jawaban2==6){
		//minggu ke bulan
		minggu = angka;
		bulan = weekToMounth(minggu);
		minggu = minggu%4;
	}
	
	else if(jawaban==5 && jawaban2==7){
		//minggu ke tahun
		minggu = angka;
		tahun = weekToYear(minggu);
		minggu = minggu%52;
		bulan = weekToMounth(minggu);
		minggu = minggu%4;
		
	}
	
	else if(jawaban==6 && jawaban2==1){
		//bulan ke detik
		detik = mounthToSec(angka);
		bulan = 0;
	}
	
	else if(jawaban==6 && jawaban2==2){
		//bulan ke menit
		menit = mounthToMin(angka);
		bulan = 0;
	}
	
	else if(jawaban==6 && jawaban2==3){
		//bulan ke jam 
		jam = mounthToHour(angka);
		bulan = 0;
	}
	
	else if(jawaban==6 && jawaban2==4){
		//bulan ke hari 
		hari = mounthToDay(angka);
		bulan = 0;
	}
	
	else if(jawaban==6 && jawaban2==5){
		//bulan ke minggu
		minggu = mounthToWeek(angka);
		bulan = 0;
	}
	
	else if(jawaban==6 && jawaban2==7){
		//bulan ke tahun
		bulan = angka;
		tahun = mounthToYear(bulan);
		bulan = bulan%12;	
	}
	
	else if(jawaban==7 && jawaban2==1){
		//tahun ke detik
		detik = yearToSec(angka);
		tahun = 0;
	}
	
	else if(jawaban==7 && jawaban2==2){
		//tahun ke menit
		menit = yearToMin(angka);
		tahun = 0;
	}
	
	else if(jawaban==7 && jawaban2==3){
		//tahun ke jam
		jam = yearToHour(angka);
		tahun = 0;
	}
	
	else if(jawaban==7 && jawaban2==4){
		//tahun ke hari
		hari = yearToDay(angka);
		tahun = 0;
	}
	
	else if(jawaban==7 && jawaban2==5){
		//tahun ke minggu
		minggu = yearToWeek(angka);
		tahun = 0;
	}
	
	else if(jawaban==7 && jawaban2==6){
		//tahun ke bulan
		bulan = yearToMounth(angka);
		tahun = 0;
	}
	
	else if(jawaban==jawaban2){
		printf("tidak ada perubahan\n");
	}
	
	else{
		printf("piihan yang anda masukan kurang tepat\n");
	}
	printf("%d tahun, %d bulan, %d minggu, %d hari,%d jam, %d menit, %d detik",tahun, bulan, minggu, hari, jam, menit, detik); 
	
}	

void suhu(){
	int jawaban, jawaban2; 
	float angka, f, c, r, k;
	printf("==========konversi satuan suhu==========\n");
	printf("\t\t1. celcuis\n");
	printf("\t\t2. fahrenheit\n");	
	printf("\t\t3. kelvin\n");
	printf("\t\t4. reamur\n");
	printf("dari : ");scanf("%d",&jawaban);
	printf("ke : ");scanf("%d",&jawaban2);
	printf("masukan angka yang akan di konversikan : ");scanf("%f",&angka);
	
	if(jawaban==1 && jawaban2==2){
		//c ke f
		f = celciToFar(angka);
		printf("-----hasil dari konverter : %f f -----",f);
	}
	else if(jawaban==1 && jawaban2==3){
		//c ke k
		k = celciToKel(angka);
		printf("-----hasil dari konverter : %f k -----",k);
	}
	else if(jawaban==1 && jawaban2==4){
		//c ke r
		r = celciToRea(angka);
		printf("-----hasil dari konverter : %f r -----",r);
	}
	else if(jawaban==2 && jawaban2==1){
		//f ke c
		c = farToCelci(angka);
		printf("-----hasil dari konverter : %f c -----",c);
	}
	else if(jawaban==2 && jawaban2==3){
		//f ke k
		k = farToKel(angka);
		printf("-----hasil dari konverter : %f k -----",k);
	}
	else if(jawaban==2 && jawaban2==4){
		//f ke r
		r = farToRea(angka);
		printf("-----hasil dari konverter : %f r -----",r);
	}
	else if(jawaban==3 && jawaban2==1){
		//k ke c
		c = kelToCelci(angka);
		printf("-----hasil dari konverter : %f c -----",c);
	}
	else if(jawaban==3 && jawaban2==2){
		//k ke f
		f = kelToFar(angka);
		printf("-----hasil dari konverter : %f f -----",f);	
	}
	else if(jawaban==3 && jawaban2==4){
		//k ke r
		r = kelToRea(angka);
		printf("-----hasil dari konverter : %f r -----",r);
	}
	else if(jawaban==4 && jawaban2==1){
		//r ke c
		c = reaToCelci(angka);
		printf("-----hasil dari konverter : %f c -----",c);
	}
	else if(jawaban==4 && jawaban2==2){
		//r ke f
		f = reaToFar(angka);
		printf("-----hasil dari konverter : %f f -----",f);
	}
	else if(jawaban==4 && jawaban2==3){
		//r ke k
		k = reaToKel(angka);
		printf("-----hasil dari konverter : %f k -----",k);	
	}
	else if(jawaban==jawaban2){
		printf("\ntidak ada perubahan\n");
	}
	else{
		printf("masukan kembali suhu yang akan dikonversikan sesuai dengan yang ada\n");
	}
	
	
}