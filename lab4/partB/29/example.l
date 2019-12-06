/* example.lex */

%{
#include <stdio.h>
#include "example.tab.h"
extern int insert(char *s, int token_type);    /*  returns position of entry for s */
extern int lookup(char *s);         /* returns position of entry for s, or -1 if not found */
%}

%option noyywrap

%%

[ \n\t]+    { /* ignore whitespace */ }
"+"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"-"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"*"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"/"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
";"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"?"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"^"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
":"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"<"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
">"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"&"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"|"       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
"="       { yylval = (int) (yytext[0]); return (int) (yytext[0]);}
[0-9]+    { yylval = atoi(yytext); return NUM; }
[A-Za-z]+ { int id_number = lookup(yytext);
            if (id_number == -1)
                id_number = insert(yytext, ID);
            yylval = id_number; return ID;}
.         { printf("Ignoring invalid character '%s'\n", yytext); }

%%
