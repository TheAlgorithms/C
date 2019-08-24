int singleNumber(int* nums, int numsSize){
    int i, result = 0;
    for(i = 0; i < numsSize; i++)
        result = result ^ nums[i];
    return result;
}
