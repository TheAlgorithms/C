#include <stdio.h>
#include <math.h>

void main()
{
	int rem, temp, num;
	// Taking large value for i and sum
	long int i = 1, sum = 0;

	// Asking for the number from user
	printf("Enter any number");
	scanf("%d" , &num);

	temp = num;
	while(temp>0)
	{
		rem = num%2;
		temp = num/2;
		num = temp;
		// Taking the number as a sum in an integer.
		sum = sum + (rem*i);
		 i  = i*10;
	} 

	// Printing the desired value as sum.
	printf("%ld" , sum);
}
