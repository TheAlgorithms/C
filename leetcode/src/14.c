int findMaxConsecutiveOnes(int* nums, int numsSize){
    int i=0;
    int maxCount=0;
    int count = 0;
    
    while(i<numsSize){
        
        while(i<numsSize && nums[i]!=0){
            count++;
            i++;
        }
        
        if(maxCount<=count){
         maxCount = count;   
        }
        
        count = 0;
        while(i<numsSize && nums[i]==0){
            i++;
        }
        
    }
    return maxCount;
    
}
