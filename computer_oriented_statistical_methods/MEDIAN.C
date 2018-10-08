#include<stdio.h>
//#include<conio.h>
#include<math.h>

void main()
{
	int a[10],n,i,j,temp;
	float mean,median;
	clrscr();
	printf("Enter no. for Random Numbers :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	printf("Random Numbers Generated are :\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
	printf("\n");
	printf("\nSorted Data:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}

	if(n%2==0)
	{
		median=(a[n/2]+a[(n/2)-1])/2;
	}
	else
	{
		median=a[n/2];
	}
	printf("\nMedian is : %f",median);
	getch();
}
