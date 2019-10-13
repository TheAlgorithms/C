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

/* crc32 Hash-Algorithm*/

int crc32(char string[])
{
    int i = 0;
    unsigned int cur_crc, masking;

    cur_crc = 0xFFFFFFFF;

    while(string[i] != '\0')
    {
        unsigned int byte = string[i];
        cur_crc = cur_crc ^ byte;
        for(int j = 8; j > 0; --j)
        {
            masking = -(cur_crc & 1);
            cur_crc = (cur_crc >> 1) ^ (0xEDB88320 & masking);
        }
        i++;
    }

    return -cur_crc;
}
