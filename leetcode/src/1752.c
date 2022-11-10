bool check(int* nums, int numsSize){
    if (numsSize == 1) {
        return true;
    }
    
    bool wasShift = false;
    for(int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            if (wasShift) {
                return false;
            }

            wasShift = true;
        }
    }
                
    return !wasShift || nums[0] >= nums[numsSize-1];
}
