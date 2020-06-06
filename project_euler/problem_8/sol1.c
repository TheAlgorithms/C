/**
 * \file
 * \brief [Problem 8](https://projecteuler.net/problem=8) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>
#include <stdlib.h>

/** Compute the product of two numbers in a file
 *
 * \param[in] fp pointer to file that is already open
 * \param[in] start_pos line number of the first numer
 * \param[in] num_digits number of digits on the line to multiply
 * \returns expected product
 */
long long int get_product(FILE *fp, long start_pos, int num_digits)
{
    char ch = ' '; /* temporary variable to store character read from file */
    unsigned char num = 0;  /* temporary variable to store digit read */
    long long int prod = 1; /* product accumulator */
    int count =
        0; /* we use this variable to count number of bytes of file read */

    /* accumulate product for num_digits */
    for (int i = 0; i < num_digits; i++, count++)
    {
        /* get character from file */
        ch = getc(fp);

        /* the ASCII codes of digits is between 0x30 and 0x39.
         * any character not in this range implies an invalid character
         */
        if (ch < 0x30 || ch > 0x39)
        {
            if (ch == EOF)
                return 0;
            i--;
            continue;
        }

        num = ch - 0x30; /* convert character digit to number */
        if (num == 0)
        {
            /* If number is zero, we can skip the next 'num_digits'
             * because this '0' will repeat in the next 'num_digit'
             * multiplications. Hence, we also do not update the file position
             */
            /* NOTE: this is not needed but helps get results faster :) */
            return 0;
        }

        prod *= num; /* accumulate product */
    }

    /* set file position to the next starting character + 1 */
    fseek(fp, -count + 1, SEEK_CUR);

    return prod;
}

/** Main function */
int main(int argc, char *argv[])
{
    int position = 0;
    int num_digits = 4;
    long long int prod, max_prod = 0;

    /* if second command-line argument is ge=iven,
     * use it as the number of digits to compute
     * successive product for
     */
    if (argc == 2)
        num_digits = atoi(argv[1]);

    /* open file to read digits from */
    FILE *fp = fopen("digits.txt", "rt");
    if (!fp)
    {
        perror("Unable to open file");
        return -1;
    }

    /* loop through all digits in the file */
    do
    {
        /* get product of 'num_digits' from current position in file */
        prod = get_product(fp, ftell(fp), num_digits);

        if (prod > max_prod)
        {
            max_prod = prod;
            position = ftell(fp) - 1;
        }
    } while (!feof(fp)); /* loop till end of file is reached */

    printf("Maximum product: %lld\t Location: %d^th position\n\t", max_prod,
           position);
    fseek(fp, position,
          SEEK_SET); /* move cursor to identified position in file */
    /* loop through all digits */
    for (; num_digits > 0; num_digits--)
    {
        char ch = getc(fp); /* get character */
        /* skip invalid character */
        if (ch < 0x30 || ch > 0x39)
            continue;
        if (num_digits > 1)
            printf("%c x ", ch);
        else
            printf("%c = %lld\n", ch, max_prod);
    }

    fclose(fp); /* close file */

    return 0;
}
