#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char s[])
{

    /* determines the length of the given string */
    int len = strlen(s);

    /* creates a return string */
    char *ans = malloc(sizeof(char) * len);

    /* for the loop */
    int i = 0;

    /* actual compile process */
    for (i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case 'G':
            ans[i] = 'C';
            break;
        case 'C':
            ans[i] = 'G';
            break;
        case 'T':
            ans[i] = 'A';
            break;
        case 'A':
            ans[i] = 'U';
            break;
        }
    }

    return ans;
}