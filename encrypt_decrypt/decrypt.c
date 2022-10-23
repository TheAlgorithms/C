#include <stdio.h>
int main(int argc, char **argv)
{
    FILE *fptr, *fptr1;
    fptr = fopen(argv[1], "r");
    int key[1000000];
    for (int i = 0; i < 127; i++)
    {
        char a;
        fscanf(fptr, "%c", &a);
        key[i] = a == '0' ? 0 : 1;
    }
    for (int i = 127; i < 1000000; i++)
    {
        key[i] = key[i - 1] ^ key[i - 127];
    }
    fclose(fptr);
    fptr = fopen(argv[2], "r");
    fptr1 = fopen(argv[3], "w");
    char temp;
    int temp1[8] = {};
    int count = 0;
    while (fscanf(fptr, "%c", &temp) != EOF)
    {
        temp1[0] = temp == '0' ? 0 : 1;
        temp1[0] *= 2 * 2 * 2 * 2 * 2 * 2 * 2;
        for (int i = 1; i < 8; i++)
        {
            fscanf(fptr, "%c", &temp);
            temp1[i] = temp == '0' ? 0 : 1;
            for (int f = 0; f < 7 - i; f++)
            {
                temp1[i] *= 2;
            }
            temp1[0] += temp1[i];
        }
        char input = (char)temp1[0];
        int j = 7;
        short int xor = 0;
        for (int i = 8 * count + 127; i < 8 * (count + 1) + 127; i++)
        {
            int d = 1;
            for (int f = 0; f < j; f++)
            {
                d *= 2;
            }
            xor += key[i] * d;
            j--;
        }
        input = input ^ (char)xor;
        fprintf(fptr1, "%c", input);
        count++;
    }
    fclose(fptr1);
    fclose(fptr);
}
