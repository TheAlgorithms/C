#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int a[10],n,i,j,temp,sum=0;
	float mean,var,stand;
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
		sum=sum+a[i];
	}
	mean=sum/(float)n;
	printf("\nMean :");
	printf("%f",mean);
	printf("\n");
	for(i=0;i<n;i++)
	{
		sum=sum+(pow((a[i]-mean),2));
	}
	var=sum/(float)n;
	printf("\nVariance is : %f",var);
	printf("\n");
	stand=sqrt(var);
	printf("\nStandard Deviation is : %f",stand);
	getch();
}



