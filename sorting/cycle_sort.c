#include <stdio.h>
#include <stdlib.h>

/*I translated the python version on wikipedia to C */
void sort (int *numbers, int size) 
{
    int i, j, item, pos;
    for (i = 0; i < size-1; ++i)
    {
        item = numbers[i];
        pos = i;
        for (j = i+1; j < size; ++j)
            if (numbers[j] < item)
                pos++;

        if (pos == i)
            continue;

        while (item == numbers[pos])
            pos++;

        int tmp = numbers[pos];
        numbers[pos] = item;
        item = tmp;
        
        while (pos != i){
            pos = i;
            for (j = i+1; j < size; ++j)
                if (numbers[j] < item)
                    pos++;
            while (item == numbers[pos])
                pos++;
            int tmp = numbers[pos];
            numbers[pos] = item;
            item = tmp;
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
    int i, size = 6;
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
