#include <stdio.h>
int main()
{
	int a=0,sum=0;
	int n;
	printf("enter the number of series you want");
	scanf("%d", &n);
	int i=0;
	for(i=1;i<n;i++)
	{
		sum=a+i;
		a=sum;
		printf("%d\n", sum);
	}
	return 0;
}
