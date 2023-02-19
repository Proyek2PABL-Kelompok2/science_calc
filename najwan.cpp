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
	detik = angka;
	menit = detik / 60;
	
	return menit;
}

int secToHour(float angka){
	detik = angka;
	jam = detik / 3600;
	
	return jam;
}

int secToDay(float angka){
	detik = angka;
	hari = detik / 86400;
	
	return hari;
}

int secToWeek(float angka){
	detik = angka;
	minggu = detik/604800;
	
	return minggu;
}

int secToMounth(float angka){
	detik = angka;
	bulan = detik/2592000;
	
	return bulan;
}

int secToYear(float angka){
	detik = angka;
	tahun = detik/31104000;
	
	return tahun;
}

//konvert dari menit
int minToSec(float angka){
	menit = angka;
	detik = menit*60;
	
	return detik;
}

int minToHour(float angka){
	menit = angka;
	jam = menit / 60;
	
	return jam;
}

int minToDay(float angka){
	menit = angka;
	hari = menit / 1440;
	
	return hari;
}

int minToWeek(float angka){
	menit = angka;
	minggu = menit/10080;
	
	return minggu;
}

int minToMounth(float angka){
	menit = angka;
	bulan = menit/43200;
	
	return bulan;
}

int minToYear(float angka){
	menit = angka;
	tahun = menit/518400;
	
	return tahun;
}

//konvert dari jam
int hourToSec(float angka){
	jam = angka;
	detik = jam * 3600;
	
	return detik;
}

int hourToMin(float angka){
	jam = angka;
	menit = jam * 60;
	
	return menit;
}

int hourToDay(float angka){
	jam = angka; 
	hari = jam/24;
	
	return hari;
}

int hourToWeek(float angka){
	jam = angka;
	minggu = jam/168;
	
	return minggu;
}

int hourToMounth(float angka){
		jam = angka;
		bulan = jam/672;
	
	return bulan;
}

int hourToYear(float angka){
		jam = angka;
		tahun = jam/8064;
	
	return tahun;
}

//konvert dari hari
int dayToSec(float angka){
	hari = angka;
	detik = hari*86400;
	
	return detik;
}

int dayToMin(float angka){
	hari = angka;
	menit = hari * 1440;
	
	return menit;
}

int dayToHour(float angka){
	hari = angka;
	jam = hari*24;	
	
	return jam;
}

int dayToWeek(float angka){
	hari = angka;
	minggu = hari / 7;
	
	return minggu;
}

int dayToMounth(float angka){
	hari = angka;
	bulan = hari /30;
	
	return bulan;
}

int dayToYear(float angka){
	hari = angka;
	tahun = hari / 365;
	
	return tahun;
}

//konvert dari minggu
int weekToSec(float angka){
	minggu = angka;
	detik = minggu*604800;
	
	return detik;
}

int weekToMin(float angka){
	minggu = angka;
	menit = minggu*10080;
	
	return menit;
}

int weekToHour(float angka){
	minggu = angka;
	jam = minggu*168;	
	
	return jam;
}

int weekToDay(float angka){
	minggu = angka;
	hari = minggu*7;
	
	return hari;
}

int weekToMounth(float angka){
	minggu = angka; 
	bulan = minggu/4;
	
	return bulan;
}

int weekToYear(float angka){
	minggu = angka;
	tahun = minggu/52;
	
	return tahun;
}

//konvert dari bulan
int mounthToSec(float angka){
	bulan = angka;
	detik = bulan*2592000;
	
	return detik;
}

int mounthToMin(float angka){
	bulan = angka;
	menit = bulan*43200;
	
	return menit;
}

int mounthToHour(float angka){
	bulan = angka;
	jam = bulan*720;
	
	return jam;
}

int mounthToDay(float angka){
	bulan = angka;
	hari = bulan*30;
	
	return hari;
}

int mounthToWeek(float angka){
	bulan = angka;
	minggu = bulan*4;
	
	return minggu;
}

int mounthToYear(float angka){
	bulan = angka;
	tahun = bulan / 12;
	
	return tahun;
}

