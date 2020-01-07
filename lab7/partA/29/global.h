/* global.h */

#include <stdio.h>  /* include declarations for i/o routines */
#include <ctype.h>  /* ... and for character test routines */
#include <stdlib.h> /* ... and for some standard routines, such as exit */
#include <string.h> /* ... and for string routines */
typedef struct node 
{
	int value;
	int type;
	struct node* args[3];

//print tree extra -----------------------------------------------------------------------------------------------------
	int spacing;
	int depth;
//print tree extra -----------------------------------------------------------------------------------------------------
}TreeNode;
#include "example.tab.hpp"



#define NONE   -1
#define EOS    '\0'

#define MAX_ID_LENGTH  128  /* for the buffer size */

extern int token_value;   /*  value of token attribute */  
extern int lineno;

struct symentry {  /*  form of symbol table entry  */
    char *lexeme; 
    int  token_type;    
};

extern struct symentry symtable[];  /* symbol table  */

extern void init();  /*  loads keywords into symtable  */
extern int lexan();  /*  lexical analyzer  */
extern void parse();  /*  parses and translates expression list  */
extern int insert(char *s, int token_type);    /*  returns position of entry for s */
extern int lookup(char *s);         /* returns position of entry for s, or -1 if not found */
extern void emit (int token_type, int token_value);  /*  generates output  */
