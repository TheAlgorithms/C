//A number is called as Armstrong number if sum of cubes of digits of number is equal to the number itself.
// For Example 153 is an Armstrong number because 153 = 1³+5³+3³.
#include <stdio.h> 

//Function to calculate x raised to the power y
int power(int x, unsigned int y) 
{ 
	if (y == 0) 
		return 1; 
	if (y % 2 == 0) 
		return power(x, y / 2) * power(x, y / 2); 
	return x * power(x, y / 2) * power(x, y / 2); 
} 

//Function to calculate order of the number 
int order(int x) 
{ 
	int n = 0; 
	while (x) { 
		n++; 
		x = x / 10; 
	} 
	return n; 
} 

// Function to check whether the given number is 
// Armstrong number or not 
int isArmstrong(int x) 
{ 
	// Calling order function 
	int n = order(x); 
	int temp = x, sum = 0; 
	while (temp)
	{ 
		int r = temp % 10; 
		sum += power(r, n); 
		temp = temp / 10; 
	} 

	// If satisfies Armstrong condition 
	if (sum == x) 
		return 1; 
	else
		return 0; 
} 

//
int main() 
{ 
	int x = 153; 
	if (isArmstrong(x) == 1) 
		printf("True\n"); 
	else
		printf("False\n"); 

	x = 1253; 
	if (isArmstrong(x) == 1) 
		printf("True\n"); 
	else
		printf("False\n"); 

	return 0; 
} 

