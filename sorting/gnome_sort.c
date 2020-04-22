#include <stdio.h>
#include <stdlib.h>

void sort(int *numbers, int size)
{
    int pos = 0;
    while (pos < size)
    {
       if (pos == 0)
          pos = 1;
        if (numbers[pos] >= numbers[pos-1] || pos == 0)
            pos++;
        else
        {
            int tmp = numbers[pos-1];
            numbers[pos-1] = numbers[pos];
            numbers[pos] = tmp;
            pos--;


        }
    }
}

void display(int *array, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int size = 6;
    int i;
    int *numbers = malloc(size*sizeof(int));
    printf("Insert %d unsorted numbers: \n", size);
    for (i = 0; i < size; ++i)
        scanf("%d", &numbers[i]);
    printf("Initial array: ");
    display(numbers, size);
    sort(numbers, size);
    printf("Sorted array: ");
    display(numbers, size);
    free(numbers);
    return 0;
}
