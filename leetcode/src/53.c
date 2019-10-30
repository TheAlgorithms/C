
int maxcmp(int a, int b) {
    return a >= b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for(int i = 1; i < numsSize; i++) {
        maxEndingHere = maxcmp(maxEndingHere + nums[i], nums[i]);
        maxSoFar = maxcmp(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
