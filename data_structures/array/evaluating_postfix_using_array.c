// Evaluating postfix expressions using an array. 
// A data structure called stack has been implemented here to do the same


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack_top=-1;
int stack[100];

int pop()
{
    if(stack_top==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    printf("%d is popped.\n",stack[stack_top]);
    stack_top--;
    return stack[stack_top+1];
}

void push(int data)
{
    if(stack_top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack_top++;
    stack[stack_top]=data;
    printf("%d added.\n", stack[stack_top]);
}

void evaluating_postfix()
{
    char expr[100];
    char c;
    int i=0;
    printf("Enter the postfix expression.\n");
    gets(expr);
    c=expr[0];
    printf("Calculating...\n");
    while(c!='\0')
    {
        if(c>='0' && c<='9')
        {
            int i= c-'0';
            push(i);
        }
        else if(c=='+')
        {
            int a=pop();
            int b=pop();
            push(a+b);
        }
        else if(c=='-')
        {
            int a=pop();
            int b=pop();
            push(b-a);
        }
        else if(c=='*')
        {
            int a=pop();
            int b=pop();
            push(a*b);
        }
        else if(c=='/')
        {
            int a=pop();
            int b=pop();
            push(b/a);
        }
        i++;
        c=expr[i];
    }
}

int main()
{
    evaluating_postfix();
    printf("Answer is %d",stack[stack_top]);
    stack_top--;
    return 0;
}
