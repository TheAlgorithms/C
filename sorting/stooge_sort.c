#include <stdio.h>
void stoogesort(int[], int, int);

int main()
{
    int arr[100], i, n;

    printf("How many elements do you want to sort: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf(" %d", &arr[i]);
    stoogesort(arr, 0, n - 1);
    printf("Sorted array : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void stoogesort(int arr[], int i, int j)
{
    int temp, k;
    if (arr[i] > arr[j])
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    if ((i + 1) >= j)
        return;
    k = (int)((j - i + 1) / 3);
    stoogesort(arr, i, j - k);
    stoogesort(arr, i + k, j);
    stoogesort(arr, i, j - k);
}
