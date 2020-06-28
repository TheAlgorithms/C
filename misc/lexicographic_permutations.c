#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *left, char *right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}

int compare(const void *a, const void *b) { return (*(char *)a - *(char *)b); }

void PrintSortedPermutations(char *str)
{
    int strSize = strlen(str);
    qsort(str, strSize, sizeof(char), compare);

    int largerPermFound = 1;
    do
    {
        // 1. Print permutation
        printf("%s\n", str);
        // 2. Find rightmost char that is smaller than char to its right
        int i;
        for (i = strSize - 2; i >= 0 && str[i] >= str[i + 1]; --i)
        {
        }

        // if we couldn't find one, we're finished, else we can swap
        if (i >= 0)
        {
            // 3. find character at index j such that str[j] = min(str[k]) &&
            // str[k] > str[i] for all k > i
            int j = i + 1, k;
            for (k = j; k < strSize && str[k]; k++)
            {
                if (str[k] > str[i] && str[k] < str[j])
                    j = k;
            }
            // 3. Swap chars at i and j
            swap(&str[i], &str[j]);
            // 4. Sort string to the right of i
            qsort(str + i + 1, strSize - i - 1, sizeof(char), compare);
        }
        else
            largerPermFound = 0;
    } while (largerPermFound);
}

int main()
{
    int n;  // size of string
    scanf("%d\n", &n);
    if (n <= 0 || n >= 1000)
    {
        perror("Input number out of range: >0 and <1000\n");
        return -1;
    }
    char *str = (char *)malloc(n * sizeof(char));
    scanf("%s", str);
    PrintSortedPermutations(str);
    free(str);
    return 0;
}
