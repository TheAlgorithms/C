#include <stdio.h>
void swap(int *a,int *b)
{
    int t;t=*a;*a=*b;*b=t;
}
void qiksort(int a[],int n,int l,int r)
{int pivot = a[l];
   int p1=l+1,p2=r;
   if (r>l)
   {
   while(p2>=p1)
   {if (a[p1]>pivot && a[p2]<pivot)
           {
               swap(&a[p1],&a[p2]);
               p1++;p2--;
           }
           
          else
          {if (a[p1]<=pivot)
          {
              p1++;
          }
          if (a[p2]>=pivot)
          {p2--;}
          
          }
   }
   swap(&a[p2],&a[l]);
   
   qiksort(a,n,l,p2-1);
   qiksort(a,n,p2+1,r);
   
   }
    
}
int main()
{
 int n,*a,i;
 scanf("%d",&n);
a = (int*)malloc(n*sizeof(int));
for (i=0;i<n;i++)
{scanf("%d",a+i);}
qiksort(a,n,0,n-1);
printf("\n\n");
for (i=0;i<n;i++)
{printf("%d",a[i]);}

    return 0;
}

