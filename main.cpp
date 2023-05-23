#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "difa.h"
#include "fathia.h"
#include "jacky.h"
#include "najwan.h"
#include "vico.h"

#define isRootWorthy(x, y) (x!=NULL && y->oper!=NULL) || (x==NULL && y->oper=='\0')

#define hasHigherPrecedenceThan(x,y) getPrecedence(x) > getPrecedence(y)
#define hasSamePrecedenceAs(x,y) getPrecedence(x) == getPrecedence(y)
#define hasLowerPrecedenceThan(x,y) getPrecedence(x) < getPrecedence(y)

int main() {
	treeNode* nodeInsertion = NULL;
	treeNode* root = NULL; 
	treeNode* pseudoRoot = NULL;
	treeNode* current = NULL;
	treeNode* leftChildCarrier = NULL;
	treeNode* rightChildCarrier = NULL;
	treeNode* parentCarrier = NULL;
	treeNode* toBeDeleted = NULL;
//	char *funcNameLetters = "sincostanarcsinarccosarctansinhcoshtanhexplog10lnsqrt";;
//
//	char mathNotations[7] = {
//		'+',
//		'-',
//		'*',
//		'/',
//		'^',
//		'v',
//		'!',
//	};
	char keypress, prevKeypress = '#'; double numInput, prevNumInput = NULL;
	char* functionNameLetters = "sincostanarcsinarccosarctansinhcoshtanhexplog10lnsqrt";
	char *possiblyFuncName = (char*)malloc(3*sizeof(char));
	bool hasComma = false; // hasOpenParenthesis = false, hasCloseParenthesis = false;
	int tenth = 0, negativeNotation = 1, openParentheses = 0, closeParentheses = 0, totalOpenParen = 0, totalCloseParen = 0, j=0;
	enum mathFunction func = NO_FUNC;
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
//			printf("%c")
			printf("%c", (prevKeypress=='.')?prevKeypress:'\0');
			printf("%c", (negativeNotation<0 && !(prevKeypress >= '0' && prevKeypress <= '9') && prevKeypress!='.')?'-':'\0');
//			printf("%c", (isFunctionNameLetter(keypress, sizeof(functionNameLetters)/sizeof(functionNameLetters[0]))?keypress:'\0'));
			printf("\n\n\n");
			printTree(root, 0);
		}
		printf("\n = %.1000g", evaluate(root));
