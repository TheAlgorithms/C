#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int number_of_prime = 0;
    for (int i = 2;; i++)
    {
        int divisors = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                divisors++;
            }
        }
        if (divisors == 2)
        {
            number_of_prime++;
            if (number_of_prime == n)
            {
                printf("%d", i);
                break;
            }
        }
    }
}
