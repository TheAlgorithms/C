/**
 * \file
 *
 * \brief Implementation of [Collatz'
 * conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture)
 *
 * Collatz conjecture: a series for a number \f$n\f$ in which if \f$n\f$ even
 * then the next number is \f$\frac{n}{2}\f$ ,but if n is odd then the next
 * number is \f$3n+1\f$. This series continues till \f$n\f$ reaches 1
 */

#include <stdio.h>
#include <stdlib.h>

/** Main function */
int main(int argc, char *argv[])
{
    unsigned long long n, curr_no, num_steps = 0;
    if (argc == 2)
        n = strtoull(argv[1], NULL, 10);
    else
    {
        printf("Enter starting number: ");
        scanf("%lu", &n);  // input number
    }

    curr_no = n;          // curr_no stores input number n
    while (curr_no != 1)  // loop till series reaches 1
    {
        num_steps++;
        printf("%llu->", curr_no);
        if (curr_no % 2 == 0)  // condition   for even number
            curr_no = curr_no / 2;
        else
            curr_no = (curr_no * 3) + 1;  // condition for odd number
    }
    printf("1\nNumber of steps: %llu\n", num_steps);
    return 0;
}
