/*
collatz conjecture: a series for a number n in which if n even then the next
number is n/2 ,but if n is odd then the next number is 3n+1. this series
continues till it reaches 1*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long long n, curr_no, num_steps = 0;
    if (argc == 2)
        n = strtoull(argv[1], NULL, 10);
    else
    {
        printf("Enter starting number: ");
        scanf("%lu", &n); // input number
    }

    curr_no = n;         // curr_no stores input number n
    while (curr_no != 1) // loop till series reaches 1
    {
        num_steps++;
        printf("%llu->", curr_no);
        if (curr_no % 2 == 0) // condition   for even number
            curr_no = curr_no / 2;
        else
            curr_no = (curr_no * 3) + 1; // condition for odd number
    }
    printf("1\nNumber of steps: %llu\n", num_steps);
    return 0;
}
