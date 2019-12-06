/* emitter.c */

#include "global.h"
int i=0;
int stack[100];
int valuetable[100];

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
int a;
int b;
void emit (int token_type, int token_value)  /*  generates output  */
{
    switch(token_type) {
    case '+' : case '-' : case '*' : case '/': case '=':case '^':{  
	//push result onto the stack
	a=pop();
	b=pop();
	if(token_type=='+')   {   
	push(a+b);}
	if(token_type=='-')   {   
	push(a-b);}
	if(token_type=='*')   {   
	push(a*b);}
	if(token_type=='/')   {   
	push(b/a);}
	if(token_type=='^')   {   
	push(powe(b,a));}
	if(token_type=='=')   {   
	printf("RESULT:%s=%d\n", symtable[b].lexeme,a);
	valuetable[b]=a;
	i=0;	
	}	
	printf("%c\n", token_type); break;}
    case DIV:{
        printf("DIV\n"); break;} 
    case MOD:{
        printf("MOD\n"); break;}
    case NUM:{      
	//push number onto stack!!!
	push(token_value);
	printf("%d\n", token_value); break;}
    case ID:{ 
	//push variable onto stack?
	if(i!=0)
	{push(valuetable[token_value]);}
	else{push(token_value);}
        printf("%s\n", symtable[token_value].lexeme); break;} 
    default:     
        printf("[Unknown token %d, with value %d]\n", token_type, token_value);
    }


}
