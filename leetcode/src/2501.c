#define max(a,b) (((a)>(b))?(a):(b))

int longestSquareStreakDp(int* numsSet, int numsSetSize, int* dp, long num){
    if (dp[num] != 0){
        return dp[num];
    }

    long numSquare = num * num;

    dp[num] = 1;
    if (numSquare <= numsSetSize && numsSet[numSquare] == 1){
        dp[num] += longestSquareStreakDp(numsSet, numsSetSize, dp, numSquare);
    }

    return dp[num];
}

// Dynamic approach. Up -> down.
// Runtime: O(numsSize)
// Space: O(max(nums))
int longestSquareStreak(int* nums, int numsSize){
    // Find nums maximum
    int numMax = 0;
    for(int i = 0; i < numsSize; i++){
        numMax = max(numMax, nums[i]);
    }

    int* numsSet = calloc(numMax + 1, sizeof(int));
    int* dp = calloc(numMax + 1, sizeof(int));
    
    // Init set of nums
    for(int i = 0; i < numsSize; i++){
        numsSet[nums[i]] = 1;
    }

    // Find result
    int result = -1;
    for(int i = 0; i < numsSize; i++){
        long num = nums[i];
        long numSquare = num * num;

        if (numSquare > numMax || numsSet[numSquare] == 0){
            continue;
        }

        result = max(result, 1 + longestSquareStreakDp(numsSet, numMax, dp, numSquare));
    }

    free(dp);
    free(numsSet);
    return result;
}
