#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "difa.h"
#include "fathia.h"
#include "jacky.h"
#include "najwan.h"
#include "vico.h"

int main() {
    // create the leaf nodes for 2, 3, 4, 5, and 7
//    treeNode* n2 = createNode(2, '\0', NULL, NULL, NULL);
//    treeNode* n3 = createNode(3, '\0', NULL, NULL, NULL);
//    treeNode* n4 = createNode(4, '\0', NULL, NULL, NULL);
//    treeNode* n5 = createNode(5, '\0', NULL, NULL, NULL);
//    treeNode* n7 = createNode(7, '\0', NULL, NULL, NULL);

    // create the addition nodes
//    treeNode* add1 = createNode(NULL, '+', n3, n4, NULL);
//    treeNode* add2 = createNode(NULL, '+', n2, add1, NULL);
//    treeNode* add3 = createNode(NULL, '*', add2, n5, NULL);
//    treeNode* sub1 = createNode(NULL, '-', add3, n7, NULL);

	treeNode* nodeInsertion = NULL;
	treeNode* root = NULL; 
	treeNode* current = NULL;
	treeNode* leftChildCarrier = NULL;
	treeNode* rightChildCarrier = NULL;
	treeNode* parentCarrier = NULL;
	char keypress, prevKeypress = '#'; double numInput, prevNumInput = NULL;
	do
	{
		system("cls");
		if(root==NULL)
		{
			printf("[EMPTY ENTRY]");
		}
		else
		{
			printInorder(root);	
		}
		printf("\n = %g", evaluate(root));
		keypress = getch();
		if((keypress >= '0' && keypress <= '9') || keypress == '.')
		{
			if(keypress!='.')
			{
				numInput = keypress - '0';
			}
			
			if((prevKeypress >= '0' && prevKeypress <= '9') || keypress == '.')
			{
				if(rightChildCarrier!=NULL)
				{
					rightChildCarrier->num = rightChildCarrier->num * 10 + numInput;
				}
				else if(current!=NULL)
				{
					current->num = current->num * 10 + numInput;
				}
			}
			else
			{
				nodeInsertion = createNode(numInput, '\0', NULL, NULL, NULL);
				if(isRootWorthy(root, nodeInsertion))
				{
					root = nodeInsertion;
					current = root;
				}
				else
				{
					current = root;
					while(current->right!=NULL)
					{
						current = current->right;
					}
					rightChildCarrier = nodeInsertion;
					current->right = rightChildCarrier;
					rightChildCarrier->parent = current;
	//				parentAndChildrenPairing(NULL, rightChildCarrier, current);
				}
			}
		}
		else if(keypress == '+' || keypress == '-' || keypress == '*' || keypress == '/')
		{
			nodeInsertion = createNode(NULL, keypress, NULL, NULL, NULL);
			if(root!=NULL)
			{
				if(root->num!=NULL || (root->oper!='\0' && getPrecedence(root->oper) >= getPrecedence(nodeInsertion->oper)))
				{
					leftChildCarrier = root;
					root = nodeInsertion;
					root->left = leftChildCarrier;
					leftChildCarrier->parent = root;
//					parentAndChildrenPairing(leftChildCarrier, NULL, root);
				}
				else if(root->oper!='\0' && getPrecedence(root->oper) < getPrecedence(nodeInsertion->oper))
				{
					current = root;
					while(current->oper!='\0' && current->right->oper!='\0')
					{
						current = current->right;
					}
					rightChildCarrier = nodeInsertion;
					rightChildCarrier->left = current->right;
					current->right->parent = rightChildCarrier;
					rightChildCarrier->parent = current;
					current->right = rightChildCarrier;
//					
//					parentAndChildrenPairing(current->right, NULL, rightChildCarrier);
//					parentAndChildrenPairing(current->left, rightChildCarrier, current);
				}
			}
//			else
//			{
//				root = nodeInsertion;
//			}
		}
//		prevNumInput = numInput;
		prevKeypress = keypress;
	}
	while(keypress!='\r');

    return 0;
}
