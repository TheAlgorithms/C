#include<stdio.h>
int top=-1;
char stack[20];

void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char x)
{
    int p;
    switch(x)
    {
    case '(':
        p=0;
        break;
    case ')':
        p=0;
        break;
    case '+':
    case '-':
        p=1;
        break;
    case '/':
    case '*':
        p=2;
        break;
    }
    return p;
}
void main()
{
    char *e,exp[20],ch;
    printf("Enter infix expression\n");
    scanf("%s",exp);
    e=exp;
    push('(');
    while(*e!='\0')
    {
        if(isalpha(*e))
        {
            printf("%c",*e);
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while(ch=pop()!='(')
                printf("%c",ch);
        }
        else
        {
            while(priority(stack[top])>priority(*e))
            
                printf("%c",*e);
                push(*e);
            
        }
        e++;
            
        
    }
    
    while(top>0)
    {
        printf("%c",pop());
        
    }
}
