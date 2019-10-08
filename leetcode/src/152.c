// Utility functions to get minimum of two integers 
int min(int x, int y) { return x < y ? x : y; } 
  
// Utility functions to get maximum of two integers 
int max(int x, int y) { return x > y ? x : y; } 

int maxProduct(int* nums, int numsSize){
   int n = numsSize;
    int maxarray[n];
    int minarray[n];
    maxarray[0] = nums[0];
    minarray[0] = nums[0];
    int result = nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]>0){
            maxarray[i] = max(nums[i],maxarray[i-1]*nums[i]);
            minarray[i] = min(nums[i],minarray[i-1]*nums[i]);
        }else{
            maxarray[i] = max(nums[i],minarray[i-1]*nums[i]);
            minarray[i] = min(nums[i],maxarray[i-1]*nums[i]);
        }
        result = max(result,maxarray[i]);
    }
    
    return result;
}

