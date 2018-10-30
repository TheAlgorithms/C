#define MAX 50
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int push(int);
int pop();

int top=-1,i;
char a[MAX],stack[MAX];

int main()
{
char ch;
int res,op1,op2;

printf("Enter The PostFix Expression : ");
 scanf("%s",a);

for(i=0;i<strlen(a);i++)
{
ch=a[i];
 if(isdigit(ch))
  push(ch-'0');

 else 
 {
 op2=pop();
 op1=pop();
  
switch(ch)
{
case'+':res=op2+op1;
         push(res);
         break;
case'-':res=op1-op2;
         push(res);
          break;
case'*':res=op2*op1;
        push(res);
         break;
case'/':res=op1/op2;
         push(res);
          break;
case'%':res=op1%op2;
         push(res);
          break;
//case'^':res=pow(op1,op2);
        // push(res);
          //break;
default:printf("Spaces Not Allowed Or Invalid Operator!!\n");

}
 
 }
}
res=pop();
printf("the result is : %d\n",res);
return 0;
}

int push(int p)
{
if(top==(MAX-1))
 printf("Stack IS oVERFLOW!!\n");

else
stack[++top]=p; 
}

int pop()
{
if(top==-1)
 printf("Stack is Underflow!!\n");

else 
 return stack[top--];
}
