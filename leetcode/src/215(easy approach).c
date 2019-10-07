

int findKthLargest(int *nums, int numsSize, int k){
    int temp;int i;int j;
   
    for(i=0;i<numsSize;i++)
    {
      scanf("%d",&nums[i]);
    }
    for(i=0;i<numsSize;i++)
     {
      for(j=i+1;j<numsSize;j++)
      {
        if(nums[i]<nums[j]) 
        {
          temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
      }
     }
   return nums[k-1];
    }



