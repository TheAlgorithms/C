/*
    author: Christian Bender
    This is the implementation unit of the hash-functions.

    Overview about hash-functions:

    - sdbm
    - djb2
    - xor8 (8 bits)
    - adler_32 (32 bits)
*/

long long sdbm(char s[])
{
    long long hash = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hash = s[i] + (hash << 6) + (hash << 16) - hash;
        i++;
    }
    return hash;
}

long long djb2(char s[])
{
    long long hash = 5381; /* init value */
    int i = 0;
    while (s[i] != '\0')
    {
        hash = ((hash << 5) + hash) + s[i];
        i++;
    }
    return hash;
}

char xor8(char s[])
{
    int hash = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hash = (hash + s[i]) & 0xff;
        i++;
    }
    return (((hash ^ 0xff) + 1) & 0xff);
}

int adler_32(char s[])
{
    int a = 1;
    int b = 0;
    const int MODADLER = 65521;

    int i = 0;
    while (s[i] != '\0')
    {
        a = (a + s[i]) % MODADLER;
        b = (b + a) % MODADLER;
        i++;
    }
    return (b << 16) | a;
}