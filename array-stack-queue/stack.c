#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 3
int push(int p);
int pop();
int show();
int palindrome();
int a[MAX],b[MAX],n,i,top=-1;
int main()
{ 
  for(;;)
  {
  printf("1.Push\n2.Pop\n3.Show\n4.palindrome\n5.exit\nEnter your choice:");
  int ch;
  scanf("%d",&ch);
  switch(ch)
   {
    case 1: printf("Enter the element to be pushed:");
            int  p;
            scanf("%d",&p);
            push(p);
            break;
    case 2:pop();
           break;
    case 3:show();
           break;
    case 4:palindrome();
           break;
    case 5:exit(0);
    default:printf("wrong entry");
            break;
   }
  }
}
int push(int p)
{
  if(top==MAX-1)
    printf("Stack is full\n");
  else
    a[++top]=p;
}
int pop()
{
  if(top==-1)
   printf("Stack is empty\n");
  else
  {
      printf("The array element deleted is:%d",a[top]);
      top--;
  }
}
int show()
{
  printf("the array elements are:\n");
  for(i=0;i<=top;i++)
    printf("%d\t",a[i]);
}
/*int palindrome()
{
  int b[MAX],flag=0;
  int i=top,j=0;
  while(i!=0)
  {
    b[j]=a[i];
    i--;
    j++;
  }
  for(i=0;i<top;i++)
  {
   if(a[i]==b[i])
     flag=1;
   else
   {
     flag=0;
     break;
   }
  }
  if(flag==1)
   printf("Palindrome");
  else
   printf("Not palindrome");
} */
int palindrome()
{
  int num,x,r,rev=0;
  printf("Enter the number to check for palindrome:");
  scanf("%d",&num);
  x=num;
  top=-1;
  while(num!=0)
  {
    r=num%10;
    push(r);
    num=num/10;    
  }
  int p=0;
  while(top>=0)
 {
    rev=rev+a[top--]*pow(10,p);
    //pop(top);
    
    p++;
 }
 if(x==rev)
   printf("Palindrome\n");
 else
   printf("Not palindrome\n");
}
  











      








