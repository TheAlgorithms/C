#include <stdio.h>
int kadane(int arr[], int size)
{
    if (arr == NULL)
        return 0;

    int sum = 0;
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        max = (max > sum) ? max : sum;
        if (sum < 0)
            sum = 0;
    }

    return max;
}

int main()
{
    printf("Enter the size of array: ");
    int size;
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    int result = kadane(arr, size);
    printf("Subarray with maximum sum: %d\n", result);

    return 0;
}
