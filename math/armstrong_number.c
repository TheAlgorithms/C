#include <stdio.h>

// Function to calculate x raised to the power y
int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res *= x;
        y = y >> 1;
        x *= x;
    }
    return res;
}

// Function to calculate order of the number
int order(int x)
{
    int n = 0;
    while (x)
    {
        n++;
        x = x / 10;
    }
    return n;
}

// Function to check whether the given number is Armstrong number or not
int isArmstrong(int x)
{
    // Calling order function
    int n = order(x);
    int temp = x, sum = 0;
    while (temp)
    {
        int r = temp % 10;
        sum += power(r, n);
        temp = temp / 10;
    }

    // If satisfies Armstrong condition
    return sum == x;
}

int main()
{
    int x = 153;
    if (isArmstrong(x))
        printf("True\n");
    else
        printf("False\n");

    x = 1253;
    if (isArmstrong(x))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
