#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENT_NR 20000
#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

void show_data(int arr[], int len)
{
    int i;

    for (i = 0; i < len; i++)
        printf("%3d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Optimized algorithm - takes half the time as other
 **/
void shell_sort(int array[], int LEN)
{
    const int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    const int gap_len = 8;
    int i, j, g;

    for (g = 0; g < gap_len; g++)
    {
        int gap = gaps[g];
        for (i = gap; i < LEN; i++)
        {
            int tmp = array[i];

            for (j = i; j >= gap && (array[j - gap] - tmp) > 0; j -= gap)
                array[j] = array[j - gap];
            array[j] = tmp;
        }
    }
#ifdef DEBUG
    for (i = 0; i < LEN; i++)
        printf("%s\t", data[i]);
#endif
}

int main(int argc, char *argv[])
{
    int i;
    int array[ELEMENT_NR];
    int range = 500;
    int size;
    double time_spent;

    srand(time(NULL));
    for (i = 0; i < ELEMENT_NR; i++)
        array[i] = rand() % range + 1;

    size = ARRAY_LEN(array);

    show_data(array, size);
    clock_t t1 = clock();
    shell_sort(array, size);
    clock_t t2 = clock();

    printf("Data Sorted\n");
    show_data(array, size);

    printf("Time spent sorting: %.4g s\n", (t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}
