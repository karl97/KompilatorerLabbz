/* example.y */

%{
#include <stdio.h>
#include "global.h"
extern int yyerror(char const *msg);

int i=0;
int stack[100];
int valuetable[1000];
int a;
int b;
int c;
void push(int value);

int pop();

int powe(int a1, int b1);

%}

%token DIV MOD DONE ID NUM


%%
start: list DONE
        ;

list: assignment ';' list | expression ';' list
        | /* empty */
        ;

assignment: ID {push($1);printf("%s\n", symtable[$1].lexeme);} '=' expr {printf("=\n"); a=pop();b=pop();push(b);printf("%s=%d\n",symtable[b].lexeme,a);valuetable[b]=a;}
	| 
	;

expression: expr {printf("Result:%d\n", pop());}
	;

expr: term moreterms
	;

moreterms: '+' term {a=pop();b=pop();push(b+a);printf("+\n");} moreterms
	| '-' term {a=pop();b=pop();push(b-a);printf("-\n");} moreterms
	|
	;

term: factor morefactors
	;

morefactors: '*' factor {a=pop();b=pop();push(b*a);printf("*\n");} morefactors
	| '/' factor {a=pop();b=pop();push(b/a);printf("/\n");} morefactors
	| DIV factor {a=pop();b=pop();push(b/a);printf("DIV\n");} morefactors
	| MOD factor {a=pop();b=pop();push(b%a);printf("MOD\n");} morefactors
	| '%' factor {a=pop();b=pop();push(b%a);printf("%c\n",'%');} morefactors
	| '&' factor {a=pop();b=pop();push(b&a);printf("&\n");} morefactors	
	| '|' factor {a=pop();b=pop();push(b|a);printf("|\n");} morefactors	
	| '<' factor {a=pop();b=pop();push(b<a);printf("<\n");} morefactors
	| '>' factor {a=pop();b=pop();push(b>a);printf(">\n");} morefactors
	| '?' factor ':' factor {a=pop();b=pop();c=pop(); printf("?\n"); if(c!=0){push(b);}else{push(a);}} morefactors
	|
	;

factor: expfactor moreexpfactors
	;

moreexpfactors: '^' expfactor {a=pop();b=pop();push(powe(b, a));printf("^\n");} moreexpfactors
	|
	;

expfactor: '(' expr ')'
	| ID {push(valuetable[$1]);printf("%s\n", symtable[$1].lexeme);}
	| NUM {push($1);printf("%d\n", $1);}
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

int yylex()
{
	int token_type=lexan();
	yylval=token_value;
	return token_type;
}


void push(int value){
stack[i]=value;
i++;
}
int pop(){
i--;
return stack[i];
}
int powe(int a1, int b1){
int c=a1;
for(int i=1;i<b1;i++){
c=c*a1;}
return c;
}

