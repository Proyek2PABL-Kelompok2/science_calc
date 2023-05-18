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
				}
			}
		prevKeypress = keypress;
	}
	while(keypress!='\r');

    return 0;
}