//konvert dari tahun
int yearToSec(float angka){
	tahun = angka;
	detik = tahun*31104000;
	
	return detik;
}

int yearToMin(float angka){
	tahun = angka;
	menit = tahun*518400;
	
	return menit;
}

int yearToHour(float angka){
	tahun = angka;
	jam = tahun*8640;
	
	return jam;
}

int yearToDay(float angka){
	tahun = angka; 
	hari = tahun*365;	
	
	return hari;
}

int yearToWeek(float angka){
	tahun = angka; 
	minggu = tahun*52;
	
	return minggu;
}

int yearToMounth(float angka){
	tahun = angka;
	bulan = tahun*12;
	
	return bulan;
}

float celciToFar(float angka){
	c = angka;
	f = (c*1.8)+32;
	
	return f;	
}

float celciToKel(float angka){
	c = angka;
	k = c + 273.15;
	
	return k;	
}

float celciToRea(float angka){
	c = angka;
	r = (c*4)/5;

	return r;
}

float farToCelci(float angka){
	f = angka;
	c = (f-32)*5/9;
	
	return c;
}

float farToKel(float angka){
	f = angka;
	c = (f-32)*5/9;
	k = c + 273.15;

	return k;	
}

float farToRea(float angka){
	f = angka;
	r = (f-32)*4/9;

	return r;
}

float kelToCelci(float angka){
	k = angka;
	c = k-273.15;

	return c;
}

float kelToFar(float angka){
	k = angka;
	c = k-273.15;
	f = (c*1.8)+32; 

	return f;
}

float kelToRea(float angka){
	k = angka;
	r = (k-273.15)*4/5;
	
	return r;
}

float reaToCelci(float angka){
	r = angka;
	c = r*5/4;

	return c;
}

float reaToFar(float angka){
	r = angka;
	c = r*5/4;
	f = (c*1.8)+32;

	return f;
}

float reaToKel(float angka){
	r = angka;
	k = (r*5/4)+273.15;

	return k;
}

//void utama
void najwan(){	
	float hasil,n;
	
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
	
	switch(){
		
		case 1:
			n = konverter_panjang_dan_massa(pilihan_dari,pilihan_ke,angka);
		case 2:
			n = konverter_luas(c,d,e);
		case 3:
			n = konverter_volume(c,d,e);
		case 4:
			n = konverter_panjang_dan_massa(pilihan_dari,pilihan_ke,angka);
		case 5:
			waktu();
		case 6:
			suhu();
			
	}
}

void waktu(){
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
	if(jawaban==1 && jawaban2==2){
		//c ke f
		f = celciToFar(angka);
	}
	else if(jawaban==1 && jawaban2==3){
		//c ke k
		k = celciToKel(angka);
	}
	else if(jawaban==1 && jawaban2==4){
		//c ke r
		r = celciToRea(angka);
	}
	else if(jawaban==2 && jawaban2==1){
		//f ke c
		c = farToCelci(angka);
	}
	else if(jawaban==2 && jawaban2==3){
		//f ke k
		k = farToKel(angka);
	}
	else if(jawaban==2 && jawaban2==4){
		//f ke r
		r = farToRea(angka);
	}
	else if(jawaban==3 && jawaban2==1){
		//k ke c
		c = kelToCelci(angka);
	}
	else if(jawaban==3 && jawaban2==2){
		//k ke f
		f = kelToFar(angka);	
	}
	else if(jawaban==3 && jawaban2==4){
		//k ke r
		r = kelToRea(angka);
	}
	else if(jawaban==4 && jawaban2==1){
		//r ke c
		c = reaToCelci(angka);
	}
	else if(jawaban==4 && jawaban2==2){
		//r ke f
		f = reaToFar(angka);
	}
	else if(jawaban==4 && jawaban2==3){
		//r ke k
		k = reaToKel(angka);
	}
	else if(jawaban==jawaban2){
		printf("\ntidak ada perubahan\n");
	}
	else{
		printf("masukan kembali suhu yang akan dikonversikan sesuai dengan yang ada\n");
	}
}
