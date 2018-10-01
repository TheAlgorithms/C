#include<stdio.h>
#include<conio.h>
void insert(int a[], int n,int j)
{
  if(j<n)
  {
    int i,key;
    key=a[j];
    i=j-1;
    while(i>=0 && a[i]>key)
    {
      a[i+1]=a[i];
      i=i-1;
    }
    a[i+1]=key;
    insert(a,n,j+1);
  }
}
int main()
{
  int a[10],i,n;
  printf("Enter the no. of elements\n");
  scanf("%d",&n);
  printf("Enter the elements\n" );
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  insert(a,n,1);
  printf("Sorted array\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
