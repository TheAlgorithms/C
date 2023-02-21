// Prefix sum.
// - Calculate whole nums sum.
// - Calculate currIndex sum.
// - Compare averages
// Runtime: O(n)
// Space: O(1)

int minimumAverageDifference(int* nums, int numsSize){
    long numsSum = 0;
    for (int i = 0; i < numsSize; i++){
        numsSum += nums[i];
    }
    
    long currSum = 0;
    long minAverage = 9223372036854775807; // Long max
    int minIndex = 0;
    
    for (int i = 0; i < numsSize; i++){
        currSum += nums[i];

        int leftItemsNumber = (numsSize - i  - 1);
        long leftItemsNumberAverage = 0;
        if (leftItemsNumber != 0){
            leftItemsNumberAverage = (numsSum - currSum) / leftItemsNumber;
        }

        long currItemsNumberAverage = currSum / (i + 1);
        long averageDiff = abs(currItemsNumberAverage - leftItemsNumberAverage);

        if (averageDiff < minAverage){
            minAverage = averageDiff;
            minIndex = i;
        }
    }

    return minIndex;
}
