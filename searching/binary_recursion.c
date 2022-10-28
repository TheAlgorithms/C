#include <stdio.h>

int main(){

int arr[7] = {2,6,8,9,10,12,14};
int s=2,n=7;
  int l=0;
    int r=n-1;
 binarySearch(arr,l,r,s);




return 0;
}

int binarySearch(int arr[],int l,int r,int s){
    if(l>r){
        return-1;
    }
     int mid = (l+r)/2;

        if(s==arr[mid]){
            printf("The searching no is find at index of %d",mid);
            return mid;
        }else if(s>arr[mid]){
            return binarySearch(arr,mid+1,r,s);

        }else{
            return binarySearch(arr,l,mid-1,s);
        }

    }





