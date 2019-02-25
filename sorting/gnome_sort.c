#include <stdio.h>
#include <stdlib.h>

void sort(int *numbers, int size)
{
    int pos = 0;
    while (pos < size)
    {
        if (numbers[pos] >= numbers[pos-1])
            pos++;
        else 
        {
            int tmp = numbers[pos-1];
            numbers[pos-1] = numbers[pos];
            numbers[pos] = tmp;
            pos--;

            if (pos == 0)
                pos = 1;
        }
    }
}

void display(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int size = 6;
    int *numbers = malloc(size*sizeof(int));
    printf("Insert %d unsorted numbers: \n", size);
    for (int i = 0; i < size; ++i)
        scanf("%d", &numbers[i]);
    printf("Initial array: ");
    display(numbers, size);
    sort(numbers, size);
    printf("Sorted array: ");
    display(numbers, size);
    free(numbers);
    return 0;
}

