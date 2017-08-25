#include <stdio.h>
#include<math.h>

int main() 
{
 int n,i=0,j,sum=0,l,k;
 scanf("%d",&n);
 k=n;
 j=k;
 while(n>0)
 {
  d=n%10;
 n=n/10;
 i++;
   }
   while(k>0)
   {  
    l=k%10;
    sum=sum+pow(l,i);
    k=k/10;
    i--;
   }
  if(j==sum)
  {
   printf("It is an  disarium number");
  }
  else
  printf("It is not disarium number");
 return 0;
}
