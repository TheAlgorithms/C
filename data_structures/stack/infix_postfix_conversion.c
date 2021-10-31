#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#define size 50
char STACK[size];
int tos=-1,ele;
void push(int);
char pop();
char infix[30],output[30];
int prec(char);
int main()
{
    int i=0,j=0,length;
    char temp;
    printf("Enter an infix expression: ");
    gets(infix);
    length=strlen(infix);
    for(i=0;i<length;i++)
    {
        //If the scanned character is an operand then push it into the stack directly.
        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!=')' && infix[i]!='(' )
        {
            output[j++]=infix[i];
        }
        else//if the scanned expression is an operator
        {
            if(tos==0)//push it onto the stack if the stack is empty
            {
                push(infix[i]);
            }
            else
            {
                //if the scanned character is not a parenthesis
                if(infix[i]!=')' && infix[i]!='(')
                {
                    //if the priority of scanned character is smaller than priority of operator
                    if(prec(infix[i]) <= prec(STACK[tos]) )
                    {
                        //repeatedly pop until you can push the operator
                        while(prec(infix[i])<=prec(STACK[tos]))
                        {
                        temp=pop();
                        output[j++]=temp;
                        }
                        push(infix[i]);
                    }
                    else
                    {
                        push(infix[i]);
                    }
                }
                else//case for parenthesis
                {
                    if(infix[i]=='(')
                    {
                        push(infix[i]);
                    }
                    if(infix[i]==')')
                    {
                        temp=pop();
                        while(temp!='(')
                        {
                            output[j++]=temp;
                            temp=pop();
                        }
                    }
                }
            }
        }
    }
    while(tos!=-1)//displaying the contents of the output
    {
        output[j++]=pop();
    }
    printf("The Postfix expression is: %s",output);
    getch();
    return 0;
}
void push(int ele)
{
    tos++;//while pushing top increases
    STACK[tos]=ele;
}
char pop()
{
    char temp;
    temp=STACK[tos];
    tos=tos-1;//while popping top decreases
    return temp;
}
int prec(char symbol)
{
    if(symbol== '(')
        return 0;
    if(symbol== ')')
        return 0;
    if(symbol=='+' || symbol=='-')
        return 1;
    if(symbol=='*' || symbol=='/')
        return 2;
    if(symbol=='^')
        return 3;
    return 0;
}
