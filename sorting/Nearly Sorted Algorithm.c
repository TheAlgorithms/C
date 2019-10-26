#include<stdio.h>
void sort(int a[],int n,int k)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
int main()
{
	int num;scanf("%d",&num);
	while(num--)
	{
	    int n,k;
	    scanf("%d%d",&n,&k);int a[n];
	    for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	    sort(a,n,k);
	    for(int i=0;i<n;i++)
	    printf("%d ",a[i]);
	    printf("\n");
	}
}
