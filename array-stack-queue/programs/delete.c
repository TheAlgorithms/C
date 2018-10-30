#include<stdio.h>
int a[20];
int main()
{
 int n,i,d;
 printf("Enter the size of the array:");
 scanf("%d",&n);
 printf("Enter the array elements:");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 printf("Enter the position to be deleted:");
 scanf("%d",&d);
 if(d<n)
 {
   for(i=d-1;i<n;i++)
    a[i]=a[i+1];
   printf("The new array is:\n");
   for(i=0;i<n-1;i++)
    printf("%d\n",a[i]);
 }
}
