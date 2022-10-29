#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,i=0;
        cin >> n;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        int low=0;
        int mid=0;
        int high=n-1;
        int temp=0;
        while(mid<=high){
            if(a[mid]==1){
                mid++;
            }
            else if(a[mid]==0){
            temp=a[low];
            a[low]=a[mid];
            a[mid]=temp;

                low++;
                mid++;
            }
            else{
                temp=a[high];
            a[high]=a[mid];
            a[mid]=temp;
                high--;
            }
        }
        for(i=0;i<n;i++)
            {
                cout << a[i]<<",";
            }

return 0;
}
