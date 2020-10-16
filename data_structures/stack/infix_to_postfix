#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int priority(char c)
{
    switch(c)
    {
        case '$':
        case '^':return 3;
        case '/':
        case '%':
        case '*': return 2;

        case '+':
        case '-': return 1;
        default: return 0;
    }
}
void main()
{
    char ch;
    char infix[MAX], postfix[MAX], stack[MAX];
    int i, j = 0, top = -1;
    stack[++top] = '#';

    printf("Enter the infix expression\n");
    scanf("%s",infix);
    
    for(i=0; infix[i]!='\0';i++)
    {
        ch = infix[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '$' || ch == '^')
        {
            if(priority(stack[top]) >= priority(ch))
            {
                while(priority(stack[top]) >= priority(ch))
                {
                    postfix[j++] = stack[top--];
                }
                
            }
            stack[++top] = ch;
        }

        else if(ch == '(')
            stack[++top] = ch;
        
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            --top;
        }
        else
            postfix[j++] = ch;
    }
    while(stack[top] != '#')
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("The postfix expression is %s",postfix);
}
