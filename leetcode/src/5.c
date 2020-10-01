char* longestPalindrome(char* s)
{
    int stringSize;
    int subStringSize = 0, j, k;
    int max = 1;
    int head = 0;

    stringSize = strlen(s);

    if (s == NULL)
        return NULL;
    if (stringSize == 1)
        return s;

    for (subStringSize = 0;
         subStringSize < stringSize && (stringSize - subStringSize) > max / 2;)
    {
        j = subStringSize;
        k = subStringSize;

        while (k < stringSize - 1 && s[k] == s[k + 1])
        {
            k++;
        }
        subStringSize = k + 1;
        while (j > 0 && k < stringSize - 1 && s[j - 1] == s[k + 1])
        {
            j--;
            k++;
        }

        if (max < (k - j + 1))
        {
            max = k - j + 1;
            head = j;
        }
    }
    char* res = (char*)malloc(sizeof(char) * (max + 1));
    if (res == NULL)
        return NULL;
    for (subStringSize = 0; subStringSize < max; ++subStringSize)
        res[subStringSize] = s[head + subStringSize];

    res[max] = '\0';

    return res;
}