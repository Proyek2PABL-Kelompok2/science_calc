#include <stdio.h>
#include <stdlib.h>
#include "jacky.h"
#include "vico.h"
#include "fathia.h"
#include "difa.h"
#include "najwan.h"

char mathNotations[] = {
	'+',
	'-',
	'*',
	'/',
	'^',
	'v',
	'!',
	'(',
	')',
	'|'
};

void otherCalcs(){
	int choice;
	char s[250];
	system("cls");
	printf("What do you want to calculate ");
	printf("\n1. Exponentials, Logarithms, Differentials");
	printf("\n2. Matrices, Sequence and Series");
	printf("\n3. Trigonometry");
	printf("\n4. Converter");
	printf("\nChoose: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			system("cls");
			vico(); // kekurangan: masih pakai void function, fungsi-fungsi hitung belum atomized
			break;
		case 2:
			system("cls");
			fathia(); // kekurangan: masih pakai void function, fungsi-fungsi hitung belum atomized
			break;
		case 3:
			system("cls");
			printf("\nTrigonometri");
			printf("\nMasukkan input: ");
			scanf("%s", s);
			printf("Hasil: %f", hitungTrigono(s));
			break;
		case 4:
			untuk_pemilihan_konverter();
			break;
		default:
			break;
	}
}

//enum operatorPrecedence {
//	ADDITION,
//	MULTIPLICATION,
//	EXPONENT
//};

treeNode* createNode(double num, char oper, mathFunction func, treeNode* left, treeNode* right, treeNode* parent) {
    treeNode* newNode = (treeNode*) malloc(sizeof(treeNode));
    newNode->num = num;
    newNode->oper = oper;
    newNode->func = func;
    newNode->left = left;
    newNode->right = right;
    newNode->parent = parent;
    return newNode;
}

double updateNodeNum(double numInNode, double newNum, bool hasComma, int* tenth)
{
	if(hasComma == true)
	{
		*tenth = *tenth + 1;
		return numInNode + newNum / pow(10, (double)*tenth);
	}
	else
	{
		return numInNode * 10 + newNum;
	}
}
