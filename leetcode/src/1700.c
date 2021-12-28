#include<stdio.h>
int rear=-1,front=-1,size=50,queue[50],count=0;
void enqueue(int ele)
{
	if(rear==size-1)
		printf("Overflow");
	else
	{
		rear++;
		queue[rear]=ele;
	}
}
int dequeue()
{
	int ele;
	if(front==size-1)
		printf("Underflow");
	else
	{
		front++;
		ele=queue[front];
		return ele;
	}
}
int main()
{
	int sand[50],stud[50],n;
	printf("Enter the number of students and sandwiches: ");
	scanf("%d",&n);
	printf("Enter the students choice: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&stud[i]);
		enqueue(stud[i]);
	}
	printf("Enter the sandwiches list: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&sand[i]);
	}
	int i=0;
	for(int j=0;j<2*n;j++)
	{
		int el=dequeue();
		if(el==sand[i])
		{

			i++;
			count++;
		}
		else
		{
			enqueue(el);
		}
		if(count==n)
		break;
	}
		printf("%d",n-count);

	return 0;
}
