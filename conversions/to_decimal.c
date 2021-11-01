/*
 * convert from any base to decimal
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int base, i, j;
    char number[100];
    unsigned long decimal = 0;

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the number: ");
    scanf("%s", &number[0]);

    for (i = 0; number[i] != '\0'; i++)
    {
        if (isdigit(number[i]))
            number[i] -= '0';
        else if (isupper(number[i]))
            number[i] -= 'A' - 10;
        else if (islower(number[i]))
            number[i] -= 'a' - 10;
        else
            number[i] = base + 1;

        if (number[i] >= base)
        {
            printf("invalid number\n");
            return 0;
        }
    }

    for (j = 0; j < i; j++)
    {
        decimal *= base;
        decimal += number[j];
    }

    printf("%lu\n", decimal);
}
