#include <stdio.h> 
#include <stdlib.h> 

// Function to display the array
void displayArray(int arr[], int n) 
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int fibMonaccianSearch(int arr[], int x, int n) 
{ 
    /* Initialize fibonacci numbers */ 
    int fibMMm2 = 0;               // (m-2)'th Fibonacci No. 
    int fibMMm1 = 1;               // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 
 
    /* fibM is going to store the smallest Fibonacci 
       Number greater than or equal to n */ 
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
    } 
 
    // Marks the eliminated range from front 
    int offset = -1; 
 
    /* while there are elements to be inspected. Note that 
       we compare arr[fibMm2] with x. When fibM becomes 1, 
       fibMm2 becomes 0 */ 
    while (fibM > 1) 
    { 
        // Check if fibMm2 is a valid location 
 
        // sets i to the min. of (offset+fibMMm2) and (n-1) 
        int i = ((offset + fibMMm2) < (n - 1)) ? (offset + fibMMm2) : (n - 1); 
 
        /* If
