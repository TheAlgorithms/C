#include <stdio.h>

int main()
{
    int a[16500], T;
    long long int i, j;

    printf("Enter number of test cases : ");
    scanf("%d", &T);

    while (T--)
    {
        for (i = 0; i < 16500; i++)
        {
            a[i] = 0;
        }

        a[1] = 1;
        int N, carry = 0, count = 0;
        printf("Enter a number : ");
        scanf("%d", &N);

        for (i = 1; i <= N; i++)
        {
            carry = 0;
            for (j = 0; j < 16500; j++)
            {
                a[j] = a[j] * i + carry;
                carry = a[j] / 10;
                a[j] = a[j] % 10;
            }
        }

        for (i = 0; i < 16500; i++)
        {
            if (a[i] != 0)
            {
                count = i;
            }
        }

        for (i = count; i > 0; i--)
        {
            printf("%d", a[i]);
        }
        printf("\n");
    }

    return 0;
}
