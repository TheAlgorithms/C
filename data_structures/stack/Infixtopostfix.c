#include<stdio.h>
#include<string.h>
 #include<stdlib.h>
 #include<math.h>
 #define SIZE 10
 #define TRUE 1
 #define FALSE 0
/**********************************************/
 struct stack
 {
     int TOP;
     char Item [SIZE];
 };
/**********************************************/

 struct stack S;
 /**********************************************/
 char StackTOP()
 { char x;
   x=S.Item[S.TOP];
     return x;
 }

/**********************************************/
 void Initalize(void)
 {
     S.TOP=-1;
 }
 /**********************************************/

int Empty(void)
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
}
/**********************************************/

 int Pop()
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
/*int evulate(int operand1,int operand2,char op)
 {
     switch(op)
     {
        case '+':return (operand1+operand2);
        case '*':return (operand1*operand2);
        case '/':return (operand1/operand2);
        case '%':return (operand1%operand2);
        case '-':return (operand1-operand2);
        case'^':return pow(operand1,operand2);
     }
 }
 /**********************************************/
 int precend(char x,char y)
 {
     if(x=='^'||x=='*'||x=='/'||x=='%')
     {
         if(y=='^')
         return FALSE;
         else
            return TRUE;
     }
     else
     {

        if (x=='+'||x=='-')
     {
         if(y=='+'||y=='-')
             return TRUE;
     else return FALSE;
     }
     }
 }
/**********************************************/
int Infixtopostfix( char str[])
{
    int i=0,j=0;
     char x,symbol,op;
     char postfix[20];
     int value;
     Initalize();
     while(str[i]!='\0')
        {
            symbol=str[i];
        if(symbol>='a'&&symbol<='z')
            postfix[j++]=symbol;
        else
        {
            while(!Empty()&& precend(StackTOP(),symbol))
            {
            x=Pop();
            postfix[j++]=x;
            }
        Push(symbol);

        }
            i++;
    }
    while(!Empty())
    {
        x=Pop();
        postfix[j++]=symbol;
    }
    postfix[j]='\0';
    //x=Pop();
    //return x;
printf("%s",postfix);

}
 /*/**********************************************/
 void main()
{    char x;
     char str[100];
     printf("enter the string");
     gets(str);
     Infixtopostfix(str);
     //printf("%d",x);
 }


