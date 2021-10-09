#include <stdio.h>
#include <stdlib.h>

//function to search element
int linearsearch(int *arr, int size, int val)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return 1;
    }
    
}

void main()
{
    int size, i, v;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);  //  the size of Array

    int *a = (int *)malloc(size * sizeof(int));
    printf("Enter the contents for an array of size %d:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);  // accepts the values of array elements until the
                             // loop terminates//

    printf("Enter the value to be searched:\n");
    scanf("%d", &v);  // Taking input the value to be searched
    if (linearsearch(a, size, v))
        printf("Value %d is in the array.\n", v);
    else
        printf("Value %d is not in the array.\n", v);

    free(a);
    
}
