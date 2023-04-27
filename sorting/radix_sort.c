/**
 * @file
 * @brief C implementation of [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
 * @details
 * Readable version of radix sort, allowing user to input size of array (up to 10) and specify elements of unordered array.
 */

#include <stdio.h> /// for radix_sort() and main() - I/O operations

/**
 * @brief finds largest element in int array
 * @param a pointer to array of numbers
 * @param n size of a
 * @returns large - the largest number in the array
 */
int largest(int const a[], int n) {

    int large = a [0]; // sets largest number to first element in array
    for (int i = 1; i < n; i++) {
        if (large < a[i]) {
            large = a[i]; // if number found in array > largest, sets largest to that number
        }
    }

    return large;
}

/**
 * @brief radix_sort - takes in unordered array, sorts it, returns ordered array
 * @param a pointer to unordered array of numbers
 * @param n size of a (number of elements)
 * @returns void
 */
void radix_sort(int a[], int n) {

    int bucket[10][10]; // creates bucket for radix sort of decimal numbers
    int bucket_count[10]; // initialises counters (for number of elements) for 10 buckets
    int remainder; // remainder of division
    int NOP = 0; // number of passes of array that need to be made
    int large; // largest number
    int divisor = 1; // indicates which digit of number algorithm should work with

    large = largest(a,n); // finds largest number in array

    printf("The largest element: %d\n", large);

    while (large > 0) { // finds number of passes to make of array (number of passes = number of digits in largest number)
        NOP++;
        large /= 10;
    }

    for (int pass = 0; pass < NOP; pass++) {

        for (int i = 0; i < 10; i++) { // initialises each bucket count (number of elements in bucket) to 0
            bucket_count[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            remainder = (a[i] / divisor) % 10; // finds value of current digit of current number (e.g. if 657 and on 3rd pass, digit = 6)
            printf("%d ", remainder);
            bucket[remainder][bucket_count[remainder]] = a[i]; // stores number in appropriate bucket
            bucket_count[remainder] += 1; // increases bucket count (number of elements in bucket) by 1
        }

        int count = 0; // puts all elements back into original array
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < bucket_count[k]; j++) {
                a[count] = bucket[k][j];
                count ++;
            }
        }

        divisor *=10; // next pass will focus on next digit along

    }
}


/*
 * @brief Main Function
 * @returns 0 on exit
 */
int main() {

    int n; // size of a
    int a[10]; // array of size 10

    printf("Enter the number of elements: "); // up to 10
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    radix_sort(a, n);

    printf("The sorted elements are: "); // outputs sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;

}
