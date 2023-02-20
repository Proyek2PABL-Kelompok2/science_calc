#include <stdio.h>
#include <stdlib.h>
//#include "difa.h"
//#include "fathia.h"
//#include "jacky.h"
//#include "najwan.h"
//#include "vico.h"

int calc(int a, int b, char op);

int main(){
	char prompt;
	do{
		system("cls");
		printf("Scientific Calculator");
		printf("\n1. Enter arithmetic expression");
		printf("\n2. Perform other calculations");
		printf("\n3. Perform conversions");
		printf("\nChoose: ");
		switch(scanf("%d")){
			case 1:
				printf("You chose 1");
				break;
			case 2:
				printf("You chose 2");
				break;
			case 3:
				printf("You chose 3");
				break;
			default:
				break;
		}
		printf("\nWould you like to try again? (y/n) ");
		scanf("%c", &prompt);
		if(prompt=='n'||prompt=='N'){
			printf("Goodbye!");
			break;
		}
	}while(prompt=='y'||prompt=='Y');
}

int calc(int a, int b, char op){
    int c;
    switch (op)
    {
    case '+':
        c = a+b;
        break;
    case '-':
        c = a-b;
        break;
    case '*':
        c = a*b;
        break;
    case '/':
        c = a/b;
        break;
    default:
        break;
    }
    return c;
}
