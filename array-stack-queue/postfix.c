#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 30
int push(char p);
int pop();
int top=-1;
char in[MAX],po[MAX],s[MAX];
int push(char p)
{
  if(top==MAX-1)
    printf("Stack overflow\n");
  else
  s[++top]=p;
}

int pop()
{
  if(top==-1)
    printf("Stack underflow\n");
  else
    return s[top--];
 }

int priority(char x)
{
  if(x=='(')
   return 0;
  else if(x=='+'||x=='-')
   return 1;
  else if(x=='*'||x=='/'||x=='%')
   return 2;
  else
   return 3;
}

int main()
{
 printf("Enter the infix string:");
 scanf("%s",in);
 int i,j;
 printf("\n");
 for(i=0,j=0;i<strlen(in);i++)
 {             
   if(isdigit(in[i]))
     po[j++]=in[i];
     //printf("%d",in[i]);
   else if(in[i]=='(')
     push(in[i]);
   else
   {
      if(in[i]==')')
      {
         while(in[i]!='(')
	   po[j++]=pop();
	  //printf("%c",pop());
	 top=top-1;
      }
      else
      {
         while(priority(in[i])<=priority(s[top]))
	   po[j++]=pop();
	   //printf("%c",pop());
	 push(in[i]);
      }
   }
 }
 while(top>=0)
   po[j++]=pop();
  //printf("%c",pop());
 po[j]='\0';  
 printf("The postfix expression is:%s",po);
 printf("\n");
 }
     

