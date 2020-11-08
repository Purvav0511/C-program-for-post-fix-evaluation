#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct
{
	int a[MAX];
	int top;
}STACK;
int pop(STACK *,int *);
int push(STACK *,int);
int is_empty(STACK);
int is_operand(char);
int is_L_H(char,char);
void op(char,int,int,STACK);
void main()
{
	int k=0,i=0,a1,a2,a3;
	char output[100];
	char s[]="53+";
	STACK s1;
	s1.top=-1;
	int v;
	int n=strlen(s);
	while(i<n)
	{
		if(is_operand(s[i])==1)
		{
			a3=s[i]-48;
			push(&s1,a3);
		}
		else
		{
			pop(&s1,&v);
			a2=v;
			pop(&s1,&v);
			a1=v;
			switch(s[i])
			{
				case '+' :k=a1+a2;
					push(&s1,k);
					break;
				case '-' :k=a1-a2;
					push(&s1,k);
					break;
				case '*' :k=a1*a2;
					push(&s1,k);
					break;
				case '/' :k=a1/a2;
					push(&s1,k);
					break;
			}
		}
		i++;
	}
	pop(&s1,&v);
	printf("%d   ",v);
}
int is_empty(STACK s)
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}
int is_operand(char s)
{
	if(s=='+' || s=='-' || s=='/' || s=='*' || s=='(' || s==')' )
		return 0;
	else
		return 1;
}	
int pop(STACK *s,int *v)
{
	if(s->top==(-1))
	{
		printf("Underflow");
		return -1;
	}
	else
	{
		*v=s->a[s->top];
		s->top--;
		return 0;
	}
	
}
int push(STACK *s,int v)
{
	if(s->top==(MAX-1))
	{
		printf("Overflow");
		return(-1);
	}
	else
	{
		s->top++;
		s->a[s->top]=v;
		return 0;
	}
}

