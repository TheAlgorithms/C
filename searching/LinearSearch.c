#include <stdio.h>

int linearSearch(int *arr, int size, int key){
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return 1;
		}
	}
	return 0;
}

int main(void) {
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);

	int array[size]; /* Variable Length Array (VLA) is available only in C99+ */
	printf("Enter the contents for an array of size %d:\n", size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}

	int key;
	printf("Enter the value to be searched: ");
	scanf("%d", &key);
	if (linearSearch(array, size, key)) {
		printf("Value %d is in the array\n", key);
	} else {
		printf("Value %d is not in the array.\n", key);
	}
}
