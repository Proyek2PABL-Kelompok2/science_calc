#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "najwan.h"
#include "jacky.h"
#define MAX_SIZE 10


// deklarasi
	int size;
    float matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], hasil[MAX_SIZE][MAX_SIZE], A[MAX_SIZE][MAX_SIZE];
    int option;
    int i, j, k;
    float det1, det2, det3, det4, in1, in2;


    
// memasukan angka yang ingin dimasukan   
void input(float matrix[][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Angka untuk baris %d, kolom %d: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

// menampilkan nilai dari operasi matriks
void tampil(float matrix[][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// memilih menu operasi mtriks
void pilihan(){ //fungsi pilihan menu perhitungan
    printf("\n[1] Penjumlahan"); 
    printf("\n[2] Pengurangan");
    printf("\n[3] Kali");;
    printf("\n[0] Keluar");
}

//int main(){
void fathia(){
	int pilih;

    printf("pilih ordo matriks: ");
    scanf("%d", &size);

 	pilihan();
    printf("\nMasukkan pilihan >");
    scanf("%d",&pilih);
    printf("%d",pilih);
    
    printf("Masukan angka matriks pertama:\n");
    input(matrix1, size);
    printf("Matrix 1 :\n");
    tampil(matrix1, size);

    printf("Masukan angka matriks kedua:\n");
    input(matrix2, size);
    printf("Matrikx 2:\n");
    tampil(matrix2, size);



    switch (pilih) {
        case 1:
            for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
		            hasil[i][j] = penjumlahan(matrix1[i][j], matrix2[i][j]); 
		        }
		    }
			printf("\n Hasil:\n");
            tampil(hasil, size);
            break;
            
        case 2:
	        for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
		            hasil[i][j] = pengurangan(matrix1[i][j],matrix2[i][j]);    
		        }
		    }
	        printf("\n Hasil:\n");
	        tampil(hasil, size);
	        break;
	        
	    case 3:
			for (i = 0; i < size; i++) {
		        for (j = 0; j < size; j++) {
				hasil[i][j] = 0;
					for(k=0;k<2;k++){
						 hasil[i][j] = penjumlahan(hasil[i][j], perkalian(matrix1[i][k], matrix2[k][j]));
					}		
				}
		    }
	        printf("\n Hasil:\n");
	        tampil(hasil, size);
	        break;

		default:
	        printf("Salah memasukan angka.\n");
	        break;
	}
	
	
	// membuat deret aritmatika dan geometri
	    int i,awal, beda, n, rasio,hasila, hasilg;
	    printf("Masukan nilai a: ");
	    scanf("%d", &awal);
	    printf("Masukan nilai b: ");
	    scanf("%d", &beda);
	    printf("Masukan nilai n : ");
	    scanf("%d", &n);
	    printf("Masukan nilai r : ");
	    scanf("%d", &rasio);
	    if (beda!=0){
	   	    hasila= awal +(n-1)*beda; 
	    }
	    else if (beda=0){
	    	hasila=awal;
		}
	    printf("Nilai Un Aritmatika= %d\n", hasila); 
	    
	    if (n!=0){
		 	hasilg= awal * pow(rasio,(n-1));
		}
		else if(n==0){
			hasilg= awal * pow(rasio,(0-1));
		}
		printf("Nilai Un Geometri= %d\n", hasilg); 
	

	
//    return 0;
}

void printInorder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    if (root->oper != '\0') {
        printf("%c", root->oper);
    } else {
        printf("%g", root->num);
    }
    printInorder(root->right);
}

void printTree(treeNode* node, int depth) {
    if (node == NULL) {
        return;
    }

    // Print the right subtree with increased depth
    printTree(node->right, depth + 1);

    // Print this node
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    if (node->oper == '\0') {
        printf("%.1f\n", node->num);
    } else {
        printf("%c\n", node->oper);
    }

    // Print the left subtree with increased depth
    printTree(node->left, depth + 1);
}