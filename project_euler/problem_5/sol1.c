#include <stdio.h>
#include <stdlib.h>

// Pretty naive implementation
// Just checks every number if it's devisable by 1 through 20

static int check_number(unsigned long long n)
{
    for (unsigned long long i = 1; i <= 20; ++i)
    {
        if (n % i != 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    for (unsigned long long n = 1;; ++n)
    {
        if (check_number(n))
        {
            printf("Result: %llu\n", n);
            break;
        }
    }
}
