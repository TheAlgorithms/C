//To find the difference between the square of sum of first n natural numbers and sum of squares of first n natural number.
#include<stdio.h>
int main()
{
        int n;
        scanf("%d",&n);
        int answer=((n*(n+1))/2)*((n*(n+1))/2)-n*(n+1)*(2*n+1)/6;//1+2+3+...n=n*(n+1)/2     1^2+2^2+..n^2=n*(n+1)*(2n+1)/6
        printf("%d",answer);//to print the required result
}
