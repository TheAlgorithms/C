#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0
/**********************************************/
struct stack
{
char TOP;
char Item [SIZE];
}; /**********************************************/
struct stack S;
/**********************************************/
void Initalize(void)
{
S.TOP=-1;
} /**********************************************/
char Empty(void)
{
if(S.TOP==-1)
return TRUE;
else
return FALSE;
}
/**********************************************/
void Push( char x)
{
if(S.TOP== SIZE-1)
{
printf("stack overflow");
exit (1);
}
S.TOP=S.TOP+1;
S.Item[S.TOP]=x;
} /**********************************************/
char Pop()
{
char x;
if(Empty())
{
printf("stack underflow");
exit(1);
}
x=S.Item[S.TOP];
S.TOP=S.TOP-1;
return x;
}
/**********************************************/
paranthesis(char str[])
{
Initalize();
 int a;
int i=0;
while(str[i]!='\0')
{
 if(str[i]=='(')
 {
     Push(str[i]);
 }
 else
    {
    if(str[i]==')')
    {
        if(!Empty())
        {
        Pop();
        }
        else
        {
            a=0;
        break;
        }
    }
   }
   i++;
   }
  if(a==0)
     {
        printf(" invalid expression");
     }
   else
   {
       if(Empty())
       {
           printf(" valid expression");
       }
       else
       {
           printf(" invalid expression");
       }
   }
}
 /**********************************************/
void main()
{
char str[10];
 int i;
printf("enter the string");
gets(str);
paranthesis(str);
}





