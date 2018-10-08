/*
Problem:
The prime factors of 13195 are 5,7,13 and 29. What is the largest prime factor of a given number N?
e.g. for 10, largest prime factor = 5. For 17, largest prime factor = 17.
*/
#include <stdio.h>
#include <math.h>

int isprime(int no) {
	int sq;

	if (no == 2) {
		return 1;
	}
	else if (no%2 == 0) {
		return 0;
	}
	sq = ((int)(sqrt(no))) + 1;
	for (int i = 3; i < sq; i + 2) {
		if (no%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int maxNumber = 0;
	int n = 0;
	int n1;
	scanf("%d", &n);
	if (isprime(n) == 1)
		printf("%d", n);
	else {
		while (n % 2 == 0) {
			n = n / 2;
		}
		if (isprime(n) == 1) {
			printf("%d\n", n);
		}
		else {
			n1 = ((int)(sqrt(n))) + 1;
			for (int i = 3; i < n1; i + 2) {
				if (n%i == 0) {
					if (isprime((int)(n / i)) == 1) {
						maxNumber = n / i;
						break;
					}
					else if (isprime(i) == 1) {
						maxNumber = i;
					}
				}
			}
			printf("%d\n", maxNumber);
		}
	}
}