#include<stdio.h>
int main()
{
        int temp,i,j,n;
        int p[100],burst_time[100],arrival_time[100];
        int completion_time[100],turn_around_time[100],waiting_time[100];
        float sum=0,sum1=0;
        printf(" Enter the no of processes:");
        scanf(" %d",&n);
        for(i=0;i<n;i++)
        {
            printf(" Enter the Process Id:");
            scanf(" %d:",&p[i]);
        }
        printf("\n Enter the arrival times:\n");
        for(i=0;i<n;i++)
        {
            printf(" P%d:",p[i]);
            scanf(" %d",&arrival_time[i]);
        }
        printf("\n Enter the burst times:\n");
        for(i=0;i<n;i++)
        {
            printf(" P%d:",p[i]);
            scanf(" %d",&burst_time[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(arrival_time[i]<arrival_time[j])continue;

                        temp=arrival_time[i];
                        arrival_time[i]=arrival_time[j];
                        arrival_time[j]=temp;

                        temp=burst_time[i];
                        burst_time[i]=burst_time[j];
                        burst_time[j]=temp;

                        temp=p[i];
                        p[i]=p[j];
                        p[j]=temp;

            }
        }
        for(i=0;i<1;i++)
        {
            completion_time[i]=arrival_time[i]+burst_time[i];
        }
        for(i=1;i<n;i++)
        {
            if(arrival_time[i]>=completion_time[i-1])
            {
                completion_time[i]=arrival_time[i]+burst_time[i];
            }
            if(arrival_time[i]<completion_time[i-1])
            {
                completion_time[i]=completion_time[i-1]+burst_time[i];
            }
        }
        for(i=0;i<n;i++)
        {
            turn_around_time[i]=completion_time[i]-arrival_time[i];
        }
        for(i=0;i<n;i++)
        {
            waiting_time[i]=turn_around_time[i]-burst_time[i];
        }
        printf("\n Process Id \t Arrival Time \t Burst Time \tCompletion Time \tTurn Around Time \tWaiting Time ");
        for(i=0;i<n;i++)
        {
            printf("\n   P%d\t\t    %d\t\t    %d\t\t        %d\t\t         %d\t\t           %d\t\t ",p[i],arrival_time[i],burst_time[i],completion_time[i],turn_around_time[i],waiting_time[i]);
        }
        printf("\n Average turn around time is:\n");
        for(i=0;i<n;i++)
        {
            sum=sum+turn_around_time[i];
        }
        printf(" %f",sum/n);
        printf("\n Average waiting time is:\n");
        for(i=0;i<n;i++)
        {
            sum1=sum1+waiting_time[i];
        }
        printf(" %f",sum1/n);
}