//		printf("\n%s", conditions[i]);
		
		keypress = getch();
		if(isNumberChar(keypress))
		{
			numInput = keypress - '0';
			if(isNumberChar(prevKeypress) || prevKeypress == '.') // || getLastInorderNode(root)->oper == '\0')
			{
				if(rightChildCarrier!=NULL)
				{
					rightChildCarrier->num = updateNodeNum(rightChildCarrier->num, numInput*negativeNotation, hasComma, &tenth);
				}
				else if(current!=NULL)
				{
					current->num = updateNodeNum(current->num, numInput*negativeNotation, hasComma, &tenth);
				}
				else if(root!=NULL)
				{
					root->num = updateNodeNum(root->num, numInput*negativeNotation, hasComma, &tenth);
				}
			}
			else
			{
				numInput*=negativeNotation; // !!
				nodeInsertion = createNode(numInput, '\0', func, NULL, NULL, NULL);
				if(openParentheses > 0)
				{
					nodeInsertion->openParentheses = openParentheses;
//					totalOpenParen+=nodeInsertion->openParentheses;
//					hasOpenParenthesis = false;
					openParentheses = 0;
				}
				if(isRootWorthy(root, nodeInsertion))
				{
					root = nodeInsertion;
//					current = root;
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
		else if(keypress == '.' && hasComma == false)
		{
			hasComma = true;
		}
		else if(isMathNotation(keypress, 5))
		{
			hasComma = false;
			tenth = 0;
			if(isMathNotation(prevKeypress, 5) || root == NULL) // sebelumnya oper, sekarang oper lagi
			{
				if(keypress == '-') //sebelumnya oper, setelahnya minus
				{
					negativeNotation = -1;
				}
			}
			else{
				negativeNotation = 1;
				nodeInsertion = createNode(NULL, keypress, NO_FUNC, NULL, NULL, NULL);
				if(root!=NULL)
				{
					current = root;
					if(current->oper==NULL || (current->oper!='\0' && (hasHigherPrecedenceThan(aNodeOrItsChild(current)->oper, nodeInsertion->oper) || hasSamePrecedenceAs(aNodeOrItsChild(current)->oper, nodeInsertion->oper))))
					{
						if(hasLowerPrecedenceThan(current->oper, nodeInsertion->oper) && current->oper != NULL)
						{
							leftChildCarrier = current->right;
							current->right = nodeInsertion;
							nodeInsertion->left = leftChildCarrier;
							leftChildCarrier->parent = nodeInsertion;
						}
						else
						{
							leftChildCarrier = current;
							current = nodeInsertion;
							current->left = leftChildCarrier;
							leftChildCarrier->parent = current;
						}
						root = current;
	//					parentAndChildrenPairing(leftChildCarrier, NULL, root);
					}
					else if(current->oper!='\0' && hasLowerPrecedenceThan(aNodeOrItsChild(current)->oper, nodeInsertion->oper))
					{
//						current = root;
						while(current->oper!='\0' && current->right->oper!='\0')
						{
							current = current->right;
						}
						rightChildCarrier = nodeInsertion;
						rightChildCarrier->left = current->right;
						current->right->parent = rightChildCarrier;
						rightChildCarrier->parent = current;
						current->right = rightChildCarrier;
	//					parentAndChildrenPairing(current->right, NULL, rightChildCarrier);
	//					parentAndChildrenPairing(current->left, rightChildCarrier, current);
					}
				}
			}
		}
		else if(keypress == '\b' && root != NULL)
		{
			toBeDeleted = getLastInorderNode(root);
			if((toBeDeleted->num <= -10 || toBeDeleted->num >= 10) && toBeDeleted->num - (int)toBeDeleted->num == 0)
			// is round num and is two digits minimum
			{
				toBeDeleted->num = (int)(toBeDeleted->num / 10); // not working
			}
			else if(toBeDeleted->num - (int)toBeDeleted->num != 0)
			// is not round num
			{
				
			}
			else if(toBeDeleted->num >= -9 && toBeDeleted->num <= 9 && toBeDeleted->num - (int)toBeDeleted->num == 0)
			// is round num and is one digit maximum
			{
				if(toBeDeleted->closeParentheses>0)
				{
					toBeDeleted->closeParentheses-=1;
				}
				else if(toBeDeleted->openParentheses>0 && toBeDeleted->num==NULL)
				{
					toBeDeleted->openParentheses-=1;
				}
				else
				{
					toBeDeleted->num=NULL;
				}
				
				if(toBeDeleted->closeParentheses==0 && toBeDeleted->num==NULL && toBeDeleted->openParentheses==0){
					root = deleteNode(root, toBeDeleted);
				}
			}
//			else if(toBeDeleted->oper!='\0')
//			{
//				
//			}
		}
		else if(isFunctionNameLetter(keypress, sizeof(functionNameLetters)/sizeof(functionNameLetters[0])))
		{
//			printf("%c is in the array.\n", keypress);
			if (j<3)
				possiblyFuncName[j++] = keypress;
				
			if(strcmp(possiblyFuncName, "sin")==0)
			{
				func = SINUS;
			}
			else if(strcmp(possiblyFuncName, "cos")==0)
			{
				func = COSINUS;
			}
			else if(strcmp(possiblyFuncName, "tan")==0)
			{
				func = TANGENT;
			}
		}
		else if(keypress == '(')
		{
			openParentheses+=1;
			totalOpenParen+=1;
			
//			hasOpenParenthesis = true;
		}
		else if(keypress == ')' && totalOpenParen > totalCloseParen)
		{
			getLastInorderNode(root)->closeParentheses+=1;
			totalCloseParen+=1;
//			getLastInorderNode(root)->hasCloseParenthesis = true;
		}
//		prevNumInput = numInput;
		prevKeypress = keypress;
	}
	while(keypress!='\r');
	
//	system("cls");
	
//	printf("\n\n\n");
//	printTree(root, 0);

    return 0;
}
