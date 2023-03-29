void swap(int *x, int *y){
    if (x==y)
        return;
   *x = *x + *y;
    *y= *x - *y;
    *x= *x - *y;
}

void sortColors(int* arr, int n){
    int start=0, mid=0, end=n-1;
    while(mid<=end){
        if(arr[mid]==1)
            mid++;
        else if(arr[mid]==0){
            swap(&arr[mid],&arr[start]);
            mid++;
            start++;
        }
        else{
            swap(&arr[mid],&arr[end]);
            end--;
        }
    }
}
