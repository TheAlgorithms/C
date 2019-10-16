class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int A[100000];
        memset(A,0,sizeof(A));
        bool flag;
        int B[10000];
        int x=0;
        map<int,int>mii;
        for(auto it=arr.begin();it!=arr.end();it++)
        {
            mii[*it]++;
        }
        for(auto it=mii.begin();it!=mii.end();it++)
        {
            int k=it->second;
            A[x]=k;
            x++;
        }
        sort(A,A+x);
          for(int i=0;i<x-1;i++)
        {
              
              if(A[i]!=A[i+1])
			{
				
                flag=0;
               
			}
            else
            {
                flag=1;
                break;
            }
             //it--;
        }
        if(flag==0)
            return true;
        else
            return false;
        
    }
};