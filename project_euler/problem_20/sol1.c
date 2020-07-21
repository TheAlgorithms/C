/**
 * \file
 * \brief [Problem 20](https://projecteuler.net/problem=20) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 *
 * Implementation uses a custom `big_int` structure that can store arbitrarily
 * large integer numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * store arbitratily large integer values
 * as a linked list of digits.
 */
typedef struct _big_int
{
    char value;                  /**< tens place (single digit) */
    struct _big_int *next_digit; /**< hundreds place */
    struct _big_int *prev_digit; /**< units place */
} big_int;

#ifdef DEBUG
/** print a digit from large integer */
void print_digit(const big_int *my_int)
{
    printf("\tValue : %d\n\tNext : %p\n\tPrev : %p\n", my_int->value,
           my_int->next_digit, my_int->prev_digit);
}
#endif

/**
 * Function that allocates memory to add another
 * digit at the MSB
 */
big_int *add_digit(big_int *digit, char value)
{
    if (digit == NULL)
    {
        digit = (big_int *)malloc(sizeof(big_int));
        if (!digit)
        {
            perror("Unable to allocate memory!");
            return NULL;
        }
        digit->value = value;
        digit->next_digit = NULL;
        digit->prev_digit = NULL;

        return digit;
    }

    if (digit->next_digit)
    {
        digit->next_digit->value = value;
        return digit->next_digit;
    }

    digit->next_digit = (big_int *)malloc(sizeof(big_int));
    if (digit->next_digit == NULL)
    {
        perror("Unable to allocate memory!");
        return NULL;
    }
    digit->next_digit->value = value;
    digit->next_digit->next_digit = NULL;
    digit->next_digit->prev_digit = digit;
    return digit->next_digit;
}

/**
 * Function to remove digits preceeding the
 * current digit.
 */
char remove_digits(big_int *digit, int N)
{
    if (digit == NULL)
        return 0;

    if (digit->next_digit == NULL)
    {
        free(digit);
        digit = NULL;
        return 0;
    }

    if (N > 0)
        return remove_digits(digit->next_digit, N - 1);

    return remove_digits(digit->next_digit, 0);
}

/** Main function */
int main(int argc, char **argv)
{
    unsigned int N = 5;
    big_int *ptr = add_digit(NULL, 1); /* start with 1 */
    const big_int *ptr0 = ptr;         /* save the first location */
    unsigned long sum_digits = 0;
    unsigned long num_digits = 0;

    if (argc == 2)
        N = atoi(argv[1]);

    clock_t start_time = clock();

    for (unsigned int i = 1; i <= N; i++)
    {
        int carry = 0;
#ifdef DEBUG
        printf("%3d: ", i);
#endif
        ptr = (big_int *)ptr0; /* multiply every digit with i */
        while (ptr)
        {
#ifdef DEBUG
            printf("%p\t", ptr);
#endif
            unsigned int tmp = ptr->value * i + carry;
            if (tmp >= 10)
            {
                div_t tmp2 = div(tmp, 10);
                carry = tmp2.quot;
                tmp = tmp2.rem;
            }
            else
                carry = 0;

            if (carry > 0 && ptr->next_digit == NULL)
                add_digit(ptr, 0);

            ptr->value = tmp;

            if (i == N)
                /*
                 * sum digits on the last iteration
                 * this avoid having another loop over all digits
                 */
                sum_digits += tmp;

            if (ptr->next_digit)
                /* more digits available */
                ptr = ptr->next_digit;
            else
                /* no more digits left - reached MSB */
                break;
        }
#ifdef DEBUG
        printf("\n");
#endif
    }

    clock_t end_time = clock();

#ifdef DEBUG
    printf("ptr = %p\n", ptr);
    printf("%d! = ", N);
#endif

    /* Notice that in the loop above, we make sure that at the end of the loop,
     * ptr is pointing to the last digit. Thus we can avoid using another loop.
     */
    // ptr = &my_int;
    // /* move ptr to the MSB digit */
    // while (ptr->next_digit)
    //     ptr = ptr->next_digit;
    do
    {
        putchar(ptr->value + 0x30); /* convert digit to ASCII char */
        ptr = ptr->prev_digit;
        num_digits++;
    } while (ptr); /* after coming to units place, there will be no valid ptr */

    printf("\nTime taken: %.4g millisecond\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    printf(
        "Digit Sum = %lu\tNumber of digits = %lu\tStorage space = %.3gkb\t \n",
        sum_digits, num_digits, num_digits * sizeof(big_int) / 1024.0);

    remove_digits((big_int *)ptr0, -1);
    return 0;
}
