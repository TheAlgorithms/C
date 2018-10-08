/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int a = 0; a < n; a++) {
		if ((a % 3 == 0) || (a % 5 == 0)) {
			sum += a;
		}
	}

	printf("%d\n", sum);
}