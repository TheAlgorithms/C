#include <stdio.h>

// Function to find the missing number
int getMissingNo(int a[], int n)
{
    int i;

    // For xor of all the elements in array
    int x1 = a[0];

    // For xor of all the elements from 1 to n+1
    int x2 = 1;

    for (i = 1; i < n; i++) x1 = x1 ^ a[i];

    for (i = 2; i <= n + 1; i++) x2 = x2 ^ i;

    return (x1 ^ x2);
}

// Driver code
void main()
{
    int arr[] = {1, 2, 3, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int miss = getMissingNo(arr, N);
    printf("%d", miss);
}
