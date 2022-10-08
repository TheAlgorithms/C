#include<stdio.h>
#define max 10
int main()
{
int i,j,n,bt[max],p[max],wt[max],tat[max],pr[max],total=0,pos,temp;
float avg_wt,avg_tat;
printf("Enter Total Number of Process:");
scanf("%d",&n); 
printf("\nEnter Burst Time and Priority For ");
for(i=0;i<n;i++)
{
printf("\nEnter Process %d: ",i+1);
scanf("%d",&bt[i]);
scanf("%d",&pr[i]);
p[i]=i+1;           
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(pr[j]<pr[pos])
pos=j;
}
temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
avg_wt=total/n;      
total=0;
printf("\n\nProcess\t\tBT\t\tWT\t\tTAT");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];     
total+=tat[i];
printf("\n P%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    } 
avg_tat=total/n;     
printf("\n\nAverage Waiting Time = %.2f",avg_wt);
printf("\nAvg Turn Around Time = %.2f\n",avg_tat);
return 0;
}
