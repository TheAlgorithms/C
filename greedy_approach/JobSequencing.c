#include<stdio.h>

struct Jobs
{
    float profit;
    int deadline;
    int id;
};

void jobSequencing(int n, struct Jobs job_details[100])
{
    float total_profit = 0;
    int i, j, tempindex, job_sequence[n], max_deadline, count = 0;
    struct Jobs temp;    
    max_deadline = job_details[0].deadline;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(job_details[j].profit < job_details[j+1].profit)
            {
                temp = job_details[j];
                job_details[j] = job_details[j+1];
                job_details[j+1] = temp;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        job_sequence[i] = 0;
        if(job_details[i].deadline > max_deadline)
        {
            max_deadline = job_details[i].deadline;
        }
    }
    
    for(i=0; count != max_deadline; i++)
    {
        tempindex = job_details[i].deadline;
        for(j=tempindex-1; j>=0; j--)
        {
            if(job_sequence[j] == 0)
            {
                job_sequence[j] = job_details[i].id;
                total_profit = total_profit + job_details[i].profit;
                count ++;
                break;
            }
        }
    }
    printf("\nJobs to be done are : ");
    for (i=0; i<max_deadline; i++)
    {
        printf("J%d   ", job_sequence[i]);
    }
    printf("\n\nTotal profit is %f\n\n", total_profit);
}

void main()
{
    int n, i, j;
    struct Jobs job_details[100];
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        job_details[i].id = i+1;

        printf("\nEnter profit for job %d: ", i+1);
        scanf("%f", &job_details[i].profit);

        printf("Enter deadline for job %d: ", i+1);
        scanf("%d", &job_details[i].deadline);
    }
    jobSequencing(n, job_details);
}