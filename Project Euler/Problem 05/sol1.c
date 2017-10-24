/*
Problem:
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
*/
#include <math.h>
#include <stdio.h>

int main()
{
    int i=0,nfound=0,n;
    scanf("%d",&n);
    while(1)
    {
        i+=n*(n-1);
        nfound=0;
        for(int j=2;j<n;j++)
        {
            if(i%j!=0)
            {
                nfound=1;
                break;
            }
        }
        if(nfound==0)
            {
            if(i==0) i=1;
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
