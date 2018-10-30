#include<stdio.h>
int a[20];
int main()
{
 int e,p,i,n;
 printf("Enter the array size\n:");
 scanf("%d",&n);
 printf("Enter the array elements:");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 printf("Enter the element to insert  and position:");
 scanf("%d%d",&e,&p);
 if(p<=n||p<=0)
 {
   for(i=n-1;i>=p-1;i--)
    a[i+1]=a[i];
   a[p-1]=e;
   printf("The new array elements are:\n");
   for(i=0;i<=n;i++)
    printf("%d\n",a[i]);
 }
 else
  printf("Wrong input");
}
