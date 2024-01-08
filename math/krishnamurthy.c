#include <stdio.h> /// For I/O ops
#include <assert.h> /// For test cases
#include <stdbool.h> /// For boolean

/**
 * @description a krishnamurthy number is
 * a number whose sum of the factorial of digits
 * is equal to the number itself.
 * @example 145 = 1! + 4! + 5!
*/


/**
 * @description n! = n*(n-1)*(n-2)*...*1
 * @brief calculates the factorial of a number
 * @param n the number we want to calculate the factorial
 * @return an integer representing the factorial of n
*/
int factorial(int n){
    if (n<2){
	return n;
    }
    return n * factorial(n-1);
}


/**
 * @brief Calculates the sum of the factorial of each digit
 * @param n the number to calculate the sum of the factorial of its digits
 * @param sum the sum variable to be incremented 
 * @returns an integer representing that sum
 */
int sum_digit(int n){
    if (n<10){
		return factorial(n);
    }
    else{
		return factorial(n%10) + sum_digit(n/10);
    }
}

/*
 * @brief Verifies if a given number
 * is a krishnamurthy number
 * @param n the number to be verified as a krishnamurthy number
 * @returns true if n is a krishnamurthy number
 * @returns false if n is not a krishnamurthy number
 */
bool krishnamurthy(int n){
    return sum_digit(n)==n;
}

/**
 * @brief Implementation of test cases
 * @return void
 */
static void tests(){
    assert(krishnamurthy(1) == true);
    assert(krishnamurthy(13) == false);
    assert(krishnamurthy(45) == false);
    assert(krishnamurthy(145) == true);
    assert(krishnamurthy(239) == false);
    printf("All tests were successful!\n");
}


/**
 * @brief main function
 * @returns 0 on successful exit
 */
int main(){
    tests();
    return 0;
}
