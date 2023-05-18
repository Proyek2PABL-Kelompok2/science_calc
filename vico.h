#ifndef vico_h
#define vico_h

void vico();

char funcNameLetters[] = "sincostanarcsinarccosarctansinhcoshtanhexplog10lnsqrt";
bool isRootWorthy(treeNode* root, treeNode* any);
bool isMathNotation(char keypress, int iteration);
bool isNumberChar(char input);
bool isFunctionNameLetter(char input, int iteration);

double power(double nilai, int pangkat);
double akar(double nilai_akar, int basis);
double ln(double nilai_ln);
double logaritma(double nilai_logaritma, double basis_logaritma);
#endif
