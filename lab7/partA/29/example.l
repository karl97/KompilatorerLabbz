/* example.lex */

%{
#include <stdio.h>
typedef struct node 
{
	int value;
	int type;
	struct node* args[3];
}TreeNode;
#include "example.tab.hpp"
extern int insert(char *s, int token_type);    /*  returns position of entry for s */
extern int lookup(char *s);         /* returns position of entry for s, or -1 if not found */
%}

%option noyywrap

%%

[ \n\t]+    { /* ignore whitespace */ }
"DONE"       { yylval.i = DONE; return DONE;}
"while"       { yylval.i = WHILE; return WHILE;}
"read"       { yylval.i = READ; return READ;}
"print"       { yylval.i = PRINT; return PRINT;}
"if"       { yylval.i = IF; return IF;}
"else"       { yylval.i = ELSE; return ELSE;}
"{"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"}"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"+"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"-"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"*"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"/"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
";"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"?"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"^"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
":"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"<"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
">"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"&"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"|"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"="       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"%"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
"("       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
")"       { yylval.i = (int) (yytext[0]); return (int) (yytext[0]);}
[0-9]+    { yylval.i = atoi(yytext); return NUM; }
[A-Za-z]* { int id_number = lookup(yytext);
            if (id_number == -1)
                id_number = insert(yytext, ID);
            yylval.i = id_number; return ID;}
.         { printf("Ignoring invalid character '%s'\n", yytext); }

%%
