#include<stdio.h>
int UbiquitousBinarySearch(int A[], int lt, int rt, int key)
{
	int m;

	while( rt - lt > 1 )
	{
		m = lt + (rt-lt)/2;

		if( A[m] <= key )
			lt = m;
		else
			rt = m;
	}

	if( A[lt] == key )
		return lt;
	if( A[rt] == key )
		return rt;
	else
		return -1;
}
int main()
{
    int l, r, p, key;

    // Get the array
    // Sort the array if not sorted
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Starting index
    l = 0;
    // length of array
    r = 9;
    key = 4;
    // Search the key using ternarySearch
    p = UbiquitousBinarySearch(arr,l,r,key);

    // Print the result
    printf("Index of %d is %d\n", key, p);

}
