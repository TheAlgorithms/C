/**
 * Modified on 07/12/2017, Kyler Smith
 *
 * A number is called strong number if sum of the 
 * 	factorial of its digit is equal to number itself.
 */

#include<stdio.h>


void strng(int a)
{
	int j=a;
	int sum=0;
	int b,i,fact=1;	
	while(a>0)
	{
		fact=1;
		b=a%10;
		for(i=1;i<=b;i++)
		{
			fact=fact*i;
		}
		a=a/10;
		sum=sum+fact;
	}
	if(sum==j)
	printf("%d is a strong number",j);
	else
	printf("%d is not a strong number",j);
}
void main()
{
	int a;
	printf("Enter the number to check");
	scanf("%d",&a);
	strng(a);
}
