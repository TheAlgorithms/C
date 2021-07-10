int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int i=0; //for x
    int j=n; //for y
    int k=0; //for result
    int* result = (int*) malloc(numsSize*sizeof(int));
    while(i<n && j<numsSize){
        result[k++] = nums[i];
        result[k++] = nums[j];
        i++;
        j++;
    }
    *returnSize = numsSize;
    return result;
}

