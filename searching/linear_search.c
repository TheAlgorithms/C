#include <stdio.h>
#include <stdlib.h>

int linearsearch(int *arr, int size, int val)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return 0;
}

int main()
{
    int n, i, v, r;
    printf("Enter the size of the array:\n");
    scanf("%d", &n); // Taking input for the size of Array

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the contents for an array of size %d:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]); // accepts the values of array elements until the
                            // loop terminates//

    printf("Enter the value to be searched:\n");
    scanf("%d", &v); // Taking input the value to be searched

    r = linearsearch(a, n, v);
    if (r != 0)
        printf("Value %d is in the array at index %d.\n", v, r);
    else
        printf("Value %d is not in the array.\n", v);

    free(a);
    return 0;
}
