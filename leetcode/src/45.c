// Breadth-first search, imitation.
// Runtime: O(n)
// Space: O(n)
int jump(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 0;
    }

    int step = 1;
    int* visitedCells = calloc(numsSize, sizeof(int));

    int* queue = malloc(numsSize * sizeof(int));
    queue[0] = 0;
    int queueLength = 1;

    while (queueLength > 0){
        int* nextQueue = malloc(numsSize * sizeof(int));
        int nextQueueLength = 0;

        for (int i = 0; i < queueLength; i++) {
            int cell = queue[i];
            int jump = nums[cell];

            if (cell + jump >= numsSize - 1) {
                free(visitedCells);
                free(queue);
                free(nextQueue);
                return step;
            }

            // populate next queue wave for searching
            for (int nextCell = cell; nextCell <= cell + jump; nextCell++) {
                if (visitedCells[nextCell] == 0){
                    nextQueue[nextQueueLength++] = nextCell;
                    visitedCells[nextCell] = 1;
                }
            }
        }

        step++;
        free(queue);

        queue = nextQueue;
        queueLength = nextQueueLength;
    }

    free(visitedCells);
    free(queue);
    return -1;
}
