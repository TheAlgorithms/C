#include <stdio.h>
#include <string.h>
/*
 * Convert from Decimal to ANY base
 */
// this function will convert any digit to it's corresponding Character, so it will return 'B' when num = 11, and '5' when num = 5
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return num + '0';
    else
        return num - 10 + 'A';
}

// This function will reverse a string
void reverseString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// This function will convert any given decimal number to a base given
char* fromDecimal (char dec[], int base, int num)
{
    // initilize the index of the result
    int i = 0;

    // We can easly convert the number by repeatedly dividing it by the base and taking the reminder
    while(num > 0)
    {
        dec[i++] = reVal(num % base);
        num /= base;
    }
    dec[i] = '\0';// The result is correct but the string is reverted

    // Revert the string so the result can be printed
    reverseString(dec);

    return dec;
}

int main()
{
    int num = 0, base = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the base: ");
    scanf("%d", &base);
    char res[100];
    printf("\n%s\n", fromDecimal(res, base, num));
    return 0;
}
