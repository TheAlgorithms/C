#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int vet[], int k, int n){ 
    int l = 0, r = n-1, m;
    while(l<=r){
        m = (l+r)/2;
        if(k == vet[m]){
            return m;
        }else if(k < vet[m]){
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return -1;
}

int main(){
    
    int vet[] = {1,2,3,4,5,6,7,8,9,10}, res; //Here I create a array called vet, with ten positions, and a variable called res
    
    res = binarySearch(vet, 5, 10); //Now I call my binarySearch function, I send to my function my array called vet, the number that I wanna find
                                   //in my array and the size of my array, respectivly.
    
    printf("%d", res); //Now, I just show what my binarySearch sent to me, it show -1 if the number isn't in the array and if 
                       //my number is in the array, it will show the index that the number is localized.
    
    return 0;
}
