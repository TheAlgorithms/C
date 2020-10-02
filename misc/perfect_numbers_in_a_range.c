// This program finds the number of perfect numbers in a given range
// @author [Mayank Chowdhary](https://github.com/m607stars)

#include<stdio.h>
void main ()
{
int i,n,n1,n2,s;
printf("Enter the given range\n");
scanf ("%d",&n1);
scanf("%d",&n2);
for (n=n1;n<=n2;n++)
{
  s=0;
  for (i=1;i<n;i++)
  {
    if (n%i==0)
    {
        s=s+i;
    }
  }
  if (s==n)
  {
    printf("%d is a perfect number\n",n);
  }
}
}
