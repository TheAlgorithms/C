// a disarium number is a number such that sum of the digits of the number raised to their respective position equals the number
#include <stdio.h>
#include <math.h>

int main() 
{
 int n,i=0,j,sum=0,l,k;
 scanf("%d",&n);
 k=n; //number stored in temporary variable
 j=k;
 while(n>0)
 {
  d=n%10;
  n=n/10;
  i++; //to get the number of digits which will be the position for last digit
 }
   while(k>0)
   {  
    l=k%10; //to get the digit
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
