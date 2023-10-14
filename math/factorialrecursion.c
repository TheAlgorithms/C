#include<stdio.h>

// This function computes the factorial 
int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1); // factorial is again recursively called from here
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial: %d", factorial(n)); // The factorial function is called from here
    return 0;
}
