/*
 * double hasing.
 * @author [Akash singh](https://github.com/Akashsnar)
 * Test case1: 5 6 7 8 9 3 2 8 -1 7
 * ans: 2
 * Test case2: 11 26 7 5 89 6 3 -1 2
 * ans: not found
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
void insert(int *h, int size, int key)
{
    // printf("%d", sizeof(h));
    int index, i, flag = 0, hkey;

    //   scanf("%d",&key);
    hkey = key % size;
    for (i = 0; i < size; i++)
    {
        index = (hkey + i) % size;
        if (h[index] == 0)
        {
            h[index] = key;
            break;
        }
    }
    if (i == size)
        printf("\nelement cannot be inserted\n");
}
void search(int *h, int size)
{
    int key, index, i, flag = 0, hkey;
    printf("\nenter search element\n");
    scanf("%d", &key);
    hkey = key % size;
    for (i = 0; i < size; i++)
    {
        index = (hkey + i) % size;
        if (h[index] == key)
        {
            printf("value is found at index %d", index);
            break;
        }
    }
    if (i == size)
        printf("\n value is not found\n");
}
void display(int *h, int size)
{
    int i;
    printf("elements in the hash table are \n");
    for (i = 0; i < size; i++)
    {
        printf("i=%d   value = %d\n", i, h[i]);
    }
    printf("\n");
}


int main()
{
    {
        int *hash = (int *)malloc(5 * sizeof(int));
        int size = 5;
        for (int i = 0; i < size; i++)
        {
            hash[i] = 0;
        }
        int n = 0;
        printf("\nenter a value to insert into hash table and press -1 to stop insertation\n");
        for (int i = 0;; i++)
        {
            scanf("%d", &n);
            if (n == -1)
            {
                break;
            }
            if (i == 0.8 * size)
            {
                printf("Size increases\n");
                size = 2 * size;
                hash = (int *)realloc(hash, size * sizeof(int));
                for (int j = size / 2; j < size; j++)
                {
                    hash[j] = 0;
                }
            }
            insert(hash, size, n);
            display(hash, size);
        }
        printf("Enter values to search\n");
        search(hash, size);
    }
    
    return 0;
}