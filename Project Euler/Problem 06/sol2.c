/*
Problem:
The sum of the squares of the first ten natural numbers is,
            1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
            (1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first N natural numbers and the square of the sum.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    long suma, sumb, sum;
    suma = n*(n+1)/2;
    sumb = n*(n+1)*(2*n+1)/6;
    sum = (suma*suma) - sumb;
    printf("%d",sum);
    return 0;
}
