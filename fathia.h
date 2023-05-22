#ifndef Fathia
#define Fathia
#include "jacky.h"
#define MAX_SIZE 10
//
//	int size;
//    float matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], hasil[MAX_SIZE][MAX_SIZE];
//    int option;
//    float det1,det2,in1,in2;
//    int i, j, k;

// pilihan void //
int faktoril(int a);
int mutlak (int a);
int arit (int a, int b, int c);
int geo (int a, int b, int c); 
void input();
void tampil();
void pilihan();
void fathia();

void printInorder(treeNode* root);
void printTree(treeNode* node, int depth);

#endif
