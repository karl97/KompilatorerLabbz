/* example.y */

%{
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
extern int yyerror(char const *msg);


TreeNode* mkleaf(int type, int value);

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2);

void printTree(TreeNode* tree);
int runTree(TreeNode* tree);
extern int yylex();
int valuetable[1000];

int powe(int a1, int b1);

%}


%union {
  TreeNode* p;
  int i; 
}

%type <p> expr;
%type <p> assignment;
//%type <p> list;
%type <p> statement;
%type <p> statements;
//%type <p> morestatements;
//%type <p> blockstatement;
%type <p> optionalelse;
%type <i> ID;
%type <i> NUM;

%token DIV MOD DONE ID NUM EXPR WHILE PRINT READ IF ELSE
%left '?' ':'
%left '<' '>'
%left '+' '-'
%left '*' '/'
%left '^'
%left '&' '|' '%'


%%
start: statements DONE { runTree($1);}
        ;

statements: statement statements{$$ = mknode(';', $1, $2, 0);} 
	| {$$ = 0;}
	;

statement: 
	  assignment ';' {$$ = $1;}
	| expr  ';' {$$ = $1;}
	| WHILE '(' expr ')' statement {$$ = mknode(WHILE, $3, $5, 0);}
	| IF '(' expr ')' statement optionalelse {$$ = mknode(IF, $3, $5, $6);}
	| '{' statements '}' {$$ = $2;}
	;


assignment: ID '=' expr{$$ = mknode((int)'=', mkleaf(ID, $1), $3, 0); }
	;
optionalelse: ELSE statement {$$ = mknode(ELSE, $2, 0, 0);}
	| {$$ = 0;}
	;
expr :    expr '+' expr { $$ = mknode((int)'+', $1, $3, 0); }
	| expr '-' expr { $$ = mknode((int)'-', $1, $3, 0); }
	| expr '*' expr { $$ = mknode((int)'*', $1, $3, 0); }
	| expr '/' expr { $$ = mknode((int)'/', $1, $3, 0); }
	| expr '<' expr { $$ = mknode((int)'<', $1, $3, 0); }
	| expr '>' expr { $$ = mknode((int)'>', $1, $3, 0); }
	| expr '&' expr { $$ = mknode((int)'&', $1, $3, 0); }
	| expr '|' expr { $$ = mknode((int)'|', $1, $3, 0); }
	| expr '^' expr { $$ = mknode((int)'^', $1, $3, 0); }
	| expr '%' expr { $$ = mknode((int)'%', $1, $3, 0); }
	| expr '?' expr ':' expr { $$ = mknode((int)'?', $1, $3, $5); }
	| PRINT '(' ID ')' { $$ = mknode(PRINT, mkleaf(ID, $3), 0, 0); }
	| READ '(' ID ')' { $$ = mknode(READ, mkleaf(ID, $3), 0, 0); }
	| '(' expr ')' { $$ = mknode((int)'(', $2, mkleaf((int)')', ')'), 0); }
	| NUM { $$ = mkleaf(NUM, $1);}
	| ID  { $$ = mkleaf(ID, $1);}
	;




%%

int yyerror(char const *msg) {
	printf("Error: %s\n", msg);
	return 0;
}

void parse()
{
	yyparse();
}

int powe(int a1, int b1){
	int c=a1;
	for(int i=1;i<b1;i++){
		c=c*a1;
	}
	return c;
}

TreeNode* mkleaf(int type, int value) {
  	
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
  	p->type = type;
  	p->value = value;
//print tree extra -----------------------------------------------------------------------------------------------------
	p->spacing = 2;
	if(type == ID)
		p->spacing += strlen(symtable[p->value].lexeme);
	if(type == NUM)
	{
		char buffer [12];
		sprintf (buffer, "%d", p->value);
		p->spacing += strlen(buffer) - 1;
	}
//print tree extra -----------------------------------------------------------------------------------------------------
  	return p;
}

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
  	p->type = type;
  	p->args[0] = a0;
  	p->args[1] = a1;
  	p->args[2] = a2;
//print tree extra -----------------------------------------------------------------------------------------------------
	int numNodes = 0;
	
	for(int i = 0; i < 3; i++)
	{
		if(p->args[i] != 0)
		{
			numNodes++;
			if(p->spacing < p->args[i]->spacing)
			{
				p->spacing = p->args[i]->spacing;
			}
			if(p->depth < p->args[i]->depth)
			{
				p->depth = p->args[i]->depth;
			}
		}
	}
	p->depth = p->depth + 1;
	if(type == READ || type == ELSE)p->spacing += 4;
	else if(type == PRINT || type == WHILE){p->spacing += 6;}
	else if(type == IF){p->spacing += 2;}
	p->spacing = p->spacing *(numNodes + (numNodes - 1));
//print tree extra ---------------------------------------------------------------------------------------------------
  	return p;
}


