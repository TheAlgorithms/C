#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv)
{
    FILE *fptr, *fptr1;
    fptr = fopen(argv[1], "r");
    fptr1 = fopen(argv[2], "w");
    srand(time(0));
    int key[1000000];
    for (int i = 0; i < 127; i++)
    {
        key[i] = rand() % 2;
        fprintf(fptr1, "%d", key[i]);
    }
    for (int i = 127; i < 1000000; i++)
    {
        key[i] = key[i - 1] ^ key[i - 127];
    }
    fclose(fptr1);
    fptr1 = fopen(argv[3], "w");
    char temp;
    int count = 0;
    while (fscanf(fptr, "%c", &temp) != EOF)
    {
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
        temp = temp ^ (char)xor;
        unsigned int output = (unsigned int)temp;
        int out[8];
        for (int i = 0; i < 8; i++)
        {
            out[i] = output % 2;
            output = output / 2;
        }
        for (int i = 7; i > -1; i--)
        {
            fprintf(fptr1, "%d", out[i]);
        }
        temp = temp ^ (char)xor;
        count++;
    }
    fclose(fptr1);
    fclose(fptr);
    return 0;
}
