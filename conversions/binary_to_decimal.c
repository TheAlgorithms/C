/*
 * Modified 23/10/2020, Suraj Patro
 *
 */

#include <stdio.h>

int main()
{
    int remainder, number = 0, decimal_number = 0, temp = 1;
    printf("Enter any binary number: ");
    scanf("%d", &number);

    // Iterate over the number until the end.
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        decimal_number += remainder * temp;
        temp = temp * 2;  // used as power of 2
    }

    printf("Decimal equivalent is: %d\n", decimal_number);
}
