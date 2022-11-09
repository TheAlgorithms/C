int max(a,b){
    if(a>b)
        return a;
    else
        return b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count = 0; 
	int result = 0; 
    
    for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
			count = 0;
		else
		{
			count++;
			result = max(result, count);
		}
	}
    return result;
}
