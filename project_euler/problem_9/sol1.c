/**
 * \file
 * \brief [Problem 9](https://projecteuler.net/problem=9) solution - A naive
 * implementation
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>

/** Main function */
int main(void)
{
    for (int a = 1; a < 300; a++)
        for (int b = a + 1; b < 400; b++)
            for (int c = b + 1; c < 500; c++)
            {
                if (a * a + b * b == c * c)
                    if (a + b + c == 1000)
                    {
                        printf("%d x %d x %d = %ld\n", a, b, c,
                               (long int)a * b * c);
                        return 0;
                    }
            }

    return 0;
}
