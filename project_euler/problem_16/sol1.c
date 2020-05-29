#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    const double tmp = log(10) / log(2); /* required to get number of digits */
    unsigned long MAX_NUM_DIGITS;
    uint8_t *digits = NULL;              /* array to store individual digits. index 0 = units place */
    int N = 1000, sum = 0;

    if (argc == 2)
        N = atoi(argv[1]);

    MAX_NUM_DIGITS = (N + tmp) / tmp;
    
    digits = calloc(MAX_NUM_DIGITS, sizeof(uint8_t));
    digits[0] = 1;

    if (!digits)
    {
        perror("Unable to allocate memory!");
        return -1;
    }

    for (int i = 0; i < N; i++)
    {
        int carry = 0;
        for (int j = 0; j < MAX_NUM_DIGITS; j++)
        {
            digits[j] = (digits[j] << 1) + carry;   /* digit * 2 + carry */
            // printf("\t value: %d\t", digits[j]);
            if (digits[j] > 9)
            {
                carry = 1;
                digits[j] -= 10;
            } else
                carry = 0;
            // printf("carry: %d\t value: %d\n", carry, digits[j]);
            
            /* accumulate sum for last multiplication */
            if (i == N - 1)
                sum += digits[j];
        }
    }

    printf("2^%d = ", N);
    for(int i = MAX_NUM_DIGITS - 1; i >= 0; i--)
        putchar(digits[i] + 0x30);
    printf("\n\t Sum: %d\t Num. digits: %lu\n", sum, MAX_NUM_DIGITS);

    free(digits);
    return 0;
}