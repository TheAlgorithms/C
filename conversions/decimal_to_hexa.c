/*****Decimal to Hexadecimal conversion*******************/
#include <stdio.h>
void decimal2Hexadecimal(long num);

int main()
{
    long decimalnum;

    printf("Enter decimal number: ");
    scanf("%ld", &decimalnum);

    decimal2Hexadecimal(decimalnum);

    return 0;
}

/********function for convert decimal number to hexadecimal
 * number****************/
void decimal2Hexadecimal(long num)
{
	char hex_letters[]="abcdef";
    long decimalnum = num;
    long quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];

    quotient = decimalnum;

    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = '0' + remainder;

        else
            hexadecimalnum[j++] =  hex_letters[remainder-10];// 'A'

        quotient = quotient / 16;
    }

    // print the hexadecimal number
	printf("0x");
    for (i = j-1; i >= 0; i--)
    {
        printf("%c", hexadecimalnum[i]);
    }

    printf("\n");
}
