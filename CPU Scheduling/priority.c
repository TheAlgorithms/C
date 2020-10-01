#include<stdio.h>
int main()
{
	int n,i,j,temp;
	int p[100],arrival_time[100],burst_time[100],priority[100];
	int completion_time[100],turn_around_time[100],waiting_time[100];
	float sum=0, sum1=0;

	//Extract process info from user
	printf(" Enter the no of processes:");
	scanf(" %d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the Process Id:");
		scanf(" %d:",&p[i]);
		printf("\n Enter the arrival times:");
		scanf(" %d",&arrival_time[i]);
		printf("\n Enter the burst times:");
		scanf(" %d",&burst_time[i]);
		printf("\n Enter the priorities:");
		scanf(" %d",&priority[i]);
	}

	//Sorting the process based on arrival time and burst time;
        for(i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
		if(arrival_time[i]<arrival_time[j])continue;
		if(arrival_time[i]==arrival_time[j])
			if(priority[i]<priority[j])continue;

		//swapping structures
                temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;

                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;

                temp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

            }
        }

	if(n>=1)
        {
            completion_time[0]=arrival_time[0]+burst_time[0];
            turn_around_time[0]=completion_time[0]-arrival_time[0];
            waiting_time[0]=turn_around_time[0]-burst_time[0];
        }
        for(i=1;i<n;i++)
        {
	    //process p have arrived after completion of previous process
            if(arrival_time[i]>=completion_time[i-1])
            {
                completion_time[i]=arrival_time[i]+burst_time[i];
            }
            else
            {
            	//need to find the higher priority
            	for(j=i+1;j<n;j++)
            	{
            		/* since the process is sorted in increasing order of arrival time , if process j have not reached, then remaining process also will not reach */
            		if(arrival_time[j]>completion_time[i-1])break;

			if(priority[i]<priority[j])continue;

			//swapping structures
             		temp=arrival_time[i];
             		arrival_time[i]=arrival_time[j];
             		arrival_time[j]=temp;

                    temp=priority[i];
                    priority[i]=priority[j];
                    priority[j]=temp;

	                temp=burst_time[i];
        	        burst_time[i]=burst_time[j];
        	        burst_time[j]=temp;

        	        temp=p[i];
        	        p[i]=p[j];
        	        p[j]=temp;
            	}
            	completion_time[i]=completion_time[i-1]+burst_time[i];
            }

            turn_around_time[i]=completion_time[i]-arrival_time[i];
            waiting_time[i]=turn_around_time[i]-burst_time[i];
        }

        //printing the process stimulation result

        printf("\n Processes \t Arrival Time \t Priority \tBurst Time\tCompletion Time \tTurn Around Time\tWaiting Time ");
        for(i=0;i<n;i++)
        {
            printf("\n     %d\t\t     %d\t\t     %d\t\t     %d\t\t     %d\t\t          %d\t\t          %d\t\t ",p[i],arrival_time[i],priority[i],burst_time[i],completion_time[i],turn_around_time[i],waiting_time[i]);
            sum1 += waiting_time[i];
            sum += turn_around_time[i];
        }
        printf("\n Average turn around time is:\n");printf(" %f",sum/n);
        printf("\n Average waiting time is:\n");printf(" %f \n",sum1/n);
}
