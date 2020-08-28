#include <stdio.h>
#include <stdlib.h>

// Little bit improved version of the naive `sol1.c`
// Since the number has to be divisable by 20, we can start at 20 and go in 20
// steps. Also we don't have to check against any number, since most of them are
// implied by other divisions (i.e. if a number is divisable by 20, it's also
// divisable by 2, 5, and 10)
//
// This all gives a 97% perfomance increase on my machine (9.562 vs 0.257)

static unsigned int divisors[] = {
    11, 13, 14, 16, 17, 18, 19, 20,
};

static int check_number(unsigned long long n)
{
    for (size_t i = 0; i < 7; ++i)
    {
        if (n % divisors[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    for (unsigned long long n = 20;; n += 20)
    {
        if (check_number(n))
        {
            printf("Result: %llu\n", n);
            break;
        }
    }
}
