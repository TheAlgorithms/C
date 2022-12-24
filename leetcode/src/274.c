int diff(const int* i, const int* j)

{
    return *i - *j;
}


// Sorting.
// Runtime: O(n*log(n))
// Space: O(1)
int hIndex(int* citations, int citationsSize){
    qsort(citations, citationsSize, sizeof(int), (int(*) (const void*, const void*)) diff);

    for(int i = 0; i < citationsSize; i++){
        if (citations[citationsSize - 1 - i] <= i){
            return i;
        }
    }

    return citationsSize;
}
