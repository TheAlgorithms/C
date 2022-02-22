/**
 * @file
 * @brief Program to perform [dutch national
 * flag](https://en.wikipedia.org/wiki/Dutch_national_flag_problem) of a target
 * value in a given {0, 1, 2} containing array.
 * @authors [Bijan Riesenberg](https://github.com/Data-Hero) Iterative
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Dutch National Flag 3-Way sort algorithm
 * @param arr array containting elements from {0, 1, 2} to be sorted
 * @param size size of the array
 * @returns void
 */
void dnfSort(int8_t *arr, int size)
{
    int low = 0, mid = 0, high = size - 1;
    int8_t temp = 0;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            temp = arr[low];
            arr[low++] = arr[mid];
            arr[mid++] = temp;
            break;
        case 1:
            ++mid;
            break;
        case 2:
            temp = arr[mid];
            arr[mid++] = arr[high];
            arr[high--] = temp;
            break;
        default:
            break;
        }
    }
}

/**
 * @brief Print an array containing int8_t elements
 *
 * @param arr array containting elements from {0, 1, 2} (int8_t) to be printed
 * @param size size of the array
 */
void printArray(int8_t *arr, int size)
{
    for (int c = 0; c < size; c++)
    {
        c != size - 1 ? printf("%" PRIi8 ", ", arr[c])
                      : printf("%" PRIi8 "\n", arr[c]);
    }
}

/**
 * @brief input an array of {0, 1, 2} and use the
 * Dutch National Flag 3-Way sort algorithm to sort
 *
 * @return int 0 if successful 1 if input is not in {0, 1, 2}
 */
int main(void)
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 8

    printf("Enter the elements in {0, 1, 2} of the array\n");
    int i;
    int8_t *arr = (int8_t *)malloc(sizeof(int8_t) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%" SCNi8, &arr[i]);
        if (arr[i] > 2 || arr[i] < 0)
        {
            printf("Elements need to be in {0, 1, 2}");
            return 1;
        }
    }
    printf("Original array: \n");
    printArray(arr, n);
    dnfSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    free(arr);
    return 0;
}
