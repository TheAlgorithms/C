/**
 * @file
 * @brief [Absolute value](https://en.wikipedia.org/wiki/Absolute_value)
 * algorithm implementation
 */
#include <assert.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Calculate the absolute value of given number
 * @param number given number to calculate
 * @return absolute value of given number
 */
int absVal(int number) { return number < 0 ? -number : number; }

/**
 * @brief Test function
 * @returns void
 */
void test()
{
    int n = rand() % 100; /* random times to test */
    for (int i = 1; i <= n; i++)
    {
        /* random number from -50 to 49 */
        int number = (rand() % 100) - 50;
        assert(abs(number) == absVal(number));
    }
}

/**
 * @brief Driver Code
 * @returns 0 on exit
 */
int main()
{
    /* Initialises random number generator */
    srand(time(NULL));
    test();
    return 0;
}
