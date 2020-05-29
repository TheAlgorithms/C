#include <stdio.h>

int main()
{
    int n, sum = 0, i, num;
    printf("Enter number: ");
    scanf("%d", &n);
    num = n;
    while (n != 0)
    {
        i = n % 10;
        sum = sum + (i * i * i);
        n = n / 10;
    }
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
