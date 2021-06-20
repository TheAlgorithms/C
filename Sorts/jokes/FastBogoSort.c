#include <stdlib.h> /* abort(), size_t */
#include <math.h> /* log() */

/* see: https://xkcd.com/1185/ */

/* function borrowed from BogoSort.c */
void shuffle(int *a, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }
}

int* FastBogoSort(int arr[], size_t size)
{
    for(int i = 0; i < log(size); i++)
    {
        shuffle(arr, size);
        
        /* check if the array is sorted */
        for(int i = 1; i<size;i++)
        {
            if(arr[i] < arr[0]) break;
        }
        
        if (i == size) return arr;
        
    }
    
    abort();
}