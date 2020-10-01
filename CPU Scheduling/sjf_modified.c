#include<stdio.h>
int main()
{
	int n,i,j,temp;
	int p[100],arrival_time[100],burst_time[100];
	int completion_time[100],turn_around_time[100],waiting_time[100];
	float avg_turn_around_time=0.0, avg_waiting_time=0.0;

	//Extract process info from user
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

	//Sorting the process based on arrival time and burst time;
        for(i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
		if(arrival_time[i]<arrival_time[j])continue;
		if(arrival_time[i]==arrival_time[j])
			if(burst_time[i]<burst_time[j])continue;

		//swapping structures
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
            	//need to find the shortest job
            	for(j=i+1;j<n;j++)
            	{
            		/* since the process is sorted in increasing order of arrival time , if process j have not reached, then remaining process also will not reach */
            		if(arrival_time[j]>completion_time[i-1])break;

			if(burst_time[i]<burst_time[j])continue;

			//swapping structures
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
            	completion_time[i]=completion_time[i-1]+burst_time[i];
            }

            turn_around_time[i]=completion_time[i]-arrival_time[i];
            waiting_time[i]=turn_around_time[i]-burst_time[i];
        }

        //printing the process stimulation result

        printf("\n Processes \t Arrival Time \t Burst Time \tCompletion Time\tTurn Around Time\tWaiting Time ");
        for(i=0;i<n;i++)
        {
            printf("\n     %d\t\t     %d\t\t     %d\t\t     %d\t\t       %d\t\t       %d\t\t ",p[i],arrival_time[i],burst_time[i],completion_time[i],turn_around_time[i],waiting_time[i]);
            avg_waiting_time += waiting_time[i];
            avg_turn_around_time += turn_around_time[i];
        }
        printf("\n Average turn around time is:\n");printf(" %f",avg_turn_around_time/n);
        printf("\n Average waiting time is:\n");printf(" %f \n",avg_waiting_time/n);
}


