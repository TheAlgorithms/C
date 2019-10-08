#include <stdio.h>
#include <math.h>

// Function to count Devisors
int countDivisors(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                count++;

            else // Otherwise count both
                count = count + 2;
        }
    }
    return count;
}

int main()
{
    int i, n;
    unsigned long sum = 1;
    printf("Over ? ");
    scanf("%d", &n);
    for (i = 2; countDivisors(sum) < n; i++){
        sum += i;
    }
    printf("\n%lu", sum);
    return 0;
}
