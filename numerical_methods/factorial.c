/**
 * @file
 * @brief simple factorial
 * @implements factorial function
 * @author [William Henrique](https://github.com/Willh-AM)
 */

#include <assert.h> /// for assert

/** 
 * @brief Factorial of a number
 * @param n not signed integer number
 * @returns n! = n * (n -1) * (n - 2) * ... * 1
 */

unsigned long factorial(unsigned long n)
{
    // temp factorial number
    unsigned long _n = 1ul; 
    // factorial loop until n igual 1
    while(n > 1)
    {
        _n *= n--;
    }
    return _n;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
void test() 
{
    /* Testing function output*/
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() 
{
    test();

    return 0;
}