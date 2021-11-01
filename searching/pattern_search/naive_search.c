#include <stdio.h>
#include <string.h>

/* Naive Pattern Search algorithm (brute force way) */
void naive_search(char *str, char *pattern)
{
    int len_str = strlen(str);
    int len_pat = strlen(pattern);

    for (int i = 0; i <= len_str - len_pat; i++)
    {
        int j;
        for (j = 0; j < len_pat; j++)
        {
            if (str[i + j] != pattern[j])
                break;
        }
        if (j == len_pat)
            printf("--Pattern is found at: %d\n", i);
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
    naive_search(str, pat1);
    printf("Test2: search pattern %s\n", pat2);
    naive_search(str, pat2);
    printf("Test3: search pattern %s\n", pat3);
    naive_search(str, pat3);
    return 0;
}
