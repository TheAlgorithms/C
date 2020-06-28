#include <stdio.h>
#include <string.h>

/* Kabin-Karp algorithm for pattern searching
   d: radix-d notation. Ex. number from 0->9, d = 10
   q: prime number for hashing */
void rabin_karp_search(char *str, char *pattern, int d, int q)
{
    int len_str = strlen(str);
    int len_pat = strlen(pattern);
    int i, h = 1;
    int hash_s = 0; /* hash value for string text */
    int hash_p = 0; /* hash value for pattern */

    /* h = pow(d, len_pat - 1) % q */
    for (i = 0; i < len_pat - 1; i++) h = d * h % q;
    /* Calculating hashing of pattern and the 1st window of text */
    for (i = 0; i < len_pat; i++)
    {
        hash_p = (d * hash_p + pattern[i]) % q;
        hash_s = (d * hash_s + str[i]) % q;
    }

    for (i = 0; i <= len_str - len_pat; i++)
    {
        /* Check hash value of current window of text, and pattern
           If it is match, check each character to make sure pattern
           is match with current window of text */
        if (hash_p == hash_s)
        {
            int j;
            for (j = 0; j < len_pat; j++)
            {
                if (pattern[j] != str[i + j])
                    break;
            }
            if (len_pat == j)
                printf("--Pattern is found at: %d\n", i);
        }
        /* Calculate hash value for next window by removing the leading
           element of current window text, and adding its trailing */
        hash_s = (d * (hash_s - str[i] * h) + str[i + len_pat]) % q;
        /* Converting hash value to positive when it is negative */
        if (hash_s < 0)
            hash_s = hash_s + q;
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
    rabin_karp_search(str, pat1, 256, 29);
    printf("Test2: search pattern %s\n", pat2);
    rabin_karp_search(str, pat2, 256, 29);
    printf("Test3: search pattern %s\n", pat3);
    rabin_karp_search(str, pat3, 256, 29);
    return 0;
}
