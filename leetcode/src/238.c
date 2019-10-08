
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    
    int *output;
output=malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    if(numsSize==1)
    {
        output[0]=0;
        return output;
    }
    int left[numsSize];
    int right[numsSize];
    int l=nums[0];
    // product of all elements to the left of i
    left[0]=1;
    for(int i=1;i<numsSize;i++)
    {
        left[i]=l;
        l=l*nums[i];
    }
    l=nums[numsSize-1];
     // product of all elements to the right of i
    right[numsSize-1]=1;
     for(int i=numsSize-2;i>=0;i--)
    {
        right[i]=l;
        l=l*nums[i];
    }
    
    for(int i=0;i<numsSize;i++)
    {
        output[i]=left[i]*right[i];
    }
    return output;
}

