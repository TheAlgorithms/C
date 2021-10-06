//infix to postfix
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>

char stack[10];
int top=-1;
void push(char opd)
{
	if(top == 9)
	{
		printf("Stack overflow...");
		exit(0);
	}
	top++;
	stack[top]=opd;
}
char pop()
{
	char item;
	if(top == -1)
	{
		printf("Stack overflow...");
		exit(0);
	}
	item=stack[top];
	top--;
	return item;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}

char Top()
{
	return stack[top];
}

int priority(char opd)
{
	if(opd == '+' || opd == '-')
		return 0;
	else if(opd == '/' || opd == '*' || opd == '%')
		return 1;
	else
		return -1;
}

void main()
{
	char inf[25], post[25];
	printf("Enter Infix: ");
	scanf("%s", inf);
	int i, j=0;
	for(i=0; i < strlen(inf); i++)
	{
		if(isalnum(inf[i]))
		{
			post[j] = inf[i];
			j++;
		}
		else if(inf[i] == '(')
			push(inf[i]);
		else if(inf[i] == ')')
		{
			while(Top() != '(')
			{
				post[j] = pop();
				j++;
			}
			pop();
		}
		else
		{
			while( (!isEmpty()) && (priority(inf[i]) <= priority(Top())) )
			{
				post[j] = pop();
				j++;
			}
			push(inf[i]);
		}
	}
	while(!isEmpty())
	{
		post[j] = pop();
		j++;
	}
	post[j] = '\0';
	printf("Postfix: %s", post);
}

