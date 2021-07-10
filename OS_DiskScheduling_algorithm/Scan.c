#include<stdio.h>
#include<math.h>
int main()
{
    int a[10],n,h,s=0,max,d,t,b[10],c[10],t1=0,t2=0;
    float avg;
    printf("Enter max range of disk =");
    scanf("%d",&max);
    printf("enter initial head position ");
    scanf("%d",&h);
     printf("enter the size of queue request ");
     scanf("%d",&n);
      printf("enter the queue of disk  position to be read ");
      for(int i=0;i<n;i++)
      {  
          scanf("%d",&a[i]);
      }
       t=h;
       a[n]=h;
       a[n+1]=max;
       a[n+2]=0;
       for(int i=0;i<n+2;i++)
       {
           for(int j=0;j<n+2-i-1;j++)
           {
               if(a[j]>a[j+1])
               {
                   t=a[j];
                   a[j]=a[j+1];
                   a[j+1]=t;
               }
           }
       }
       int i,k,j=0;
       for( i=0;i<=n+2;i++)
       {
           if(h==a[i])
           break;
       }
       k=i;
       if(k<n/2)
       {
           for(i=k;i<n+3;i++)
           {
               b[j++]=a[i];
           }
           for(i=k-1;i>=0;i--)
           {
               b[j++]=a[i];
           }
       }
       else
       {
          for(i=k;i>=0;i--)
           {
               b[j++]=a[i];
           }
           for(i=k+1;i<n+3;i++)
           {
               b[j++]=a[i];
           } 
       }
       t=b[0];
       printf("%d",t);
      for( j=1;j<=n+2;j++)
      {
          if(h!=b[j])
          {
          s+=abs(b[j]-t);
          printf(" --> %d",b[j]);
          t=b[j];
          }
      }
      printf("Total seek time = %d\n",s);
      avg=s/(float)n;
      printf("Average seek time is %f\n",avg);
      return 0;
    
}
//Writer:- Amit yadav
