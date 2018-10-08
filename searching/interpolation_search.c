#include<stdio.h>
int interpolationSearch(int arr[], int n, int x)
{ 
    int q=NULL;
    while(q<n)
    {
     if(arr[q]==x)
     return q;
     q++;
    }
    return -1;
}
 

int main()
{
    // Array of items on which search will
    // be conducted.
    int x;
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
                  24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]); //To get length of an array
    
    printf("Enter the no, to be searched");
    scanf("%d",&x); // Element to be searched
    
    int index = interpolationSearch(arr, n, x);
 
    // If element was found
    if (index != -1)
        printf("Element found at position %d", index+1);
    else
        printf("Element not found.");
    return 0;
}
