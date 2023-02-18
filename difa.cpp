#include <math.h>
#include <string.h>
#include <stdio.h>
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

