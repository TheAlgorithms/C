// Prefix sum.
// Collect sum fromleft part and compare it with left sum.
// Runtime: O(n)
// Space: O(1)
int waysToSplitArray(int* nums, int numsSize){
    long sumNums = 0;
    for (int i = 0; i < numsSize; i++){
        sumNums += nums[i];
    }
    
    long prefixSum = 0;
    int result = 0;
    for (int i = 0; i < numsSize - 1; i++){
        prefixSum += nums[i];
        if (prefixSum >= sumNums - prefixSum){
            result += 1;
        }
    }

    return result;
}
