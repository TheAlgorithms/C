/*
 * Modified 23/10/2020, Suraj Patro
 *
 */
#include <stdio.h>

int main()
{
    long int binary, hexa = 0, i = 1, remainder;

    printf("Enter any binary number: ");
    scanf("%ld", &binary);
    while (binary != 0)
    {
        remainder = binary % 10;
        hexa = hexa + remainder * i;
        i = i * 2;
        binary = binary / 10;
    }
    printf("Hexadecimal equivalent is: %lX\n", hexa);
    return 0;
}
