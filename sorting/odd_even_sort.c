#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/*Displays the array, passed to this method*/
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/**
 * Swapped two numbers using pointer
 * @param first first pointer of first number
 * @param second second pointer of second number
 */
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
  
/**
 * ODD-EVEN sort algorithm implements
 * @param arr array to be sorted
 * @param size size of array
 */
void oddEvenSort(int arr[], int n) 
{ 
    bool isSorted = false; 
  
    while (!isSorted) 
    { 
        isSorted = true; 
        for (int i=1; i<=n-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
             { 
                swap(&arr[i], &arr[i+1]); 
                isSorted = false; 
              } 
        } 
  
        for (int i=0; i<=n-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
            { 
                swap(&arr[i], &arr[i+1]); 
                isSorted = false; 
            } 
        } 
    } 
  
    return; 
} 
 
/** Driver Code */
int main() 
{ 
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 5

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);  // show array before sorting

  
    oddEvenSort(arr, n); //Call sorting function
    display(arr, n); // show array after sorting
  
    return (0); 
} 