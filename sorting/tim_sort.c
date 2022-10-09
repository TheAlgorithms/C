#include<stdio.h>
#include<stdlib.h>

const int RUN = 32; 

int min(int a, int b)    
{    
    return a<b?a:b;     
} 

void insertionSort(int a[], int beg, int end) 
{  
    int i, j, temp;  
    for (i = beg + 1; i <= end; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])    
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    }  
}  


void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;        
    int* LeftArray = (int*) malloc(sizeof(int)*n1);
    int* RightArray = (int*) malloc(sizeof(int)*n2);
    
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];       
    i = 0;   
    j = 0;  
    k = beg;       
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }       
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}  

void timSort(int a[], int n)  
{  
      
       
    for (int i = 0; i < n; i+=RUN)  
        insertionSort(a, i, min((i+RUN-1), (n-1)));   
        
    for (int size = RUN; size < n; size = 2*size)  
    {  
        for (int beg = 0; beg < n; beg += 2*size)  
        {  
            
            int mid = beg + size - 1;  
            int end = min((beg + 2*size - 1),(n-1));  
  
  
            if(mid < end)  
                merge(a, beg, mid, end);  
        }  
    }  
}  

void printArr(int a[], int n)  
{  
    for (int i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  

int main()  
{  
    int a[] = {23, 3, 33, 32, 5};  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    timSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}  
