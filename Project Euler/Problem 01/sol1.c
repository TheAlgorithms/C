/*
Problem Statement:
If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3,5,6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below N.
*/
#include <stdio.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=3;i<n;i++)
    {
        if((i%3==0) || (i%5==0))
            sum += i;
    }
    printf("%d\n",sum);
    return 0;
}
