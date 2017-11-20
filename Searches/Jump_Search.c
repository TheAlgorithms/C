#include <stdio.h>
#include <math.h>
#define min(X,Y) ((X) < (Y) ? (X) : (Y))  
int jump_search(int* arr, int x);
int n;

int main() {
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
	n = sizeof(arr) / sizeof(int);
	int x = 55;
	int index = jump_search(arr, x);
	printf("\nNumber %d is at index %d\n", x, index);
}

int jump_search(int* arr, int x) {
	int step = floor(sqrt(n));
	int prev = 0;
	while (*(arr + (min(step, n) - 1)) < x) {
		prev = step;
		step += floor(sqrt(n));
		if (prev >= n)
			return -1;
	}

	while (*(arr + prev) < x) {
		prev = prev + 1;
		if (prev == fmin(step, n))
			return -1;
	}
	if (*(arr + prev) == x)
		return prev;
	return -1;
}
