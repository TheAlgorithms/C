#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 30
int push(int p);
int pop();
int top=-1,i;
char a[MAX];
int main()
{
  char ch;
  int res,op1,op2;
  printf("Enter the postfix expression:");
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
        case '+':res=op2+op1;
	         push(res);
		 break;
        case '-':res=op1-op2;
	         push(res);
		 break;
	case '*':res=op2*op1;
	         push(res);
		 break;
	case '/':res=op1/op2;
                 push(res);
		 break;
	case '%':res=op1%op2;
	         push(res);
		 break;
	case '^':res=pow(op1,op2);
	         push(res);
		 break;
        default:printf("Spaces are not allowed\n");
      }
    }
  }
  res=pop();
  printf("The result is:%d\n",res);
}

int push(int p)
{
  if(top==MAX-1)
     printf("Stack overflow\n");
  else
  a[++top]=p;
}

int pop()
{
  if(top==-1)
    printf("Stack underflow\n");
  else
    return a[top--];
}


