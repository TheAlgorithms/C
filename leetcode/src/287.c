int cmpval(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int findDuplicate(int* nums, int numsSize){
    int i;
    qsort(nums, numsSize, sizeof(int), cmpval);
    for(i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i+1])
            return nums[i];
    }
    return nums[i];
}

