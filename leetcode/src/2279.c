int compare(const int* i, const int* j)
{
    return *i - *j;
}

// Sorting.
// Runtime: O(n*log(n))
// Space: O(n)
int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
    int* capacityLeft = malloc(capacitySize * sizeof(int));
    for (int i = 0; i < capacitySize; i++) {
        capacityLeft[i] = capacity[i] - rocks[i];
    }

    qsort(capacityLeft, capacitySize, sizeof (int), (int(*) (const void*, const void*)) compare);
    
    int bags = 0;
    for (int i = 0; i < capacitySize; i++) {
        if (additionalRocks < capacityLeft[i]){
            break;
        }

        additionalRocks -= capacityLeft[i];
        bags++;
    }

    free(capacityLeft);
    return bags;
}
