int isPalendrome(char *s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return 0;
        }
    }
    return 1;
}

char *longestPalindrome(char *s)
{
    int i, j, longestSoFar, I, J, L;
    I = 0;
    J = 0;
    longestSoFar = 1;
    L = strlen(s);
    for (i = 0; i < L - longestSoFar; ++i)
    {
        for (j = i + longestSoFar; j < L; ++j)
        {
            if (((j - i + 1) * isPalendrome(s, i, j)) > longestSoFar)
            {
                I = i;
                J = j;
                longestSoFar = j - i + 1;
            }
        }
    }
    s[J + 1] = '\0';
    return s + I;
}
