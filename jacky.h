#ifndef JACK
#define JACK

void otherCalcs(); //menu display for other calculations outside inline calculator

enum mathFunction {
	SINUS,
	COSINUS,
	TANGENT,
	ARC_SINUS,
	ARC_COSINUS,
	ARC_TANGENT,
	HYPERBOLIC_SINUS,
	HYPERBOLIC_COSINUS,
	HYPERBOLIC_TANGENT,
	EXPONENTIAL,
	NATURAL_LOG,
	COMMON_LOG,
	SQUARE_ROOT,
	CUBE_ROOT,
	POWER,
	NO_FUNC
};

typedef struct treeNode {
	double num; // operand
	char oper; // operator
	mathFunction func;
	int openParentheses;
	int closeParentheses;
	treeNode* left; // left son
	treeNode* right; // right son
	treeNode* parent; // parent
} treeNode;

//enum operatorPrecedence {
//	ADDITION,
//	MULTIPLICATION,
//	EXPONENT
//};

treeNode* createNode(double num, char oper, /*mathFunction func,*/ treeNode* left, treeNode* right, treeNode* parent);

double updateNodeNum(double numInNode, double newNum, bool hasComma, int* tenth);

treeNode* getLastInorderNode(treeNode* root);

treeNode* getInorderSuccessor(treeNode* node);

treeNode* aNodeOrItsChild(treeNode* current);

//enum numAppendRule
//{
//	DECIMAL_DIVIDE,
//	DECIMAL_MULTI
//};

#endif // !JACK
