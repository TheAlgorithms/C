#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void shakersort(int *a, int n)
{
    int p, i;
    for (p = 1; p <= n / 2; p++)
    {
        for (i = p - 1; i < n - p; i++)
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
            }
        for (i = n - p - 1; i >= p; i--)
            if (a[i] < a[i - 1])
            {
                swap(&a[i], &a[i - 1]);
            }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) scanf("%d ", &arr[i]);
    shakersort(arr, n);
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    free(arr);
    return 0;
}
