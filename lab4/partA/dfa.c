#include <stdio.h>

int main()
{
	/*
	int i=0;
	LOOP:
	i++;
	printf("hej\n");
	if(i<5)	
	goto LOOP;
	*/
	char c;
	char str[10];
STATE_1:
	printf("state 1\n");
	scanf("%s", str);
	c=str[0];	
	if(c=='a'){
		
		printf("1: Moving to state 2\n");
		goto STATE_2;
	}else{
		
		printf("1: Moving to state 4\n");
		goto STATE_4;
	}
STATE_2:
	printf("state 2\n");
	scanf("%s", str);
	c=str[0];
	if(c=='a'){
		printf("2: Moving to state 3\n");
		goto STATE_3;
	}else if(c=='b'){

		printf("2: Moving to state 1\n");	
		goto STATE_1;
	}else{
		
		printf("2: Moving to state 4\n");
		goto STATE_4;
	}
STATE_3:
	printf("state 3\n");
	return 0;
STATE_4:
	printf("state 4\n");	
	return 0;
}
