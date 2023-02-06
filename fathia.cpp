#include <stdio.h>
#include <stdlib.h>
 
//Ini adalah baris deklarasi array 2 dimensi
float entryA[2][2],entryB[2][2],varC[2][2]; 
int a,b,c;
 
void pilihan(){ //fungsi pilihan digunakan untuk memilih menu penghitungan program
    printf("\n[1] Penjumlahan"); 
    printf("\n[2] Pengurangan");

    printf("\n[0] Keluar");
}
 
void Input(){ //fungsi input digunakan untuk menyimpan inputan dari user
    int i,j;
    printf("\n----Matriks A----\n");
 
    for (i=0; i<2; i++){ //pengulangan untuk matrik A dengan jumlah perulangan < 2
        for (j=0; j<2; j++){
            printf("Input Matrix A[%d][%d] : ",i, j);
            scanf("%f",&entryA[i][j]);
        }
}
 
    printf("\n----Matriks B----\n"); 
       //perulangan matriks B
 
    for (i=0; i<2; i++){
        for (j=0; j<2; j++){
            printf("Input Matrix B[%d][%d] : ",i, j);
            scanf("%f",&entryB[i][j]); //menyimpan inputan dari user dari hasil pengulangan ke dalam variabel
        }
    }
}
 
//menunjukkan jenis operasi dalam matriks misal menunjukkan operasi penjumlahan
void show(char opr){ 
    for (a=0; a<2; a++){ //menampilkan nilai matrik A yang tadi diinputkan
        for (b=0; b<2; b++){
            printf("%2.0f ",entryA[a][b]);
        }
 
        if(a==0) printf("\t%c\t",opr);
        else printf("\t \t");
        for (b=0; b<2; b++){
            printf("%2.0f ",entryB[a][b]); //menampilkan nilai matriks B dari inputan user ke variabel
        }
 
        printf("\n");
    }
}
 
void penjumlahan(){ //memanggil fungsi penjumlahan
    Input();//memanggil fungsi input
    show('+');//memanggil fungsi show jenis operasi + /jumlah
    printf("Hasil Penjumlahan:\n");
 
    for (a=0; a<2; a++){
        for (b=0; b<2; b++){
            printf("%2.0f ",entryA[a][b]+entryB[a][b]);
        }
        printf("\n");
    }
}
 
void pengurangan(){//fungsi pengurangan
    Input(); //memanggil fungsi show jenis operasi (�) minus/kurang
    show('-');
    printf("Hasil Pengurangan:\n");
 
    for (a=0; a<2; a++){
        for (b=0; b<2; b++){
            printf("%2.0f ",entryA[a][b]-entryB[a][b]);
        }
        printf("\n");
    }
}
 
 
 
void fathia(){ //fungsi utama dari main
    int selesai=1,pilih; //program akan berlanjut jika variabel selesai bernilai 1
    printf("\n-----------PROGRAM PENGHITUNGAN MATRIKS 2 ORDO------------\n\n");
    while(selesai==1){
        pilihan();
        printf("\nMasukkan pilihan >");
        scanf("%d",&pilih);
 
        switch(pilih){
        case 0 : selesai=0; break; //dan program akan selesai jika bernilai/input angka 0
        case 1 : penjumlahan(); break;
        case 2 : pengurangan(); break;
        default :  printf("Pilihan Salah\n"); break;
        }
    }
    system("pause");
}
