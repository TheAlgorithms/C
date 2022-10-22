#include<stdio.h>
void insertsort(int a[],int n );
int main()
{
    int a[100],n,i,j,w;
    printf("enter value of n: ");
    scanf("%d",&n);
    //write the loop for reading array elements
    for(i=0;i<n;i++)
    {
        printf("enter element for a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    printf("before sorting the elements in the array are:\n");
    //write the loop to display the array elements
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d ",i,a[i]);
    }
    printf("\n");
    printf("after sorting the elements in the array are:\n");
    //write the loop to display array elements after sorting
    insertsort(a,n);
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d ",i,a[i]);
    }
    return 0;
}
void insertsort(int a[],int n)
{
    int i,j,x;
    for(i=0;i<n;i++)
    {
        j=i-1;
        x=a[i];
        while(a[j]>x && j>-1)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

