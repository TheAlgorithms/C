/**
 * \file
 * \brief [Problem 25](https://projecteuler.net/problem=25) solution implemented
 * using arbitrarily large numbers represented as arrays
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIGITS 1000 /**< maximum number of digits */

/**
 * Function to add arbitraty length decimal integers stored in an array.\n
 * a + b = c = new b
 */
unsigned int add_numbers(unsigned char *a, unsigned char *b, unsigned char *c,
                         int N)
{
    unsigned char carry = 0;
    unsigned int i;

    for (i = 0; i < N; i++)
    {
        // printf("\t%d + %d + %d ", a[i], b[i], carry);
        c[i] = carry + a[i] + b[i];
        if (c[i] > 9) /* check for carry */
        {
            carry = 1;
            c[i] -= 10;
        }
        else
        {
            carry = 0;
        }
        // printf("= %d, %d\n", carry, c[i]);
    }

    while (carry != 0)
    {
        // printf("\t\t...adding new digit\n");
        // printf("\t0 + %d + %d ", b[i], carry);
        c[i] = carry + c[i];
        if (c[i] > 9)
        {
            carry = 1;
            c[i] -= 10;
        }
        else
        {
            carry = 0;
        }
        // printf("= %d, %d\n", carry, c[i]);
        i++;
    }
    return i;
}

/** Print a large number */
int print_number(unsigned char *number, int N)
{
    int start_pos = N - 1;

    /* skip all initial zeros */
    while (number[start_pos] == 0) start_pos--;

    for (int i = start_pos; i >= 0; i--) putchar(number[i] + 0x30);

    return 0;
}

/** Get number of digits in a large number */
unsigned int get_digits(unsigned char *number)
{
    unsigned int digits = MAX_DIGITS;
    while (number[digits] == 0) digits--;
    return digits;
}

/** Main function */
int main(int argc, char *argv[])
{
    unsigned char
        fn[MAX_DIGITS + 1]; /* array to store digits of a large number */
    unsigned char fn1[MAX_DIGITS + 1];
    unsigned char sum[MAX_DIGITS + 1];

    memset(fn, 0, MAX_DIGITS);
    memset(fn1, 0, MAX_DIGITS);
    memset(sum, 0, MAX_DIGITS);

    fn[0] = 1;
    fn1[1] = 1;

    unsigned int index = 1, digit_count = 1;

    clock_t start_time = clock();
    do
    {
        digit_count = add_numbers(fn, fn1, sum, digit_count);
        // digit_count = get_digits(sum);

        // printf("%5u (%u) (%u) ", index, digit_count, get_digits(sum));
        // print_number(sum, digit_count);
        // putchar('\n');

        if (digit_count == MAX_DIGITS)
        {
            break;
        }
        memcpy(fn, fn1, MAX_DIGITS);
        memcpy(fn1, sum, MAX_DIGITS);
        index++;
    } while (digit_count < MAX_DIGITS);
    clock_t end_time = clock();

    printf("Time taken: %.4g ms\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    printf("The nth term for %d digits: %u \n", MAX_DIGITS, index--);
    print_number(sum, digit_count);

    return 0;
}
