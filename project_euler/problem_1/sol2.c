/*
If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3,5,6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below N.
'''
'''
This solution is based on the pattern that the successive numbers in the series follow: 0+3,+2,+1,+3,+1,+2,+3.
*/
#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;
	scanf("%d", &n);

	int terms = (n - 1) / 3;
	sum += ((terms)*(6 + (terms - 1) * 3)) / 2; //sum of an A.P.
	terms = (n - 1) / 5;
	sum += ((terms)*(10 + (terms - 1) * 5)) / 2;
	terms = (n - 1) / 15;
	sum -= ((terms)*(30 + (terms - 1) * 15)) / 2;

	printf("%d\n", sum);
}