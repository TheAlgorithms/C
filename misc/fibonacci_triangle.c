/**
 * @file
 * @brief using fibonacci series we can print triangle of numbers
 *
 * @author [Sumeet Shinde](https://github.com/sumeet-shinde)
 */
#include <stdio.h>   /// for standard Input Output 
#include <stdlib.h>  /// for standard library functions
#include <assert.h>  /// for assert functions
#include <stdbool.h> /// for boolean functions
/**
 * @brief Function to print Fibonacci series in triangle format
 * @param [in] n index of Fibonacci number to get
 */
bool fibo(int n)
{
	int i = 0, j = 0, a = 0, b = 0, c = 0;
	for(i=1;i<=n;i++)
	{
		a=0; //initialize first number
		b=1; //initialize second number
		printf("%d\t",b);
		for(j=1;j<i;j++) //printing series in loop till n
		{
			c=a+b;
			printf("%d\t",c); 
			a=b;
			b=c;
		}
		printf("\n"); //next line after every series till n
	}
	return -1;
}
/**
 * Test implementations
 * @returns void
 */
static void test()
{
	assert(fibo(5)); //giving value of n to test
}
/**
 * @brief Driver Code
 * @returns 0 on exit
 */
int main()
{
	test(); // execute the tests
	return 0;
}
