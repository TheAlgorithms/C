#include <stdio.h>
void double_sort(int a[],int n);
void input_array(int a[],int n);
void output_array(int a[],int n);
int main()
{
  int n,arr[100],ch;
  printf("enter no of elements ");
  scanf("%d",&n);
  input_array(arr,n);
  double_sort(arr,n);
  output_array(arr,n);
}
void input_array(int a[],int n)
{
  printf("enter the elements \n");
  for (int x=0;x<n;x++)
    scanf("%d",&a[x]);
}
void output_array(int a[],int n)
{
  printf("the sorted elements are \n");
  for (int x=0;x<n;x++)
    printf("%d ",a[x]);
}
void double_sort(int a[],int n)
{
  int i=0,j=1;
  for (i=0; i < ((n-1)/2)+1; i++)
  {
    for (j=0; j < n-1; j++)
    {
      if (a[j+1]<a[j])
      {
        int temp=a[j+1];
        a[j+1]=a[j];
        a[j]=temp;
      }
      if (a[n-1-j]<a[n-2-j])
      {
        int temp=a[n-1-j];
        a[n-1-j]=a[n-2-j];
        a[n-2-j]=temp;
      }
    }
  }
}
