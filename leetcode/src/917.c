char *reverseOnlyLetters(char *S)
{
    int last = strlen(S) - 1, i;
    for (i = 0; i < last;)
    {
        if (!isalpha(S[i]))
        {
            i++;
            continue;
        }
        if (!isalpha(S[last]))
        {
            last--;
            continue;
        }
        char tmp = S[i];
        S[i] = S[last];
        S[last] = tmp;
        i++;
        last--;
    }
    return S;
}
