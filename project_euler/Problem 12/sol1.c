#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long count_divisors(long long n)
/*
    If x = a * b, then both a and b are divisors of x.
    Since multiplication is commutative, we only need to search
    till a maximum of a=b = a^2 i.e., till sqrt(x).
    At every integer till then, there are eaxctly 2 divisors
    and at a=b, there is only one divisor.
*/
{
    long num_divisors = 0;
    
    for (long long i = 1; i < sqrtl(n) + 1; i++)
        if (n % i == 0)
            num_divisors += 2;
        else if (i * i == n)
            num_divisors += 1;

    return num_divisors;
}

int main(int argc, char **argv)
{
    int MAX_DIVISORS = 500;
    long i = 1, num_divisors;
    long long triangle_number = 1;

    if (argc == 2)
        MAX_DIVISORS = atoi(argv[1]);

    while(1)
    {
        i++;
        triangle_number += i;
        num_divisors = count_divisors(triangle_number);
        if (num_divisors > MAX_DIVISORS)
            break;
    }

    printf("First Triangle number with more than %d divisors: %lld\n", MAX_DIVISORS, triangle_number);

    return 0;
}