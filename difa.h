#ifndef difa_h
#define difa_h

#define info(P) (P)->opp
#define angka(P) (P)->angka
#define next(P) (P)->next
#define prev(P) (P)->prev
#define Nil NULL
typedef char infotype;			   // variable bentukan bernama infotype dengan tipe char
typedef struct tElmtlist *address; // variable pointer yang akan menunjuk ke alamat yang nilainya bernilai tElmtlist

typedef struct tElmtlist //Var bentukan untuk list
{
	address prev;
	infotype opp;
	float angka;
	address next;
	
} ElmtList;


float sinus(float angka);

float cosinus(float angka);

float tangent(float angka);

float secan(float angka);

float cotangent(float angka);

float cosecan(float angka);

float asinus(float angka);

float acosinus(float angka);

float atangent(float angka);

float hitungTrigono(char *query);

float hitungQuery(char query[]);

float operasi(char opp,int operandNum1,int operandNum2);

//Linked List

void viewAsc(address First);

address searchValue(address Q, address First, char operator1,char operator2);

void insLast(address *P,address *Last, address *First);

address LLcreateListOperator(char opp);

address LLcreateListAngka(char data[]);

float MenentukanRumusHitung(address P);

void HitungOperasi(address P, address First,char operator1, char operator2);

float HitungHasil(address First,address Last);

void LLBuatList(char query[]);


//tree


double evaluate(treeNode* root);
int getPrecedence(char oper);

#endif
