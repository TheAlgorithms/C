#include <stdio.h>
#include <stdlib.h>

int linearsearch(int* arr, int size, int val)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

int main()
{
    int n, i, v, show_idx;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);  // Taking input for the size of Array

    int* a = (int*)malloc(n * sizeof(int));
    printf("Enter the contents for an array of size %d:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);  // accepts the values of array elements until the
                             // loop terminates//

    printf("Enter the value to be searched:\n");
    scanf("%d", &v);  // Taking input the value to be searched

    printf("Enter 1 if you want to see the index and 0 if otherwise:\n");
    scanf("%d", &show_idx);

    int res = linearsearch(a, n, v);

    if (show_idx)
    {
        if (res != -1)
            printf("Element found at index: %d\n", res);
        else
            printf("Element not found in the array.\n");
        free(a);
        return 0;
    }

    if (res != -1)
        printf("Value %d is in the array.\n", v);
    else
        printf("Value %d is not in the array.\n", v);

    free(a);
    return 0;
}
