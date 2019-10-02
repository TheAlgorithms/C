#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
	int n,i;
	
	printf("ENTER THE N");
	scanf("%d" ,&n);
	int fib[n];
	fib[0]=1;
	fib[1]=1;
	//printf("%d  ",fib[0]);
	//printf("%d  ",fib[1]);
	for(i=2;i<n;i++)   
		{
		fib[i]=fib[i-1]+fib[i-2];
	}
	printf("%d  ",fib[n-1]);	
	
}
