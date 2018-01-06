//convert infix to postfix
#include <stdio.h>
char stack[20]; //declaring an empty stack
int top = -1;   //declaring top of stack

void push(char x) //push function
{
    stack[++top] = x; //each time it is pushed top is increamented
}

 char pop()  //pop function
{
    if(top == -1)
        return -1;
    else
        return stack[top--]; //each time it is popped top is decreamented
}

 int priority(char x) // to check the priority of characters
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
        if(x=='^')
        return 3;
}
 
int main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(') //push it directly into the stack
            push(*e);
        else if(*e == ')') //pop until we gwt the left parenthesis
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e)) //pop until priority of top of stack is greater than equal to priority of expressions character
                printf("%c",pop());
            push(*e); //otherwise push
        }
        e++;
    }
    // keep popping until top is not -1
    while(top != -1)
    {
        printf("%c",pop()); 
    }
}
