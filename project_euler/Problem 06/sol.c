#include <stdio.h>

int main(void)
{
    unsigned s1 = 0, s2 = 0, i;
    int n;
    printf("For the first ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        s1 += i * i;
        s2 += i;
    }
    unsigned ans = s2 * s2 - s1;
    printf("%u\n", ans);
    return 0;
}
