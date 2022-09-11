/**
 * \file
 *
 * \brief Implementation of [Fibonacci Sequence
 * explicit formula solution](https://fabiandablander.com/r/Fibonacci.html)
 *
*/

#include <math.h> /// for pow and sqrt
#include <stdio.h>

/*
 * formula comes from quadratic formula and recurrence relation
 * all the proof can be found in the related article in top of the file
 */
double fib(int n) {
    return (1 / sqrt(5) * pow(((1 + sqrt(5)) / 2), n + 1)) -
           (1 / sqrt(5) * pow(((1 - sqrt(5)) / 2), n + 1));
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test () {
    for(int i = 0; i <= 10; i++){
        printf("%d. fibonacci sequence is: %.0f\n", i, fib(i));
    }
}

// driver code
int main() {
    test();
    return 0;
}
