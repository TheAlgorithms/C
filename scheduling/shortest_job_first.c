/*Program for Shortest Job First Scheduling*/
#include<stdio.h>
#include<stdlib.h>

/*function to swap two pointers*/
void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;

}

/*function to sort burst time and process numbers arrays based on burst times using selection sort*/
void burst_sort(int* burst,int* p_no,int n)
{
	int pos;
	for(int i=0;i<n;i++)
	{
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(burst[j]<burst[pos])
				pos=j;
		}

		swap(&burst[i],&burst[pos]);
		swap(&p_no[i],&p_no[pos]);
	}	
}

/*function to calculate the total waiting time of all processes*/
int wait_calc(int* wait,int* burst,int n)
{
	wait[0]=0;
	int total_wait=0;
	for(int i=1;i<n;++i)
	{
		wait[i]=0;
		for(int j=0;j<i;++j)
			wait[i]+=burst[j];
		total_wait+=wait[i];
	}

	return total_wait;
}

/*function to calculate the total turnaround time of all processes*/
int turn_time(int* turn,int* burst,int* wait,int n)
{
	int total_turn=0; 
	for(int i=0;i<n;++i)
	{
		turn[i]=burst[i]+wait[i];
		total_turn+=turn[i];
	}
	return total_turn;
}
int main()
{
	int n;
	float avg_wt,avg_tat;
	printf("****Shortest Job First****\n\n");
	printf("Enter no. of jobs:  ");
	scanf("%d",&n);
	int* burst=(int*)malloc(sizeof(int)*n);	/*Array for storing burst times*/
	int* wait=(int*)malloc(sizeof(int)*n);	/*Array for storing waiting times*/
	int* turn=(int*)malloc(sizeof(int)*n);	/*Array for storing turnaround times*/
	int* p_no=(int*)malloc(sizeof(int)*n);	/*Array for storing processes numbers*/
	for(int i=0;i<n;++i)
	{
		printf("\nEnter Burst Time of %d Process: ",i+1);
		scanf("%d",&burst[i]);
		p_no[i]=i+1;
	}
	
	burst_sort(burst,p_no,n);
	int total_wait=wait_calc(wait,burst,n);
	int total_turn=turn_time(turn,burst,wait,n);
	
	printf("\n\nJob\t    Burst Time\t   Waiting Time \tTurnaround Time");
	for(int i=0;i<n;++i)
		printf("\n%d\t\t%d\t\t%d\t\t\t%d",p_no[i],burst[i],wait[i],turn[i]);

	float avg_wait=(float)total_wait/n;	/*Calculating average waiting time*/
	float avg_turn=(float)total_turn/n;	/*Calculating average turnaround time*/
	printf("\n\t\tAverage Waiting time is %f\n",avg_wait);
	printf("\t\tAverage turn around time is %f\n",avg_turn);
	printf("--------------------------------\n");
	
	return 0;
}
