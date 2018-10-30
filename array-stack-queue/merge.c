#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int merge(int *,int,int,int);
int part(int *,int,int);
int  main()
{
   int *a,i;
   printf("Enter the elements to be sorted:");
   scanf("%d",&n);
   a=(int *)malloc(sizeof(int) * n);
   srand(time(NULL));
   for(i=0;i<n;i++)
      *(a+i)= rand() % 100;
   printf("Numbers before sorting:\n");
   for(i=0;i<n;i++)
     printf("%d\t",*(a+i));
   part(a,0,n-1);
   printf("\nAfter sorting:\n");
   for(i=0;i<n;i++)
     printf("%d\t",*(a+i));
   return 0;
}

int part(int *a,int min,int max)
{
   int mid;
   if(min<max)
   {
      mid=(min+max)/2;
      part(a,min,mid);
      part(a,mid+1,max);
      merge(a,min,mid,max);
   }
}

int merge(int *a,int min,int mid,int max)
{
   int *tmp;
   tmp=(int *)malloc(sizeof(int)*n);
   int i,j,k,m;
   j=min;
   m=mid+1;
   for(i=min; j<=mid && m<=max; i++)
   {
     if(a[j]<=a[m])
     {
        tmp[i]=a[j];
	j++;
     }
     else
     {
        tmp[i]=a[m];
	m++;
     }
   }
   if(j>mid)
   {
     for(k=m;k<=max;k++)
     {
        tmp[i]=a[k];
	i++;
     }
   }
   else
   {
      for(k=j;k<=mid;k++)
      {
         tmp[i]=a[k];
	 i++;
      }
   }
   for(k=min;k<=max;k++)
      a[k]=tmp[k];
}
