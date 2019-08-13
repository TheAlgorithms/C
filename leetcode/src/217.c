int numcmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool containsDuplicate(int* nums, int numsSize){
    int i;
    qsort(nums, numsSize, sizeof(int), numcmp);
    for (i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i+1])
            return 1;
    }
    return 0;
}
