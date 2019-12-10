/* example.y */

%{
#include <stdio.h>
#include <stdlib.h>
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
	| '(' expr ')' { $$ = mknode((int)'(', $2, mkleaf((int)')', ')'), 0); }
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
	p->spacing = 2;
	if(type == ID)
		p->spacing += strlen(symtable[p->value].lexeme);
	if(type == NUM)
	{
		char buffer [12];
		sprintf (buffer, "%d", p->value);
		p->spacing += strlen(buffer) - 1;
	}
  	return p;
}

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
  	p->type = type;
  	p->args[0] = a0;
  	p->args[1] = a1;
  	p->args[2] = a2;
	int numNodes = 0;
	int maxDepth = 0;
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
	p->spacing = p->spacing * (numNodes + (numNodes - 1));
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
/*
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
*/

/*
void printTreeReccursive(TreeNode* tree, int h, int globalSpacing)
{

	
	if(h == 0){
		int spacing = globalSpacing / 2;
		for(int i = 0; i < spacing; i++)
		{
			printf(" ");
		}
		if(tree == 0)
		{ 
			
			printf(" ");
		}else
		{


			switch(tree->type)
			{
			case NUM:
			{
				printf("%d", tree->value);
			}break;
			case ID:
			{
				printf("%s", symtable[tree->value].lexeme);
			}break;
			default:
			{
				printf("%c", tree->type);

			}break;
			}
		}
		for(int i = 0; i < spacing; i++)
		{
			printf(" ");
		}
	}
	else {
		if(tree != 0)
		{
			for(int i = 0; i < 3; i++)
			{
				
				printTreeReccursive(tree->args[i],  h - 1, globalSpacing/2);
			}
		}
	}

		
}*/


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
			//printf ("[%s] is a string %d chars long\n",buffer,n);
			//itoa(tree->value, &row[index], 1);
			//row[index] = (char)tree->value; //printf("%d", tree->value);
		}break;
		case ID:
		{
			char* temp = symtable[tree->value].lexeme;
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; //printf("%s", symtable[tree->value].lexeme);
		}break;
		default:
		{
			row[index] = (char)tree->type; //printf("%c", tree->type);

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
	/*	if(h == 0){
		int spacing = globalSpacing / 2;
		for(int i = 0; i < spacing; i++)
		{
			printf(" ");
		}
		if(tree == 0)
		{ 
			
			printf(" ");
		}else
		{


			switch(tree->type)
			{
			case NUM:
			{
				printf("%d", tree->value);
			}break;
			case ID:
			{
				printf("%s", symtable[tree->value].lexeme);
			}break;
			default:
			{
				printf("%c", tree->type);

			}break;
			}
		}
		for(int i = 0; i < spacing; i++)
		{
			printf(" ");
		}
	}
	else {
		if(tree != 0)
		{
			for(int i = 0; i < 3; i++)
			{
				
				printTreeReccursive(tree->args[i],  h - 1, globalSpacing/2);
			}
		}
	}*/	
}


void printTree(TreeNode* tree)
{
	printf("Syntax tree:\n");
	char* row = (char*) malloc(sizeof(char)*tree->spacing + 1);
	row[tree->spacing] = '\0';
	for(int i = 0; i <= tree->depth; i++){
		for(int j = 0; j < tree->spacing; j++)
		{
			row[j] = ' ';
		}
		printTreeReccursive(tree, i, tree->spacing/2, row);	
		printf("%s\n", row);
	}
	free(row);
	printf(";\n");
}


