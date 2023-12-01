#include <stdio.h> // For I/O ops
#include <assert.h> //For test cases

/**
MAIN DESCRIPTION:

 * @description a krishnamurthy number is
 * a number whose sum of the factorial of digits
 * is equal to the number itself.

 * @example 145 = 1! + 4! + 5!

 * @reference https://www.geeksforgeeks.org/problems/krishnamurthy-number1323/1
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
    return n*factorial(n-1);
}

/**
 * @brief Calculates the sum of the factorial of each digit
 * @param n the number to calculate the sum of the factorial of its digits
 * @param sum the sum variable to be incremented 
 * @returns an integer representing that sum
 */
int get_digit(int n, int sum){

    if (n<10){
	return sum+factorial(n);
    }
    else{
	int div = n/10;
	sum += factorial(n%10);
	return get_digit(div,sum);
    }
}

/*
 * @brief Verifies if a given number
 * is a krishnamurthy number
 * @param n the number to be verified as a krishnamurthy number
 * @returns 1 if n is a krishnamurthy number
 * @returns 0 if n is not a krishnamurthy number
 */
int krishnamurthy(int n){
    int sum=0;
    return get_digit(n,sum)==n;
}

/**
 * @brief Implementation of test cases
 * @return void
 */
static void tests(){
    assert(krishnamurthy(1) == 1);
    assert(krishnamurthy(13) == 0);
    assert(krishnamurthy(45) == 0);
    assert(krishnamurthy(145) == 1);
    assert(krishnamurthy(239) == 0);
    printf("All tests were successful!\n");
}

int main(){
    tests();
    return 0;
}

