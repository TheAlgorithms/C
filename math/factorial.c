#include <stdio.h>
int main()
{
    int a[200], n, counter, temp, i;
    // Digits of the factorial stored individually in reverse order. 
    a[0] = 1; 
    counter = 0;
/* This program computes large factorials by storing each digit
   separately in an array, avoiding integer overflow. */
    printf("Enter a whole number to Find its Factorial: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Cannot Calculate factorials for negative numbers.");
    else
    {
        for (; n >= 2; n--) // Multiply the current factorial value by every number from n down to 2. 
        {
            temp = 0;
            for (i = 0; i <= counter; i++)
            {
                temp = (a[i] * n) + temp; // Multiply current digit by n and add the carry from previous digit. 
                a[i] = temp % 10; // Store the last digit of the product. 
                temp = temp / 10; // Remaining value becomes the carry.
            }
            while (temp > 0) // Store remaining carry digits. 
            {
                a[++counter] = temp % 10;
                temp = temp / 10;
            }
        }
        for (i = counter; i >= 0; i--) printf("%d", a[i]); // Print the digits in reverse order to obtain the final factorial value. 
    }
    return 0;
}
