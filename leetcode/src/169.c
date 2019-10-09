/* Boyer-Moore Majority Vote Algorithm
 * http://www.cs.utexas.edu/~moore/best-ideas/mjrty/ */
int majorityElement(int* nums, int numsSize){
    int count = 1;
    int majorNum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if(count == 0) {
            majorNum = nums[i];
            count++;
        } else if (majorNum == nums[i])
            count++;
        else
            count--;
    }
    return majorNum;
}
