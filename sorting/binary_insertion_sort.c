/*
Binary Insertion sort is a variant of Insertion sorting in which proper location to insert the selected element is found using the binary search.
*/

#include<stdio.h>

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;
 
    int mid = (low + high)/2;
 
    if(item == a[mid])
        return mid+1;
 
    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
 
// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}
 
int main()
{
    int n;
    scanf("%d",&n) ;
    int a[n],i;
    for(i = 0; i<n; i++)
    {
	scanf("%d",&a[i]);
    }
 
    insertionSort(a, n);
 
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ",a[i]);
 
    return 0;
}
