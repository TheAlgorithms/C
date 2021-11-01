/**
 * @brief Octal to binay conversion by scanning user input
 * @details
 * The octalTobinary function take the octal number as long
 * return a long binary nuber after conversion
 * @author [Vishnu P](https://github.com/vishnu0pothan)
 */
#include <math.h>
#include <stdio.h>

/**
 * @brief Converet  octal number to binary
 * @param octalnum octal value that need to convert
 * @returns A binary number after conversion
 */
long octalToBinary(int octalnum)
{
    int decimalnum = 0, i = 0;
    long binarynum = 0;

    /* This loop converts octal number "octalnum" to the
     * decimal number "decimalnum"
     */
    while (octalnum != 0)
    {
        decimalnum = decimalnum + (octalnum % 10) * pow(8, i);
        i++;
        octalnum = octalnum / 10;
    }

    // i is re-initialized
    i = 1;

    /* This loop converts the decimal number "decimalnum" to the binary
     * number "binarynum"
     */
    while (decimalnum != 0)
    {
        binarynum = binarynum + (long)(decimalnum % 2) * i;
        decimalnum = decimalnum / 2;
        i = i * 10;
    }

    // Returning the binary number that we got from octal number
    return binarynum;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    int octalnum;

    printf("Enter an octal number: ");
    scanf("%d", &octalnum);

    // Calling the function octaltoBinary
    printf("Equivalent binary number is: %ld", octalToBinary(octalnum));
    return 0;
}
