#include <stdio.h>
#include "swap.h"
#define range 10

void countsort(int arr[],int n,int place)
{
        int i,freq[range]={0};         //range for integers is 10 as digits range from 0-9
        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}
void radixsort(int arr[],int n,int maxx)            //maxx is the maximum element in the array
{
        int mul=1;
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
}

int main(){
    int size = 8, ar[] = {1,3,2,7,6,4,3,12};
    int max = MAX(ar, size);
    radixsort(ar, size, max);
    int i;
    for(i = 0; i<size; i++)
        printf("%d ", ar[i]);

    return 0;


}
