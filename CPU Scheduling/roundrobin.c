#include<stdio.h>
struct process
{
	int at,bt,ct,wt,tt,rt, name;
	int completed;
}p[10];

int n;
int q[10];  //queue
int front=-1,rear=-1;
void enqueue(int i)
{
    if(rear==10)
        printf("overflow");
    rear++;
    q[rear]=i;
    if(front==-1)
        front=0;

}

int dequeue()
{
    if(front==-1)
        printf("underflow");
    int temp=q[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return temp;
}
int isInQueue(int i)
{
    int k;
    for(k=front;k<=rear;k++)
    {
        if(q[k]==i)
        return 1;
    }
    return 0;
}

void sortByArrival()
{
    struct process temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

void main()
{
    int i,j,time=0,sum_bt=0,tq,c;
    float avgtt=0,avgwt=0;
     printf("\n Enter Number of Processes:");
     scanf("%d",&n);
     for(i=0,c=1;i<n;i++,c++)
     {
        printf(" Enter the Process Id:");
        scanf(" %d:",&p[i].name);
        printf(" Enter the arrival time:");
        scanf(" %d",&p[i].at);
        printf(" Enter the burst time:");
        scanf(" %d",&p[i].bt);
        p[i].rt=p[i].bt;
        p[i].completed=0;
        sum_bt+=p[i].bt;
    }
    printf("\n Enter the time quantum:");
    scanf(" %d",&tq);
    sortByArrival();
    enqueue(0);          // enqueue the first process
    printf("\n Process execution order: ");
    for(time=p[0].at;time<sum_bt;)       // run until the total burst time reached
    {
        i=dequeue();
        if(p[i].rt<=tq)
        {                          /* for processes having remaining time with less than                                             or  equal  to time quantum  */

            time+=p[i].rt;
            p[i].rt=0;
            p[i].completed=1;
            printf(" %d ",p[i].name);
            p[i].ct=time;
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;
            for(j=0;j<n;j++)     /*enqueue the processes which have come while scheduling */
            {
                if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
                {
                    enqueue(j);
                }
            }
        }
        else               // more than time quantum
        {
            time+=tq;
            p[i].rt-=tq;
            printf(" %d ",p[i].name);
            for(j=0;j<n;j++)    /*first enqueue the processes which have come while                                             scheduling */
            {
                if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
                {
                    enqueue(j);
                }
            }
            enqueue(i);   // then enqueue the uncompleted process
        }
    }

    printf("\n Process Id\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time");
    for(i=0;i<n;i++)
    {
        avgwt+=p[i].wt;
        avgtt+=p[i].tt;
        printf("\n %d\t\t%d\t\t%d\t\t %d\t\t %d\t\t %d",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    }
    printf("\n Average waiting time:%f\n",avgwt/n);
    printf("\n Average Turnaround time:%f\n",avgtt/n);
}
