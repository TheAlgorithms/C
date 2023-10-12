#include <stdio.h>
int rec(int n)
{
  if(n==0)
    return 1;
  else
    return n*rec(n-1);
    
}
int main(void) 
{
  int n;
  printf("Enter number:\n");
  
  scanf("%d",&n);
  
  int a=rec(n);
  printf("%d\n",a);
  return 0;
  
}
