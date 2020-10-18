#include <math.h>
#include <stdio.h>

// Converts octal number to decimal number
long octalToDecimal(long octalValue){
    long decimalValue = 0;
    int i = 0;
    while (octalValue) {
        // Extracts right-most digit, multiplies it with 8^i, and increment i by 1
        decimalValue += (long)(octalValue % 10) * pow(8, i++);
        // Shift right in base 10
        octalValue /= 10;
    }
    return decimalValue;
}
char *octalToHexadecimal(long octalValue){
    char *hexadecimalValue = malloc(256 * sizeof(char));
    sprintf(hexadecimalValue, "%lX", octalToDecimal(octalValue));
    return hexadecimalValue;
}
int main()
{
    int octalValue;

    printf("Enter an octal number: ");
    scanf("%d", &octalValue);

    //Calling the function octalToHexadecimal
    char *hexadecimalValue = octalToHexadecimal(octalValue);
    printf("\nEquivalent hexadecimal number is: %s", hexadecimalValue);
    free(hexadecimalValue);
    return 0;
}
