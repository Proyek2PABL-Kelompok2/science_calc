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

treeNode* createNode(double num, char oper, /*mathFunction func, int openParentheses, int closeParentheses,*/ treeNode* left, treeNode* right, treeNode* parent) {
    treeNode* newNode = (treeNode*) malloc(sizeof(treeNode));
    newNode->num = num;
    newNode->oper = oper;
    newNode->func = NO_FUNC;
    newNode->openParentheses = 0;
    newNode->closeParentheses = 0;
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

treeNode* getLastInorderNode(treeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    treeNode* lastNode = NULL;
    treeNode* currentNode = root;

    while (currentNode != NULL) {
        if (currentNode->left == NULL) {
            lastNode = currentNode;
            currentNode = currentNode->right;
        } else {
            treeNode* predecessor = currentNode->left;

            while (predecessor->right != NULL && predecessor->right != currentNode) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                predecessor->right = currentNode;
                currentNode = currentNode->left;
            } else {
                predecessor->right = NULL;
                lastNode = currentNode;
                currentNode = currentNode->right;
            }
        }
    }

    return lastNode;
}

treeNode* getInorderSuccessor(treeNode* node) {
    treeNode* current = node->right;

    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

treeNode* aNodeOrItsChild(treeNode* current)
{
	if (current->right==NULL || current->right->oper=='\0')
		return current;
	else
		return aNodeOrItsChild(current->right);
}
