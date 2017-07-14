#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int a[10],n,i,j,temp;
	float q1,q3,iqr;
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
	q1=a[n/4];
	printf("\nFirst Quartile : %f",q1);
	q3=a[(3*n)/4];
	printf("\nThird Quartile : %f",q3);
	iqr=q3-q1;
	printf("\nInterQuartile Range is : %f",iqr);
	getch();
}