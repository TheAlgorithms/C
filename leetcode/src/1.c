#Method:1

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    int *ret = calloc(2, sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        int key = target - nums[i];
        for (j = i + 1; j < numsSize; j++)
            if (nums[j] == key)
            {
                ret[0] = i;
                ret[1] = j;
            }
    }
    *returnSize = 2;
    return ret;
}

#Method:2

#define         m       32887
#define         EMPTY   -32768

int table[m];
void hash_init();
void hash_insert();
int  hash_srch();


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,idx0,idx;
    hash_init();
    for(i=0;i<numsSize;i++)
        hash_insert(nums[i]);
    
    for(i=0;i<numsSize;i++)
    {
        
        idx=hash_srch(target-nums[i]);  
        
        if(nums[i]*2==target)           
        {
            idx0=i;
            int flag=0;
            for(j=i ;j<numsSize && flag<2 ;j++)
                if(nums[j]==nums[i])    
                    flag++;
            
            if(flag==2)
            {
                idx=j-1;
                break;
            }   
        }
            
        
        else if(idx!=-1)  
        {
            idx0=i;
            
            for(j=i;j<numsSize;j++)
                if(nums[j]==table[idx])
                {
                    idx=j;
                    break;
                }

            
            break;
        }
    }
    
    *returnSize=2;
    
    int *ans=(int*)malloc(*returnSize*sizeof(int));
    ans[0]=idx0;
    ans[1]=idx;
    return ans;
    
}



int hash(int key)
{
    return(abs(key)*11 % m);
}


void hash_init(void)
{
    int i;
    for(i=0;i < m;i++)
        table[i]= EMPTY;
}


void hash_insert(int key)
{
    int addr=hash(key);         
    while(table[addr] != EMPTY)
        addr=(addr+1) % m;     
    table[addr]=key;
}


int hash_srch(int key)
{
    int addr;
    addr=hash(key); 
    while(table[addr] != key)   
    {
        addr=(addr+1)%m;  
        if(table[addr]== EMPTY || addr==hash(key))
                return(-1);                   
    }
  
