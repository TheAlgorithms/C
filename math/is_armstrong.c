#include <stdio.h>


int main()
{
    int num, temp, rem, sum = 0, d = 0;

    printf("Enter number: ");
    scanf("%d", &num); // get number
    
    temp = num;
    // get number of digits
    // and save in variable d
    while (temp)
    {
        temp /= 10;
        d += 1;
    }

    temp = num;
    int powerSum;
    // adding digits of number
    // each raised to the power of the total number of digits
    while (temp)
    {
        rem = temp % 10;
        temp /= 10;
        powerSum = rem;
        for (int i=1; i<d; i++) powerSum *= rem;
        sum += powerSum;
    }

    // if sum is same as num,
    // then it is an armstrong number
    if (sum == num)
    {
        printf("%d is an armstrong number!\n", num);
    }
    else
    {
        printf("%d is not an armstrong number!\n", num);
    }
    return 0;
}
