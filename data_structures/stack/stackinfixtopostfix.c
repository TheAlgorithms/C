#include<ctype.h>
#include<stdio.h>
int top=-1,i,k=0;
char infix[30],postfix[30],stack[30];
char symbol, element;
void push(char element)
{
    top++;
    stack[top]=element;
}
char pop()
{
    element=stack[top];
    top--;
    return element;
}
int priority(char symbol)
{
    switch(symbol)
    {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
        case '$':
            return 4;
    }
}
int evaluate() { 
    for (i = 0; infix[i] != '\0';i++)
    {
        symbol = infix[i];
        if(symbol == '(')
        {
            push(symbol);
        }
       else if(isalnum(symbol))
        {
            postfix[k++] = symbol;
        }
        else if(symbol == ')')
        {
            while(stack[top] != '(')
            {
                postfix[k++] = pop();
            }
            pop();
        }
        else
        {
            while(priority(stack[top]) >= priority(symbol))
            {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }
    while(stack[top] != '(')
    {
        postfix[k++] = pop();   
        
        }
        postfix[k] = '\0';
    
     }
int main()
{
    printf("\nenter the infix expression");
    scanf("%s",infix);
    evaluate();
    printf("\npostfix expression is %s",postfix);
    return 0;
}
