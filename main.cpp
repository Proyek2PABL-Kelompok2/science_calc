#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "difa.h"
#include "fathia.h"
#include "jacky.h"
#include "najwan.h"
#include "vico.h"

int main(){
	char s[250], prompt;
	float res;
	do{
		system("cls");
		printf("Enter an arithmetic expression or press ENTER KEY for other options:\n");
		memset(s,'\0',250);
		for(int iter=0; iter<250; iter++){
			s[iter] = getch();
			if(s[iter]==13){
				if(iter==0){
					otherCalcs(); //redirects user to other calculations menu when enter key is the first key being pressed
				} 
				break; //ends input loop when enter key is pressed
			}
			else if(s[iter]==8){
				memset(s+(iter-1),'\0',2); //sets the element where the backspace key and the last character being deleted are located in the array to null
				iter-=2; //rolls back the iteration to the second-to-last character after deletion of last character
			}
			for(int i=0;s[i]!=NULL;i++){ //prints the entire input as it is being typed
				system("cls"); //resets the display of the input everytime a character is deleted
				printf("%s", s); //prints the entire string
			}
		}
		res = hitungQuery(s);
		printf("\nResult: %g", res);
		printf("\nWould you like to try again? (y/n) ");
		scanf("\n%c", &prompt);
		if(prompt=='n'||prompt=='N'){
			printf("Goodbye!");
			break;
		}
	}while(prompt=='y'||prompt=='Y');
	return 0;
}
