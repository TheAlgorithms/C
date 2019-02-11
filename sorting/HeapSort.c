#include <stdio.h>

void heapify(int *unsorted, int index, int heap_size);
void heap_sort(int *unsorted, int n);

int main() {
	int n = 0;
	int i = 0;
	char oper;

	int* unsorted;
	printf("Enter the size of the array you want\n");
	scanf("%d", &n);
	unsorted = (int*)malloc(sizeof(int) * n);
	while (getchar() != '\n');
	printf("Enter numbers separated by a comma:\n");
	while (i != n) {
		scanf("%d,", (unsorted + i));
		i++;
	}
	heap_sort(unsorted, n);

	printf("[");
	printf("%d", *(unsorted));
	for (int i = 1; i < n; i++) {
		printf(", %d", *(unsorted + i));
	}
	printf("]");
}

void heapify(int *unsorted, int index, int heap_size) {
	int temp;
	int largest = index;
	int left_index = 2 * index;
	int right_index = 2 * index + 1;
	if (left_index < heap_size && *(unsorted + left_index) > *(unsorted + largest)) {
		largest = left_index;
	}
	if (right_index < heap_size && *(unsorted + right_index) > *(unsorted + largest)) {
		largest = right_index;
	}

	if (largest != index) {
		temp = *(unsorted + largest);
		*(unsorted + largest) = *(unsorted + index);
		*(unsorted + index) = temp;
		heapify(unsorted, largest, heap_size);
	}
}

void heap_sort(int *unsorted, int n) {
	int temp;
	for (int i = n / 2 - 1; i > -1; i--) {
		heapify(unsorted, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		temp = *(unsorted);
		*(unsorted) = *(unsorted + i);
		*(unsorted + i) = temp;
		heapify(unsorted, 0, i);
	}
}
