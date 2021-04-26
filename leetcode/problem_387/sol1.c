int firstUniqChar(char *s)
{
    int *arr = calloc(256, sizeof(int));
    int i;
    for (i = 0; i < strlen(s); i++) arr[s[i]] = arr[s[i]] + 1;
    for (i = 0; i < strlen(s); i++)
    {
        if (arr[s[i]] == 1)
            return i;
    }
    return -1;
}
