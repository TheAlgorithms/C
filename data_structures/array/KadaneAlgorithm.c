#include <stdio.h>
#include <limits.h>
int main() {
        int arr []={-1,-2,3,-4};
        size_t n = sizeof(arr)/sizeof(arr[0]);
        int max=0,curr=0,neg=INT_MIN;
        for (int i=0;i<n;i++) {
            curr += arr[i];
            if (curr > max)
                max = curr;
            else if (curr < 0)
                curr = 0;
            if(neg<arr[i])
                neg=arr[i];
        }
        if(neg>0)
          printf("%d",max);
        else
           printf("%d",neg);
    
    return 0;
}
