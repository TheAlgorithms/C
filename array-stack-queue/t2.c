#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
	if(b==0)
	   return a;
	if(a==0)
	   return b;
	else 
	   return gcd(b,a%b);
}

long int decToBin(unsigned int n)
{
	if(n==0)
	   return 0;
	else
	   return (n%2+10*decToBin(n/2));
}

int  TOH(int n,int s,int t,int d)
{
	if(n==0)
	   return 0;
	TOH(n-1,s,d,t);
	printf("Move disc %d from %c to %c\n",n,s,d);
	TOH(n-1,t,s,d);
}

int main()
{
	int a,b,n;
	unsigned int m;
	printf("Enter the two numbers to find gcd:");
	scanf("%d%d",&a,&b);
	printf("GCD of two numbers is:%d\n\n",gcd(a,b));
	printf("Enter the unsigned number to find its binary value:");
	scanf("%u",&m);
	printf("The binary value of the number is:%ld\n\n",decToBin(m));
	printf("Enter the no of discs for tower of hanoi:");
	scanf("%d",&n);
	TOH(n,'A','C','B');
}

	


