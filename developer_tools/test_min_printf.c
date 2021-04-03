/**
 * @file
 * @brief File used to test min_printf function.
 * @details
 * The test will be executed by comparing the result of both `min_printf` and `printf` functions
 * @author [Jaskarn7](https://github.com/Jaskarn7)
 * @see min_printf.h
*/

#include "min_printf.h" /// for `min_printf` function
#include <stdio.h> /// for `printf` function

/**
 * @brief Main function
 * @details
 * This function is used to test `min_printf` function.
 * The numbers and string used for the test is generated randomly (The user can also specify their own value for tests)
 * First integers were tested then floats and at last strings
 * After running the program the user will see three pair of lines with each pair followed by an empty line
 * In each pair of lines, the first line will be printed by `min_printf` function and next line by the actual `printf` function
 * In each line user will see number or string covered with two colons, they are used to check from where the printing was started and where it ends
 * @returns 0 on exit
*/
int main()
{
    // print strings using `printf` and `min_printf`
    min_printf(":%d: :%1.6d:\n", 12, 56);
    printf(":%d: :%1.6d:\n", 12, 56);

    printf("\n"); /// Printing an empty new line

    // print floats or doubles using `printf` and `min_printf`
    min_printf(":%f: :%3.6f:\n", 104.5654, 43.766443332);
    printf(":%f: :%3.6f:\n", 104.5654, 43.766443332);

    printf("\n");

    // print integers `printf` and `min_printf`
    min_printf(":%s: :%4.3s:\n", "Hello, World!", "Hello, World!");
    printf(":%s: :%4.3s:\n", "Hello, World!", "Hello, World!");

}
