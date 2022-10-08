#include <stdio.h>
#include <math.h>

int digcount(int);
int arm(int,int);
int main() 
{
	int n;
	printf("Enter a no.\n");
	scanf("%d",&n);
	if(arm(n,digcount(n)) == n)
	    printf("%d is Armstrong\n",n);
	else
	    printf("%d is not Armstrong\n",n);
}
int digcount(int a)
{
    if(a == 0)
        return 0;
    else
        return digcount(a/10) + 1;
}
int arm(int a,int l)
{
    if(a == 0)
        return 0;
    else
        return (pow(a%10,l) + arm(a/10,l)) ;
}