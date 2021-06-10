#include<stdio.h>
#include<math.h>
int main()
{
    int q[100],a[100],n,h,s=0,t,f[100],d=12345667,index;
    float avg;
    printf("Enter the size of the queue");
    scanf("%d",&n);
     printf("Enter initial head position ");
    scanf("%d",&h);
   
    printf("Enter queue element ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
        f[i]=0;
    }
    
      for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
    {   
      if(abs(q[j]-h)<d&&f[j]==0)
      {  d=abs(q[j]-h);
          index=j;
      }
    }
    s+=d;
    f[index]=1;
    d=12345667;
    h=q[index];
    a[i]=h;
    
    }
   
    
     printf("*********Seek sequance ****** \n");
     
  for(int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
      
    }
     printf("\n Total seek time = %d",s);
     avg=s/(float)n;
     printf("\n Total seek time = %f",avg);
    return 0;
}


//Writer:- Amit Yadav