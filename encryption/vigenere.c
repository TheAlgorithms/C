/*************************************************************************
	> File Name: vigenere.c
	> Author: Aaron
	> Mail: for_unity@sina.com
	> Created Time: Sat 25 May 2019 10:43:24 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRLEN       100
#define ISLETTER(ch)    (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')

void encrypt(char plain[], char key[])
{
    int i, j = 0;
    int keylen = strlen(key);

    for (i = 0; plain[i] != '\0'; i++)
    {
        if (ISLETTER(plain[i]))
        {
            plain[i] = (toupper(plain[i]) + key[j]) % 26 + 65;
            j = (j + 1) % keylen;
        }
    }
}

void decrypt(char cipher[], char key[])
{
    int i, j = 0;
    int keylen = strlen(key);

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (ISLETTER(cipher[i]))
        {
            cipher[i] = (26 + toupper(cipher[i]) - key[j]) % 26 + 65;
            j = (j + 1) % keylen;
        }
    }
}

int main()
{
    char str[MAXSTRLEN], key[MAXSTRLEN];
    int len;

    printf("Input the plain text:\n");
    fgets(str, MAXSTRLEN-1, stdin);
    printf("Input the key text:\n");
    scanf("%s", key);

    len = strlen(str);
    str[len-1] = '\0';

    encrypt(str, key);
    printf("After encrypt:\n%s\n", str);
    decrypt(str, key);
    printf("After decrypt:\n%s\n", str);

    return 0;
}
