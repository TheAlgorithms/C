#include<stdio.h>
void swap(int* xp,int* yp);
void bubblesort(int a[],int n );
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
    bubblesort(a,n);
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d ",i,a[i]);
    }
    return 0;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubblesort(int a[],int n)
{
    int i,j,temp=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
