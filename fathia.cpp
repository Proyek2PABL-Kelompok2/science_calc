#include <stdio.h>
#include <stdlib.h>
#include "fathia.h"


//Ini adalah baris deklarasi array 2 dimensi
float A[2][2],B[2][2],varC[2][2], D[3][3],E[3][3],varF[3][3];
int a,b,c;
 
void pilihan(){ //fungsi pilihan menu perhitungan
    printf("\n[1] Penjumlahan"); 
    printf("\n[2] Pengurangan");
    printf("\n[3] Kali");
    printf("\n[4] Bagi");
    printf("\n[0] Keluar");
}

void menu(){ //fungsi pilihan menu ordo
    printf("\n[1] ordo2"); 
    printf("\n[2] ordo3");
    printf("\n[0] Keluar");

}

void ordo2(){
	int i,j; // baris dan kolom
    printf("\n----Matriks A----\n"); // untuk matriks A
 
    for (i=0; i<2; i++){ //krn ordo 2*2 makanya peerulangan sebanyak dua kali
        for (j=0; j<2; j++){
            printf("Input Matrix A[%d][%d] : ",i, j);
            scanf("%f",&A[i][j]);
        }
}
 
    printf("\n----Matriks B----\n"); 
       //perulangan matriks B
 
    for (i=0; i<2; i++){
        for (j=0; j<2; j++){
            printf("Input Matrix B[%d][%d] : ",i, j);
            scanf("%f",&B[i][j]); //menyimpan inputan dari user dari hasil pengulangan ke dalam variabel
        }
    }
}

 


void ordo3(){ //menyimpan inputan dari user
    int i,j,k; // baris dan kolom
    printf("\n----Matriks D----\n"); // untuk matriks A
 
    for (i=0; i<3; i++){ //krn ordo 2*2 makanya peerulangan sebanyak dua kali
        for (j=0; j<3; j++){
            printf("Input Matrix D[%d][%d] : ",i, j);
            scanf("%f",&D[i][j]);
        }
}
 
    printf("\n----Matriks E----\n"); 
       //perulangan matriks B
 
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf("Input Matrix E[%d][%d] : ",i, j);
            scanf("%f",&E[i][j]); //menyimpan inputan dari user dari hasil pengulangan ke dalam variabel
        }
    }
}
 
//menunjukkan jenis operasi dalam matriks misal menunjukkan operasi penjumlahan
void show(char opr){ 
    for (a=0; a<2; a++){ //menampilkan nilai matrik A yang tadi diinputkan
        for (b=0; b<2; b++){
            printf("%2.0f ",A[a][b]);
        }
        
        for(a=0; a<3; a++){ //menampilkan nilai matrik A yang tadi diinputkan
        	for (b=0; b<3; b++){
            	printf("%3.0f ",D[a][b]);
            	}
        	}
		}
 
        if(a==0) printf("\t%c\t",opr);
        else printf("\t \t");
        for (b=0; b<2; b++){
            printf("%2.0f ",B[a][b]); //menampilkan nilai matriks B dari inputan user ke variabel
        }
        for(b=0; b<3; b++){
            printf("%3.0f ",E[a][b]); //menampilkan nilai matriks B dari inputan user ke variabel
        }
 
        printf("\n");
}

 
void penjumlahan(){ //memanggil fungsi penjumlahan
	menu();// menentukan jenis ordo 
    ordo2();//memanggil fungsi input
    ordo3();//memanggil fungsi input
    show('+');//memanggil fungsi show jenis operasi + /jumlah
    printf("Hasil Penjumlahan:\n");
 
    if (a<2){
        for (b=0; b<2; b++){
            printf("%2.0f ",A[a][b]+B[a][b]);
        }
        printf("\n");
    }
    else if (a<3){
    	for (b=0; b<3; b++){
    		printf("%3.0f ",D[a][b]+E[a][b]);
		}
		printf("\n");
	}
}
 
void pengurangan(){//fungsi pengurangan
	menu(); // menentukan jenis ordo
    ordo2(); //memanggil fungsi show jenis operasi (–) minus/kurang
    ordo3(); //memanggil fungsi show jenis operasi (–) minus/kurang 
	show('-');
    printf("Hasil Pengurangan:\n");
 
    for (a=0; a<2; a++){
        for (b=0; b<2; b++){
            printf("%2.0f ",A[a][b]-B[a][b]);
        }
        printf("\n");
    }
    for (a=0; a<3; a++){
    	for (b=0; b<3; b++){
    		printf("%3.0f ",D[a][b]-E[a][b]);
		}
		printf("\n");
	}
}

void kali(){
	menu(); // menentukan jenis ordo
    ordo2(); //memanggil fungsi show jenis operasi (*) kali
    ordo3(); //memanggil fungsi show jenis operasi (*) kali 
	show('*');
    printf("Hasil Kali:\n");
    
    for (a=0; a<2; a++){
        for (b=0; b<2; b++){
            printf("%2.0f ",A[a][b]*B[a][b]);
        }
		printf("\n");
	}
    for (a=0; a<3; a++){
    	for (b=0; b<3; b++){
    			printf("%3.0f ",D[a][b]*E[a][b]);
		}
		printf("\n");
	}
    
}
 
void bagi (){
	menu(); // menentukan jenis ordo
    ordo2(); //memanggil fungsi show jenis operasi (–) minus/kurang
    ordo3(); //memanggil fungsi show jenis operasi (–) minus/kurang 
	show(':');
    printf("Hasil Kali:\n");
    
    for (a=0; a<2; a++){
        for (b=0; b<2; b++){
            printf("%2.0f ",A[a][b]/B[a][b]);
        }
		printf("\n");
	}
	for (a=0; a<3; a++){
    	for (b=0; b<3; b++){
    		printf("%3.0f ",D[a][b]/E[a][b]);
		}
		printf("\n");
	}
} 
 
int main(){ //fungsi utama dari main
    int tordo,selesai=1,pilih; //program akan berlanjut jika variabel selesai bernilai 1
    printf("\n-----------PROGRAM PENGHITUNGAN MATRIKS ------------\n\n");
    while(selesai==1){
        pilihan();
        printf("\nMasukkan pilihan >");
        scanf("%d",&pilih);
        menu();
    	printf("\nMasukkan pilihan >");
    	scanf("%d",&tordo);
 
        switch(pilih){
        case 0 : selesai=0; break; //dan program akan selesai jika bernilai/input angka 0
        case 1 : penjumlahan(); break;
        case 2 : pengurangan(); break;
        case 3 : kali(); break;
        case 4 : bagi(); break;
        default :  printf("Pilihan Salah\n"); break;
        }
        switch(tordo){
        case 0 : selesai=0; break; //dan program akan selesai jika bernilai/input angka 0
        case 1 : ordo2(); break;
        case 2 : ordo3(); break;
        default :  printf("Pilihan Salah\n"); break;
        }
    }
    system("pause");
    return 0;
}
