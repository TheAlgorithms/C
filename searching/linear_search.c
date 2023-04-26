/**
 * @file
 * @brief C implementation of [Linear Search](https://en.wikipedia.org/wiki/Linear_search)
 * @details
 * Takes array (and its size) as input and value to search for.
 * Checks if value is in array.
 */

#include <stdio.h> /// for main() I/O operations
#include <stdlib.h> /// for main() dynamic memory allocation (malloc)

/**
 * @brief checks if value in array by comparing value to each element of array
 * @param arr pointer to array to be searched
 * @param size size of array
 * @param val value to search for
 * @returns 1 if value in array
 * @returns 0 if value not in array
 */
int linear_search(const int *arr, int size, int val) {

    for (int i=0; i < size; i++) {
        if (arr[i] == val)
            return 1;
    }

    return 0;
}


/**
 * @brief Main Function
 * @returns 0 on exit
 */
int main() {

    int n, v; // n is size of array, v is value to search for
    printf("Enter the size of the array:\n");
    scanf("%d", &n); // takes input - size of array

    int *a = (int *)malloc(n * sizeof(int)); // allocates memory for array
    printf("Enter the contents for an array of size %d:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // accepts the values of array elements until the loop terminates
    }

    printf("Enter the value to be searched: \n");
    scanf("%d", &v); // takes input - value to search for)

    if (linear_search(a, n, v)) {
        printf("Value %d is in the array.\n", v);
    }
    else {
        printf("Value %d is not in the array.\n", v);
    }

    free(a);
    return 0;
}
