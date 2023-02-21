/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int* sets, int index){
    while (sets[index] != index){
        index = sets[index];
    }

    return index;
}

void unionSet(int* sets, int i1, int i2){
    int i1Parent = find(sets, i1);
    int i2Parent = find(sets, i2);
    
    sets[i1Parent] = i2Parent;
}

// Union find
// Runtime: O(n)
// Space: O(n)
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int setsSize = edgesSize + 1;
    int* sets = malloc(setsSize * sizeof(int));
    for (int i = 0; i < setsSize; i++){
        sets[i] = i;
    }

    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++){
        int* edge = edges[i];

        int i0Parent = find(sets, edge[0]);
        int i1Parent = find(sets, edge[1]);

        if (i0Parent == i1Parent){
            result[0] = edge[0];
            result[1] = edge[1];
            continue;
        }

        unionSet(sets, i0Parent, i1Parent);
    }

    free(sets);
    return result;
}
