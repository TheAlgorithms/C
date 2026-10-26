// C program to find LCM of two numbers
/*
    suppose we have two numbers a and b.
    Property: Since product of LCM and GCD of two numbers are equal to product
   of that number itself. i.e, LCM(a,b)*GCD(a,b)=a*b. So,here we first find the
   GCD of two numbers and using above property we find LCM of that two numbers.
*/
#include <stdio.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    // gcd(a, b) == 0 only when both inputs are zero; the division below would
    // raise SIGFPE. lcm(0, 0) is conventionally 0.
    if (a == 0 || b == 0)
        return 0;

    // Divide BEFORE multiplying. gcd(a, b) divides a exactly, so the
    // intermediate value never exceeds the true LCM: for a = b = 50000 the old
    // order computed 50000 * 50000 = 2500000000 (signed overflow, UB in C11)
    // even though the answer 50000 fits in int with room to spare.
    return (a / gcd(a, b)) * b;
}

// Driver program
int main()
{
    int a, b;
    printf("Enter two numbers to find their LCM \n");
    scanf("%d%d", &a, &b);
    printf("LCM of %d and %d is %d ", a, b, lcm(a, b));
    return 0;
}
/*
Test Case1:
a=15,b=20
LCM(a,b)=60
Test Case2:
a=12,b=18
LCM(a,b)=36
*/
