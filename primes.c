#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void primes(bool * primeList, int len) {
	int i, j;

	// Initiallize the list
	for (i = 0; i < len; i++) {
		primeList[i] = true;
	}
	primeList[0] = false; // 0 is not prime
	primeList[1] = false; // 1 is not prime

	for (i = 0; i < len; i++) {
		if (primeList[i] == true) {
			for (j = i*i; j < len; j = j+i) {
				primeList[j] = false;
			}
		}
	}
}

int main(void) {
	int size, i;
	bool * list;

	// Ask for the largest value to check primeness
	printf("Maximum value: ");
	scanf("%d", &size);

	// Allocate list to act as prime mask
	list = malloc(sizeof(bool) * size);

	// Populate list
	primes(list, size);

	// Print prime numbers
	for (i = 0; i < size; i++) {
		if (list[i] == true) {
			printf("%d\n", i);
		}
	}

	return 0;
}
