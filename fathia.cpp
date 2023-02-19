#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define MAX_SIZE 10
#include "fathia.h"
#include "najwan.h"


	int size;
    float matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], hasil[MAX_SIZE][MAX_SIZE];
    int option;
    int i, j, k;
    float det1,det2,in1,in2;


    
    
void input(float matrix[][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Enter the element at row %d, column %d: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void tampil(float matrix[][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}


void pilihan(){ //fungsi pilihan menu perhitungan
    printf("\n[1] Penjumlahan"); 
    printf("\n[2] Pengurangan");
    printf("\n[3] Kali");
    printf("\n[4] Determinan");
    printf("\n[5] Invers");
    printf("\n[0] Keluar");
}

//	
//void tambah(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], float hasil[][MAX_SIZE], int size){
//}
//
//void kurang(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], float hasil[][MAX_SIZE], int size) {
//}
//
//void kali(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], float hasil[][MAX_SIZE], int size) {
//}
//
//void determinan(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], float det1, float det2, int size) {
//}
//void invers(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], float det1, float det2,float in1, float in2, int size) {
//}



int main() {
	int pilih;
    

    printf("pilih ordo matriks: ");
    scanf("%d", &size);

    printf("Masukan angka matriks pertama:\n");
    input(matrix1, size);
    printf("Matrix 1 :\n");
    tampil(matrix1, size);

    printf("Masukan angka matriks kedua:\n");
    input(matrix2, size);
    printf("Matrikx 2:\n");
    tampil(matrix2, size);

    pilihan();
    printf("\nMasukkan pilihan >");
    scanf("%d",&pilih);


    switch (pilih) {
        case 1:
            tambah(matrix1, matrix2, hasil, size);
            for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
		            hasil[i][j] = matrix1[i][j] + matrix2[i][j]; 
		        }
		    }
			printf("\n Hasil:\n");
            tampil(hasil, size);
            break;
            
        case 2:
	        kurang(matrix1, matrix2, hasil, size);
	        for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
		            hasil[i][j] = matrix1[i][j] - matrix2[i][j];    
		        }
		    }
	        printf("\n Hasil:\n");
	        tampil(hasil, size);
	        break;
	        
	    case 3:
	        kali(matrix1, matrix2, hasil, size);
			for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
				hasil[i][j] = 0;
					for(k=0;k<2;k++){
						 hasil[i][j] = hasil[i][j] +(matrix1[i][k] * matrix2[k][j]);
					}
				}
		    }
	        printf("\n Hasil:\n");
	        tampil(hasil, size);
	        break;
	    
		case 4:
	        determinan(matrix1, matrix2, det1, det2, size); 
	    	for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
			        det1= ((matrix1[0][0]*matrix1[1][1])-(matrix1[0][1]*matrix1[1][0]));
				    det2 = ((matrix2[0][0]*matrix2[1][1])-(matrix2[0][1]*matrix2[1][0]));
				}
			}
			printf("\n Hasil: %d, %d\n", det1,det2);
	    	break;

		case 5:
			for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
			        det1= ((matrix1[0][0]*matrix1[1][1])-(matrix1[0][1]*matrix1[1][0]));
				    det2 = ((matrix2[0][0]*matrix2[1][1])-(matrix2[0][1]*matrix2[1][0]));
				}
			}
		    in1 = 1/(det1);
		    in2 = 1/(det2);
		    printf("\n Hasil: %d, %d\n", in1,in2);
	    	break;

		default:
	        printf("Salah memasukan angka.\n");
	        break;
	}
    return 0;
}
