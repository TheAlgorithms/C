#include <stdio.h>

int is_palindromic(unsigned int n)
{
    unsigned int reversed = 0, t = n;

    while (t>0)
    {
        reversed = 10 * reversed + (t % 10);
        t /= 10;
    }
    return reversed == n;
}

int main(void)
{
    unsigned int i, j, max = 0;
    for (i = 100; i <= 999; i++)
    {
        for (j = 100; j <= 999; j++)
        {
            unsigned int p = i * j;
            if (is_palindromic(p) && p > max)
            {
                max = p;
            }
        }
    }
    printf("%u\n", max);
    return 0;
}
