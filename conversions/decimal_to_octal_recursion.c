// Program to convert decimal number to octal (Using Reccursion)
// This program only works for integer decimals
// Created by Aromal Anil

#include <stdio.h>
int decimal_to_octal(int decimal)
{
    if ((decimal < 8) && (decimal > 0))
    {
        return decimal;
    }
    else if (decimal == 0)
    {
        return 0;
    }
    else
    {
        return ((decimal_to_octal(decimal / 8) * 10) + decimal % 8);
    }
}
int main()
{
    int octalNumber, decimalNumber;
    printf("\nEnter your decimal number : ");
    scanf("%d", &decimalNumber);
    octalNumber = decimal_to_octal(decimalNumber);
    printf("\nThe octal of %d is : %d", decimalNumber, octalNumber);
    return 0;
}
