/**
 * @file
 * @brief Finding Fibonacci number of any `n` number using [Binet's closed form formula](https://en.wikipedia.org/wiki/Fibonacci_number#Binet's_formula)
 * compute \f$f_{nth}\f$ Fibonacci number using the binet's formula:
 * Fn = 1√5 * (1+√5 / 2)^n+1 − 1√5 * (1−√5 / 2)^n+1
 * @author [GrandSir](https://github.com/GrandSir/)
 */

#include <math.h> /// for pow and sqrt
#include <stdio.h> /// for printf
#include <assert.h> /// for assert

/**
 * @param n index of number in Fibonacci sequence
 * @returns nth value of fibonacci sequence for all n >= 0
 */
int fib(unsigned int n) {
    float seq = (1 / sqrt(5) * pow(((1 + sqrt(5)) / 2), n + 1)) - (1 / sqrt(5) * pow(((1 - sqrt(5)) / 2), n + 1));

    // removing unnecessary fractional part by implicitly converting float to int
    return seq;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test () {
    /* this ensures that the first 10 number of fibonacci sequence
     * (1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89)
     * matches with algorithm
    */
    assert(fib(0) == 1);
    assert(fib(1) == 1);
    assert(fib(2) == 2);
    assert(fib(3) == 3);
    assert(fib(4) == 5);
    assert(fib(5) == 8);
    assert(fib(6) == 13);
    assert(fib(7) == 21);
    assert(fib(8) == 34);
    assert(fib(9) == 55);
    assert(fib(10) == 89);
    
    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations

    for(int i = 0; i <= 10; i++){
        printf("%d. fibonacci number is: %d\n", i, fib(i));
    }
    return 0;
}
