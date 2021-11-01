// for strlen()
#include <string.h>

int numJewelsInStones(char *j, char *s)
{
    // as strlen is O(n), store it once rather than using it in for loop
    int cnt[500], lens = strlen(s), lenj = strlen(j), sol = 0;
    memset(cnt, 0, sizeof(cnt));

    // lookup to know which character occurs in j
    for (int i = 0; i < lenj; i++) cnt[j[i]]++;

    // count the characters in s
    for (int i = 0; i < lens; i++) sol += cnt[s[i]];

    return sol;
}
