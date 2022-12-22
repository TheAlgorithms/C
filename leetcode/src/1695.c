// Window sliding. Runtime: O(n), Space: O(n)
int maximumUniqueSubarray(int* nums, int numsSize){
    short* numsSet = (short*)calloc(10001, sizeof(short));
    numsSet[nums[0]] = 1;

    int maxSum = nums[0];

    int windowSumm = maxSum;
    int leftIndex = 0;
    
    int num = 0;
    for(int i = 1; i < numsSize; i++){
        num = nums[i];
        while (numsSet[num] != 0){
            numsSet[nums[leftIndex]] = 0;
            windowSumm -= nums[leftIndex];
            leftIndex++;
        }
        
        numsSet[num] = 1;
        windowSumm += num;
            
        if (maxSum < windowSumm){
            maxSum = windowSumm;
        }
    }
    
    return maxSum;
}
