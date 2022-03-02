/**
 * @file
 * @brief Program to perform [dutch national
 * flag](https://en.wikipedia.org/wiki/Dutch_national_flag_problem) of a target
 * value in a given {0, 1, 2} containing array.
 * @author [Bijan Riesenberg](https://github.com/Data-Hero) Iterative
 */
#include <inttypes.h>   /// for the 8 bit sized int8_t type
#include <stdio.h>      /// for IO operations
#include <stdlib.h>     /// for memory allocation
#include <assert.h>     /// for assert

/**
 * @brief Dutch National Flag 3-Way inplace sort algorithm
 * @param arr array containting elements from {0, 1, 2} to be sorted
 * @param size size of the array
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
            arr[mid] = arr[high];
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
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    int size = 6;
    int8_t *arr1 = (int8_t *)malloc(sizeof(int8_t) * size);
    arr1[0] = 1, arr1[1] = 1, arr1[2] = 1, arr1[3] = 2, arr1[4] = 1,
    arr1[5] = 0;
    dnfSort(arr1, size);
    int8_t compare1[] = {0, 1, 1, 1, 1, 2};
    for (int c = 0; c < size; c++)
    {
        assert(arr1[c] == compare1[c]);
    }
    free(arr1);

    size = 1;
    int8_t *arr2 = (int8_t *)malloc(sizeof(int8_t) * size);
    arr2[0] = 2;
    dnfSort(arr2, size);
    int8_t compare2[] = {2};
    for (int c = 0; c < size; c++)
    {
        assert(arr2[c] == compare2[c]);
    }
    free(arr2);
}

/**
 * @brief Main Functiuon that reads an array of {0, 1, 2} and use the
 * Dutch National Flag 3-Way sort algorithm to sort
 *
 * @return int 0 if successful 1 if input is not in {0, 1, 2}
 */
int main(void)
{
    test();
    int size = 0;
    printf("Enter size of the array:\n");
    scanf("%d", &size);  // E.g. 8

    printf("Enter the elements in {0, 1, 2} of the array\n");
    int i;
    int8_t *arr = (int8_t *)malloc(sizeof(int8_t) * size);
    for (i = 0; i < size; i++)
    {
        scanf("%" SCNi8, &arr[i]);
        if (arr[i] > 2 || arr[i] < 0)
        {
            printf("Elements need to be in {0, 1, 2}");
            free(arr);
            return 1;
        }
    }
    printf("Original: \n");
    printArray(arr, size);
    dnfSort(arr, size);
    printf("Sorted: \n");
    printArray(arr, size);

    free(arr);
    return 0;
}
