#define MAX_SIZE 100
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int *PUSH(int *);
int *POP(int *);
void display(int *);
int palin();
void check(int *);
int pop(int *);

int top=-1,C[MAX_SIZE],j,k,rev,temp,pal,X;
int main()
{
 int A[MAX_SIZE],K,flag;
 int *p=A;
 
 while(1){
 printf("Enter the Choice Of Operation : \n 1.PUSH\n 2.POP\n 3.Check FOr Palindrome\n 4.Check fOR OverFLow Or UnderFlow\n 5.Display\n 6.Exit\n");
  scanf("%d",&K);

 switch(K)
  {
  case(1):p=PUSH(A);
          break;
  case(2):p=POP(A);
          break;
  case(3):flag=palin();
          if(flag==1)
          printf("The Number Is Palindrome!!\n");
          else
          printf("The Number Is Not Palindrome!!\n");
          break;
  case(4):check(A);
          break;
  case(5):display(A);
          break;
  case(6):exit(0);
  
  default:printf("Wrong Choice!!!");
 }
 }
}

int *PUSH(int *A){
 int p,i;
  if(top==(MAX_SIZE-1))
   { printf("Stack Is Full!\n");
     return A;
   }
 
 printf("ENter The Element to be pushed : \n");
  scanf("%d",&p);
 top=top+1;
 A[top]=p;
 return A;
}

int *POP(int *A){
  if(top==-1)
   { printf("Stack Is Empty\n");
     return A;
   }
 printf("Element Poped : %d\n",A[top]);
 top=top-1;
 
 return A;
}

void display(int *A){
int i;

if(top==-1)
{ printf("Stack is Empty\n");
}

for(i=0;i<=top;i++)
{
printf("Element %d Of Stack Is : %d\n",(i+1),A[i]);
}
}

void check(int *A){
if(top==-1)
{ printf("Stack is Empty.....UnderFlow\n");
}
if(top==(MAX_SIZE-1))
 printf("Stack Is Full....OverFlow\n");
if(0<=top<(MAX_SIZE-1))
 printf("The Stack Is Neither UnderFlow Or OverFlow\n");
}

int pop(int *X)
{ k=0;rev=0;
  while(k<j){
  rev=rev*10+X[k];
   k++; 
 }
 if(pal==rev)
  return 1;
 else 
  return 0;
}

int palin(int *A){
 printf("Enter The Number To Be Checked For Palindrome : ");
  scanf("%d",&pal);
   X=pal;j=0;
 
 while(X!=0){
  temp=X%10;
  C[j]=temp;
  X=X/10;
  j++;
  }
 return pop(C);
}

