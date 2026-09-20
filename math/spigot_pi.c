/**
 * @file
 * @brief Generate decimal digits of Pi with integer arithmetic.
 * @details Uses the Rabinowitz-Wagon spigot algorithm to produce digits
 * sequentially without floating-point arithmetic.
 * @see https://en.wikipedia.org/wiki/Spigot_algorithm
 * @author Alex (alexdev8930)
 * @date 20 September 2026
 */

#include <assert.h>   /// for assert
#include <stdbool.h>  /// for bool
#include <stddef.h>   /// for size_t
#include <stdio.h>    /// for printf
#include <stdlib.h>   /// for calloc and free

#define PI_DIGITS 42
#define ARRAY_SIZE (10 * PI_DIGITS / 3 + 1)
#define OUTPUT_SIZE (PI_DIGITS + 3)

/**
 * @brief Helper to append digits safely to the string buffer.
 */
static void append_char(char *output, size_t *out_idx, char c)
{
    // Leave one byte available for the terminating '\0'.
    if (*out_idx < OUTPUT_SIZE - 1)
    {
        // Insert decimal point automatically right after the leading '3'
        if (*out_idx == 1)
        {
            output[(*out_idx)++] = '.';
        }
        output[(*out_idx)++] = c;
    }
}

/**
 * @brief Generate Pi digits into an output buffer.
 * @param output buffer receiving the generated digits
 * @returns true if generation succeeds
 * @returns false if the output buffer is invalid
 */
static bool generate_pi(char output[OUTPUT_SIZE])
{
    int *remainder;
    int predigit = 0;
    int nines = 0;
    size_t out_idx = 0;

    if (output == NULL)
    {
        return false;
    }

    // Each array cell stores a remainder used by the spigot calculation.
    remainder = calloc(ARRAY_SIZE, sizeof(*remainder));
    if (remainder == NULL)
    {
        return false;
    }

    // The spigot algorithm starts every remainder at 2.
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        remainder[index] = 2;
    }

    for (int digit = 0; digit < PI_DIGITS + 2; digit++)
    {
        int carry = 0;

        // Process the remainder array from right to left.
        for (int index = ARRAY_SIZE; index > 0; index--)
        {
            int value = 10 * remainder[index - 1] + carry * index;

            remainder[index - 1] = value % (2 * index - 1);
            carry = value / (2 * index - 1);
        }

        remainder[0] = carry % 10;
        int next_digit = carry / 10;

        // Store the first digit (3) as predigit without printing it yet.
        if (digit == 0)
        {
            predigit = next_digit;
            continue;
        }

        if (next_digit == 9)
        {
            nines++;
        }
        else if (next_digit == 10)
        {
            // A carry changes the previous digit and pending 9s become 0s.
            append_char(output, &out_idx, (char)('0' + predigit + 1));

            while (nines > 0)
            {
                append_char(output, &out_idx, '0');
                nines--;
            }

            predigit = 0;
        }
        else
        {
            // The previous digit is now safe to print.
            append_char(output, &out_idx, (char)('0' + predigit));

            predigit = next_digit;

            while (nines > 0)
            {
                append_char(output, &out_idx, '9');
                nines--;
            }
        }
    }

    // Print the final delayed digit and terminate the C string.
    append_char(output, &out_idx, (char)('0' + predigit));
    output[out_idx] = '\0';

    free(remainder);
    return true;
}

/**
 * @brief Run automated tests to verify the correctness of the Pi generator.
 */
static void run_tests(void)
{
    char output[OUTPUT_SIZE];
    const char expected[] = "3.14159";

    assert(generate_pi(output));

    // Compare the beginning of the generated result with known Pi digits.
    for (size_t index = 0; expected[index] != '\0'; index++)
    {
        assert(output[index] == expected[index]);
    }

    // Confirm that the result is a valid terminated string.
    assert(output[OUTPUT_SIZE - 1] == '\0');

    printf("Success: tests passed.\n");
    printf("Result: %s\n", output);
}

/**
 * @brief Program entry point.
 * @returns 0 on success
 */
int main(void)
{
    run_tests();
    return 0;
}
