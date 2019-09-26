void moveZeroes(int* nums, int numsSize){
    int i, start = 0;
    for (i = 0; i < numsSize; i++) {
        if(nums[i])
            nums[start++] = nums[i];
    }
    for(;start < numsSize; start++) {
        nums[start] = 0;
    }
}
