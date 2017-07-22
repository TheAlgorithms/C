#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a ,int *b)
{int t;t =*a;*a=*b;*b=t;}
int part(int a[],int l,int r,int n,int pivot,int pindex)
{int p1=l,p2=r;
    while(p2>p1)
    {
        if (a[p1] > pivot && a[p2]<pivot)
        {swap(&a[p1],&a[p2]);}
        else
        {
            if (a[p1] <=pivot)
            {p1++;}
            if (a[p2]>=pivot)
            {p2--;}
        }
    }
    swap(&a[pindex],&a[p2]);
    return p2;
}
int rselect(int a[],int l,int r,int n,int o)
{
    int pivot,pindex,pactual;
    if (r>l)
    {
    pindex = rand()%(r-l+1);
    pivot = a[pindex];
    pactual = part(a,l,r,n,pivot,pindex);
    
    if (pactual == o)
    {return a[pactual];}
    
    if (o < pactual)
    {rselect(a,l,pactual-1,n,o);}
    
    if (o>pactual)
    {rselect(a,pactual+1,r,n,o-pactual);}
    }
    if (r==l)
    {return a[l];}
}
int main()
{srand(time(NULL));
    int n,o,i,*a;
   scanf("%d %d",&n,&o);
   a = (int*)malloc(n*sizeof(int));
   for (i=0;i<n;i++)
   {scanf("%d",a+i);}
printf("\n\n%d",rselect(a,0,n-1,n,o));
    return 0;
}

