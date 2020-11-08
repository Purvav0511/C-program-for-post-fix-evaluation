#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct
{
	char a[MAX];
	int top;
}STACK;
int pop(STACK *,char *);
int push(STACK *,char);
int is_empty(STACK);
int is_operand(char);
int is_L_H(char,char);
int op(char);
void main()
{
	int k=0,i=0;
	char output[100];
	char s[]="a+b";
	STACK s1;
	s1.top=-1;
	char v;
	int n=strlen(s);
	while(i<n)
	{
		if(is_operand(s[i])==1)
			output[k++]=s[i];	
		else
		if(s[i]=='(')
			push(&s1,s[i]);
		else
		if(s[i]==')')
		{
			while(1)
			{
				pop(&s1,&v);
				if(v=='(')
					break;
				output[k++]=v;
			}
		}
		else
		{
			if(is_empty(s1)==1)
				push(&s1,s[i]);
			else
			{
				pop(&s1,&v);
				if(v=='(')
				{
					push(&s1,v);
					push(&s1,s[i]);
				}
				else
				if(is_L_H(v,s[i]))
				{
					push(&s1,v);
					push(&s1,s[i]);
				}
				else
				{
					output[k++]=v;
					i--;
				}
			}
		}
		i++;
	}
	while(!is_empty(s1))
	{
		pop(&s1,&v);
		output[k++]=v;
	}
	printf("%s",output);
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
int is_L_H(char c1,char c2)
{
	if(op(c1)<op(c2))
		return 1;
	else
		return 0;
}
int op(char c)
{	int k;
	switch(c)
	{
		case '+' :
		case '-' :k=1;
			break;
		case '*' :
		case '/' :k=2;
			break;
	}
	return k;
}	
int pop(STACK *s,char *v)
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
int push(STACK *s,char v)
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

	
