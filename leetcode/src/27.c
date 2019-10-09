int removeElement(int* nums, int numsSize, int val) {
    int i, start = 0;
    for (i = 0; i < numsSize; i++) {
        if(nums[i] != val)
            nums[start++] = nums[i];
    }
    return start;
}
