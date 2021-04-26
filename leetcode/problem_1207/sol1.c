#define MAP_SIZE 2048

int cmpvalue(const void *a, const void *b) { return *(int *)b - *(int *)a; }
bool uniqueOccurrences(int *arr, int arrSize)
{
    int *map = calloc(MAP_SIZE, sizeof(int));
    int i;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] < 0)
            map[arr[i] + MAP_SIZE / 2] += 1;
        else
            map[arr[i]] += 1;
    }
    /* number of occurrences is sorted by decreasing order
       Ex: 3 2 1 0 0 0 0 */
    qsort(map, MAP_SIZE, sizeof(int), cmpvalue);
    i = 0;
    while (map[i])
    {
        if (map[i] == map[i + 1])
            return 0;
        i++;
    }
    return 1;
}
