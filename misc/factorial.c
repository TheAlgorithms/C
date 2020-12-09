#include<stdio.h>

int main()
{
	long long int n, factorial = 1;
	printf("Enter a whole number to Find its Factorial:\n");
	scanf("%lld",&n);
	
	if(n<0)
	{
		printf("Cannot Calculate factorials for negative numbers.");
	}
	else
	{
		for(int i=n; i>0 ;i--)
		{
			factorial = factorial * i;
		}
	}
	
	
	printf("%lld",factorial);
}
