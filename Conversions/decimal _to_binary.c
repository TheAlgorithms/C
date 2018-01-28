#include<stdio.h>
int main()
{
    int n,re,a[10000],j;
    printf("\nenter the no ");
    scanf("%d",&n);
    int i=0;
    while(n>0)
    {

        re=n%2;
        a[i]=re;
        n=n/2;
        i++;
    }
    int k;
    k=i-1;
    printf("\n the number in binary is: ");
    for(j=k;j>=0;j--)
    {
        printf("%d",a[j]);
    }
    return(0);
}

