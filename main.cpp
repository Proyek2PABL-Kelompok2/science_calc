#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "difa.h"
#include "fathia.h"
#include "jacky.h"
#include "najwan.h"
#include "vico.h"

int main(){
	char s[250], prompt;
	int res;
	do{
		system("cls");
		printf("Enter an arithmetic expression or press ENTER KEY for other options:\n");
		for(int iter=0; iter<250; iter++){
			s[iter] = getch();
			if(s[iter]==13){
				if(iter==0){
					otherCalcs(); //redirects user to other calculations menu when enter key is the first key being pressed
				} 
				break; //ends input loop when enter key is pressed
			}
			printf("%c", s[iter]);
		}
		res = hitungQuery(s);
		printf("\nResult: %d", res);
		printf("\nWould you like to try again? (y/n) ");
		scanf("\n%c", &prompt);
		if(prompt=='n'||prompt=='N'){
			printf("Goodbye!");
			break;
		}
	}while(prompt=='y'||prompt=='Y');
	return 0;
}
