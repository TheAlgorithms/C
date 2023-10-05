#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// finds factorial of a given inegral input. Assumes 0!=1.
int factorial(int n)
{
    if (n == 0)
    {
        return 1; // base case
    }
    return n * factorial(n - 1); // based on the fact that n*(n-1)! = n!
}

bool check_arrays(int *a, int *b, int pos)
{
    if (factorial(a[pos]) == b[pos])
        return true;
    else
        return false;
}

static void tests()
{
    /* tests have a few integral factorials*/
    int tests[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int expected[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};

    for (int i = 0; i < 11; i++)
    {
        assert(check_arrays(tests, expected, i) == true);
    }
    printf("All test cases passed !\n");
}

int main()
{
    tests();
    return 0;
}