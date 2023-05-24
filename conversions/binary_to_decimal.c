#include <stdio.h>

int main()
{
    int binary_number, decimal_number = 0, temp = 1;

    // Input the binary number
    printf("Enter any binary number: ");
    scanf("%d", &binary_number);

    // Convert binary to decimal
    while (binary_number > 0)
    {
        // Extract the rightmost digit of the binary number
        int digit = binary_number % 10;

        // Multiply the rightmost digit with the corresponding power of 2 and add to the decimal number
        decimal_number += digit * temp;

        // Remove the rightmost digit from the binary number
        binary_number /= 10;

        // Increase the power of 2 for the next digit
        temp *= 2;
    }

    // Output the decimal equivalent
    printf("Decimal equivalent: %d\n", decimal_number);

    return 0;
}
