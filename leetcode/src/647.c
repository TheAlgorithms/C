
/* Author : Saurav Dubey */

int countSubstrings(char *s)
{
    int len = strlen(s);
    int i;
    int count = 0;
    for (i = 0; i < len; i++)
    {
        // cases handled for both odd and even lenghted Palindrome

        count += countPalin(s, i, i, len);
        if (i != len - 1)
            count += countPalin(s, i, i + 1, len);
    }
    return count;
}
int countPalin(char *s, int head, int tail, int len)
{
    int ret = (s[head] == s[tail]) ? 1 : 0;
    if (ret && head - 1 >= 0 && tail + 1 < len)
        ret += countPalin(s, head - 1, tail + 1, len);
    return ret;
}
