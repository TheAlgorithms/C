/*
    Algorithm: Factorial Calculation using Memoization

    This C program calculates factorials of non-negative integers using a recursive algorithm with memoization.
    Factorial of a non-negative integer 'n' is denoted as 'n!' and is defined as the product of all positive integers
    less than or equal to 'n'. For example, 5! = 5 x 4 x 3 x 2 x 1 = 120.

    Author: Sricharan Nibhanupudi
    
    Uses:
    - The program provides a function 'computeFactorial' that calculates the factorial of a given non-negative integer
      using recursive memoization. It stores previously computed factorials in an array 'factResults' to avoid redundant
      calculations, which significantly improves performance for large values of 'n'.
    - The 'testFactorial' function uses assertions to verify the correctness of the 'computeFactorial' function by
      comparing its results with known factorial values.
    - The program also demonstrates the use of standardized integer data types like 'uint64_t' from 'stdint.h' for
      improved code portability and readability.

    References:
    - The concept of factorial: https://en.wikipedia.org/wiki/Factorial
    - Memoization: https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/
*/

#include <stdio.h> /// Perform Input and Output operations
#include <stdint.h> /// Standardized integer data types for improved portability.
#include <assert.h> /// Assertions for testing purposes.

#define MAX_LIMIT 200

uint64_t factResults[MAX_LIMIT] = {0};

/**
 * @brief Computes the factorial of a non-negative integer using memoization.
 * @param sequenceNumber The non-negative integer for which to compute the factorial.
 * @return The factorial of the input integer.
 */
uint64_t computeFactorial(int sequenceNumber) {
    if (sequenceNumber == 0) {
        return 1;
    }
    if (factResults[sequenceNumber] != 0) {
        return factResults[sequenceNumber];
    }
    factResults[sequenceNumber] = sequenceNumber * computeFactorial(sequenceNumber - 1);
    return factResults[sequenceNumber];
}

/**
 * @brief Tests the 'computeFactorial' function by comparing its results with known factorial values.
 */
void testFactorial() {
    assert(computeFactorial(0) == 1);
    assert(computeFactorial(1) == 1);
    assert(computeFactorial(2) == 2);
    assert(computeFactorial(3) == 6);
    assert(computeFactorial(4) == 24);
    assert(computeFactorial(5) == 120);
    assert(computeFactorial(6) == 720);
    assert(computeFactorial(7) == 5040);
    assert(computeFactorial(8) == 40320);
    assert(computeFactorial(9) == 362880);
    assert(computeFactorial(10) == 3628800);
}

/**
 * @brief Main function to test the factorial calculation.
 * @return 0 on success.
 */
int main() {
    testFactorial();
    
    int testNumber;
    testNumber = 5;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber = 4;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber = 6;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber = 7;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber = 9;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber = 10;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    
    return 0;
}
