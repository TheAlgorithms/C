#include <stdio.h>
#include <string.h>

#define NUM_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

void computeArray(char *pattern, int size, int arr[NUM_OF_CHARS])
{
    int i;

    for (i = 0; i < NUM_OF_CHARS; i++) arr[i] = -1;
    /* Fill the actual value of last occurrence of a character */
    for (i = 0; i < size; i++) arr[(int)pattern[i]] = i;
}
/* Boyer Moore Search algorithm  */
void boyer_moore_search(char *str, char *pattern)
{
    int n = strlen(str);
    int m = strlen(pattern);
    int shift = 0;
    int arr[NUM_OF_CHARS];

    computeArray(pattern, m, arr);
    while (shift <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pattern[j] == str[shift + j]) j--;
        if (j < 0)
        {
            printf("--Pattern is found at: %d\n", shift);
            shift += (shift + m < n) ? m - arr[str[shift + m]] : 1;
        }
        else
        {
            shift += max(1, j - arr[str[shift + j]]);
        }
    }
}

int main()
{
    char str[] = "AABCAB12AFAABCABFFEGABCAB";
    char pat1[] = "ABCAB";
    char pat2[] = "FFF"; /* not found */
    char pat3[] = "CAB";

    printf("String test: %s\n", str);
    printf("Test1: search pattern %s\n", pat1);
    boyer_moore_search(str, pat1);
    printf("Test2: search pattern %s\n", pat2);
    boyer_moore_search(str, pat2);
    printf("Test3: search pattern %s\n", pat3);
    boyer_moore_search(str, pat3);
    return 0;
}
