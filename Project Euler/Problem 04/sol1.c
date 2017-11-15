/*
Problem:
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
*/
#include <math.h>
#include <stdio.h>
int palindrome(int n)
{
    int rev=0,temp=n;
    while(n)
        {
        rev*=10;
        rev+=n%10;
        n/=10;
    }
    if(rev==temp) return 1;
    else return 0;
}
int main()
{
    int n,j;
    scanf("%d",&n);
    for(int i=n-1;i>10000;i--)
    {
        if(palindrome(i))
            {
                j=999;
                while(j!=99)
                {
                    if((i%j==0) && ((i/j)<1000) && ((i/j)>99))
                    {
                        printf("%d\n",i);
                        return;
                    }
                    j--;
                }
            }
    }
}