//Print tree here -----------------------------------------------------------------------------------------------------
void printTreeReccursive(TreeNode* tree, int h, int globalSpacing, char* row)
{
	
	int index = globalSpacing;
	if(h <= 0)
	{
		if(tree == 0) return;
		switch(tree->type)
		{
		case NUM:
		{
			
			char buffer [12];
			sprintf (buffer, "%d", tree->value);
			for(int k = 0; k < 12; k++){
				if(buffer[k] == '\0')break;
				row[index + k] = buffer[k];
			}			
		}break;
		case ID:
		{
			char* temp = symtable[tree->value].lexeme;
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case PRINT:
		{
			char* temp = "print";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case WHILE:
		{
			char* temp = "while";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case READ:
		{
			char* temp = "read";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case IF:
		{
			char* temp = "if";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case ELSE:
		{
			char* temp = "else";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		default:
		{
			row[index] = (char)tree->type; 
		}break;
		}		

		 	
	}else {
		if(tree != 0){
			int numNodes = 0;
			for(int i = 0; i < 3; i++)
			{
				if(tree->args[i] != 0)
				{
					numNodes++;
				}
			}
			if(numNodes == 3) {
				for(int i = 0; i < 3; i++)
				{
					printTreeReccursive(tree->args[i],  h - 1, globalSpacing + tree->spacing/4* (i - 1), row);
					
				}
			}else if(numNodes == 2)
			{	
				printTreeReccursive(tree->args[0],  h - 1, globalSpacing + tree->spacing/4* ( -1), row);
				printTreeReccursive(tree->args[1],  h - 1, globalSpacing + tree->spacing/4* ( +1), row);
			}else if(numNodes == 1)
			{					
				printTreeReccursive(tree->args[0],  h - 1, globalSpacing, row);
			}
		}
		
	}	
}


void printTree(TreeNode* tree)
{
	int globalSpacing = tree->spacing;
	char* row = (char*) malloc(sizeof(char)*globalSpacing + 1);
	row[globalSpacing] = '\0';
	for(int i = 0; i <= tree->depth; i++){
		for(int j = 0; j < globalSpacing; j++)
		{
			row[j] = ' ';
		}
		printTreeReccursive(tree, i, globalSpacing/2, row);	
		printf("%s\n", row);
	}
	free(row);
}
//Print tree here -----------------------------------------------------------------------------------------------------



#define DEBUG_PRINTS 0


#if !DEBUG_PRINTS
#define DEBUG_CALL(x)
#else 
#define DEBUG_CALL(x) x
#endif


int runTree(TreeNode* tree)
{
	if(tree == NULL) return 0;
	switch(tree->type)
		{
		case NUM:
		{
			DEBUG_CALL(printf("NUM\n"));
			return tree->value;
						
		}break;
		case ID:
		{
			DEBUG_CALL(printf("ID\n"));
			return tree->value;
		}break;
		case PRINT:
		{
			DEBUG_CALL(printf("PRINT\n"));
			int idPosition = runTree(tree->args[0]);
			int idVal=valuetable[idPosition];			
			printf("%s = %d\n", symtable[idPosition].lexeme, idVal);
			return idVal;
		}break;
		case WHILE:
		{
			DEBUG_CALL(printf("WHILE\n"));
			while(runTree(tree->args[0]) != 0)
			{
				runTree(tree->args[1]);
			}
		}break;
		case READ:
		{
			DEBUG_CALL(printf("READ\n"));
			int idVal=0;
			int idPosition = runTree(tree->args[0]);
			printf("Input value for %s\n", symtable[idPosition].lexeme);			
			scanf("%d",&idVal);			
			valuetable[idPosition]=idVal;
			return idVal;
		}break;
		case (int)'?':
		case IF:
		{
			DEBUG_CALL(printf("IF\n"));
			if(runTree(tree->args[0]) != 0)
			{
				runTree(tree->args[1]);
			}else{
				runTree(tree->args[2]);
			}
		}break;
		case ELSE:
		{
			DEBUG_CALL(printf("ELSE\n"));
			runTree(tree->args[0]);
		}break;
		case (int)'+':
		{
			DEBUG_CALL(printf("+\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue + rightValue;
		}break;
		case (int)'-':
		{
			DEBUG_CALL(printf("-\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue - rightValue;
		}break;
		case (int)'/':
		{
			DEBUG_CALL(printf("/\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue / rightValue;
		}break;
		case (int)'*':
		{
			DEBUG_CALL(printf("*\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue * rightValue;
		}break;
		case (int)'<':
		{
			DEBUG_CALL(printf("<\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue < rightValue;
		}break;
		case (int)'>':
		{
			DEBUG_CALL(printf(">\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue > rightValue;
		}break;
		case (int)'&':
		{
			DEBUG_CALL(printf("&\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue & rightValue;
		}break;
		case (int)'|':
		{
			DEBUG_CALL(printf("|\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue | rightValue;
		}break;
		case (int)'^':
		{
			DEBUG_CALL(printf("^\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return powe(leftValue, rightValue);
		}break;
		case (int)'%':
		{
			DEBUG_CALL(printf("%%\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			return leftValue % rightValue;
		}break;
		case (int)';':
		{
			DEBUG_CALL(printf(";\n"));
			runTree(tree->args[0]);
			runTree(tree->args[1]);

		}break;
		case (int)'=':
		{
			DEBUG_CALL(printf("=\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			int idVal = valuetable[leftValue] = rightValue;

			return idVal;
		}break;
		default:
		{
			
			int arg0 = runTree(tree->args[0]);
			int arg1 = runTree(tree->args[1]);
			int arg2 = runTree(tree->args[2]);
			DEBUG_CALL(printf("DEFAULT: %c, %d, %d, %d\n", tree->type, arg0, arg1, arg2));

			return arg0;
		}break;
	}		
	return 0;

}


