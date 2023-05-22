#ifndef vico_h
#define vico_h
//#include "jacky.h"
//#include "najwan.h"

void vico();

//extern char* funcNameLetters;
//
//char mathNotations[7];

//bool isRootWorthy(treeNode* root, treeNode* any);
bool isMathNotation(char keypress, int iteration);
bool isNumberChar(char input);
bool isFunctionNameLetter(char input, int iteration);

double power(double nilai, int pangkat);
double akar(double nilai_akar, int basis);
double ln(double nilai_ln);
double logaritma(double nilai_logaritma, double basis_logaritma);
#endif
