#ifdef _WIN32
#include <Windows.h> /* sleep()  - Windows */
#else
#include <unistd.h> /* sleep() - UNIX */
#endif
#include<stddef.h> /* size_t */
#include <stdbool.h> /* true, false */

/* 
Miracle Sort assumes that cosmic rays, bit rot, and miracles will 
eventually cause the array to become sorted. If it is sorted, return it.
Otherwise, allow time for miracles to occur and check again.
*/

/* borrowed from BogoSort.c */
bool check_sorted(int *a, int n)
{
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}

int* MiracleSort( int arr[], size_t size)
{
    while(1)
    {
        if(check_sorted(arr, size)) return arr;
        
        sleep(1); // Allow time for miracles to occur
    }
}