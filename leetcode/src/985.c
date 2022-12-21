/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// collecting sum Runtime: O(len(queries)), Space: O(1)
int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int summ = 0;
    int* result = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    for(int i = 0; i < numsSize; i++){
        if (nums[i] % 2 == 0) {
            summ += nums[i];
        }
    }
    
    for(int i = 0; i < queriesSize; i++){
        int* query = queries[i];
        int val = query[0];
        int index = query[1];
        
        // sub index value from summ if it's even
        if (nums[index] % 2 == 0) {
            summ -= nums[index];
        }

        // modify the nums[index] value
        nums[index] += val;

        // add index value from summ if it's even
        if (nums[index] % 2 == 0) {
            summ += nums[index];
        }
        
        result[i] = summ;
    }
    
    return result;
}
