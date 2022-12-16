/**
 * @file
 * @brief Conversion of temperature in degrees from [Celsius](https://en.wikipedia.org/wiki/Celsius)
 * to [Fahrenheit](https://en.wikipedia.org/wiki/Fahrenheit).
 * 
 * @author [Focusucof](https://github.com/Focusucof)
 */

#include <assert.h> /// for assert
#include <stdio.h>  /// for IO operations

/**
 * @brief Convert celsius to Fahrenheit
 * @param celsius Temperature in degrees celsius double
 * @returns Double of temperature in degrees Fahrenheit
 */
 double celcius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
 }

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // 1st test
    double input = 0.0;
    double expected = 32.0;

    double output = celcius_to_fahrenheit(input);

    // 1st test
    printf("TEST 1\n");
    printf("Input: %f\n", input);
    printf("Expected Output: %f\n", expected);
    printf("Output: %f\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    // 2nd test
    input = 100.0;
    expected = 212.0;

    output = celcius_to_fahrenheit(input);

    printf("TEST 2\n");
    printf("Input: %f\n", input);
    printf("Expected Output: %f\n", expected);
    printf("Output: %f\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    // 3rd test
    input = 22.5;
    expected = 72.5;

    output = celcius_to_fahrenheit(input);

    printf("TEST 3\n");
    printf("Input: %f\n", input);
    printf("Expected Output: %f\n", expected);
    printf("Output: %f\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}
