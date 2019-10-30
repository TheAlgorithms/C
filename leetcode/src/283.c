void moveZeroes(int* nums, int numsSize) {
    int i = 0, start = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i])
            nums[start++] = nums[i];
    }

    for (start; start < numsSize; start++) {
        nums[start] = 0;
    }
}
