#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *a,i,sum=0,n;
  printf("Enter the n value:");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  printf("Enter the array elements:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  printf("\n%d",sum);
}
