#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/* 
Miracle Sort assumes that cosmic rays, bit rot, and miracles will 
eventually cause the array to become sorted. If it is sorted, return it.
Otherwise, allow time for miracles to occur and check again.
*/

int* MiracleSort( int arr[], size_t size)
{
    while(True)
    {
        // check if the array is sorted
        for(int i = 1; i<size;i++)
        {
            if(arr[i] < arr[0]) break;
        }
        
        if (i == size) 
        {
            // array completed without breaking.
            // therefore, it is properly sorted
            return arr;
        }
        
        sleep(1); // Allow time for miracles to occur
    }
}