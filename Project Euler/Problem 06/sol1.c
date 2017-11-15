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
    long suma=0,sumb=0,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        suma += i*i;
        sumb += i;
    }
    sum = (sumb*sumb) - suma;
    printf("%ld\n",sum);
    return 0;
}
