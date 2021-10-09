/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //volatile int i=0,j=0;
    static int *return_ptr;
    *returnSize = 2;
    return_ptr = (int*) malloc(2 * sizeof(int));
    
    for (int i=0; i<numsSize-1;i++)
    {    
        for(int j=i+1;j<numsSize;j++)
        {
            if((nums[i] + nums[j]) == target)
            {
                return_ptr[0] = i;
                return_ptr[1] = j;
                return return_ptr;
            }
        }
    }
    return NULL;
}
