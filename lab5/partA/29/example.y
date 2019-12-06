/* example.y */

%{
#include <stdio.h>
#include "global.h"
extern int yyerror(char const *msg);


TreeNode* mkleaf(int type, int value);

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2);

void printTree(TreeNode* tree);

int valuetable[1000];

int powe(int a1, int b1);

%}


%union {
  TreeNode* p;
  int i; 
}

%type <p> expr;
%type <p> assignment;
%type <i> ID;
%type <i> NUM;

%token DIV MOD DONE ID NUM EXPR
%left '?'
%left '+' '-'
%left '*' '/'
%left '^'
%left '<' '>' '&' '|'

%%
start: list DONE
        ;

list: assignment {printTree($1);} ';' list | expr {printTree($1);}/*{printf("Result = %d\n", $1);}*/ ';' list 
        |  
        ;

assignment: ID '=' expr{$$ = mknode((int)'=', mkleaf(ID, $1), $3, 0); }//printf("%s = %d\n",symtable[$1].lexeme,$3);valuetable[$1]=$3; }
	;

//expression: expr 
//	;

expr :   expr '+' expr { $$ = mknode((int)'+', $1, $3, 0); }//$$ = $1 + $3; }
	| expr '-' expr { $$ = mknode((int)'-', $1, $3, 0); }//$$ = $1 - $3; }
	| expr '*' expr { $$ = mknode((int)'*', $1, $3, 0); }//$$ = $1 * $3; }
	| expr '/' expr { $$ = mknode((int)'/', $1, $3, 0); }//$$ = $1 / $3; }
	| expr '<' expr { $$ = mknode((int)'<', $1, $3, 0); }//$$ = $1 < $3; }
	| expr '>' expr { $$ = mknode((int)'>', $1, $3, 0); }//$$ = $1 > $3; }
	| expr '&' expr { $$ = mknode((int)'&', $1, $3, 0); }//$$ = $1 & $3; }
	| expr '|' expr { $$ = mknode((int)'|', $1, $3, 0); }//$$ = $1 | $3; }
	| expr '^' expr { $$ = mknode((int)'^', $1, $3, 0); }//$$ = powe($1, $3); }
	| expr '?' expr ':' expr { $$ = mknode((int)'?', $1, $3, $5); }//if($1 != 0){ $$ = $3; } else {$$ = $5;}}
	| '(' expr ')' { $$ = mknode((int)'(', $2, mknode((int)')', 0, 0, 0), 0); }
	| NUM { $$ = mkleaf(NUM, $1);}
	| ID  {$$ = mkleaf(ID, $1);}
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
  	return p;
}

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
  	p->type = type;
  	p->args[0] = a0;
  	p->args[1] = a1;
  	p->args[2] = a2;
  	return p;
}

/*
void printTreeReccursive(TreeNode* tree, int h)
{
	//if(h > 2)printf("\t");	
	for(int i = 0; i < h-2; i++)
	{
		printf("|\t");
	}
	if(h > 1)printf("|------ ");
	switch(tree->type)
	{
	case NUM:
	{
		printf("%d\n", tree->value);
	}break;
	case ID:
	{
		printf("%s\n", symtable[tree->value].lexeme);
	}break;
	default:
	{
		printf("%c\n", tree->type);
		for(int i = 0; i < 3; i++)
		{
			if(tree->args[i] != 0)
			{
				printTreeReccursive(tree->args[i], h+1);
			}					
		}
	}break;
	}
	if(h > 1)
	{
		for(int i = 0; i < h-2; i++)
		{
			printf("|\t");
		}
		printf("|\n");
	}		
}
*/

void printTreeReccursive(TreeNode* tree, int h)
{
	for(int i = 0; i < h-1; i++)
	{
		printf("\t");
	}
	switch(tree->type)
	{
	case NUM:
	{
		printf("%d\n", tree->value);
	}break;
	case ID:
	{
		printf("%s\n", symtable[tree->value].lexeme);
	}break;
	default:
	{
		printf("%c\n", tree->type);
		for(int i = 0; i < 3; i++)
		{
			if(tree->args[i] != 0)
			{
				printTreeReccursive(tree->args[i], h+1);
			}					
		}
	}break;
	}		
}

void printTree(TreeNode* tree)
{
	printf("Syntax tree:\n");
	printTreeReccursive(tree, 1);
	printf(";\n");
}


