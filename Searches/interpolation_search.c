
int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
       
        int pos = lo + (((double)(hi-lo) /
              (arr[hi]-arr[lo]))*(x - arr[lo]));
 
       
        if (arr[pos] == x)
            return pos;
 
        
        if (arr[pos] < x)
            lo = pos + 1;
 
        else
            hi = pos - 1;
    }
    return -1;
}
 

int main()
{
    // Array of items on which search will
    // be conducted.
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
                  24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    int x = 18; // Element to be searched
    int index = interpolationSearch(arr, n, x);
 
    // If element was found
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found.");
    return 0;
}
