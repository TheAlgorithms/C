char findTheDifference(char *s, char *t)
{
    int sum1 = 0, sum2 = 0;
    int i;
    for (i = 0; i < strlen(s); i++) sum1 += s[i];
    for (i = 0; i < strlen(t); i++) sum2 += t[i];
    return (char)(sum2 - sum1);
}
