#include<stdio.h>
void quick( int a[],int first,int last){
    int i,j,pivot,t;
    if(first<last)
    {
        i=first;
        j=last;
        pivot=first;
     while(i<j)
        {
            while(a[i]<=a[pivot]&&i<=last)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {t=a[i];
            a[i]=a[j];
            a[j]=t;

            }
        }
        t=a[pivot];
        a[pivot]=a[j];
        a[j]=t;
        quick(a,first,j-1);
        quick(a,j+1,last);
    }
}
 void main()
 {
     int n,i,j,key,t;
     printf("Enter the size of the array");
     scanf("%d",&n);
     int a[n];
     printf("Enter the elements to the array");
     for(i=0;i<n;i++)
       {

        scanf("%d",&a[i]);}
     printf("Elements before sorting are");
     for(i=0;i<n;i++)
      {

       printf("%d ",a[i]);}
        printf("Elements aftere sorting are");
        quick(a,0,n-1);
         for(i=0;i<n;i++)
      {

       printf("%d ",a[i]);}

 }
