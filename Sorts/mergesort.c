#include <stdio.h>

void swap (int *a,int *b)
{
    int t;
    t= *a;
    *a=*b;
    *b=t;
    
}

void merge(int a[],int l,int r,int n)
{  int *b = (int*)malloc(n*sizeof(int));
int c=l;
    int p1,p2;
    p1 = l;p2=((l+r)/2)+1;
    while ((p1<((l+r)/2)+1) &&(p2<r+1))
    { if(a[p1] <= a[p2])
{          b[c++] = a[p1];#include<stdlib.h>
#include<stdio.h>
 
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r);
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      merge(arr, l, m, r);
   }
}
 
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
           p1++;
}
          else
          {b[c++] = a[p2];p2++;}
        
    };
    
    if (p2 == r+1)
    {
       while ((p1<((l+r)/2)+1))
    { 
          b[c++] = a[p1];
            p1++;
    }; 
        
    }
    else
    {
          while ((p2<r+1))
    { 
          b[c++] = a[p2];
p2++;
    }; 
         }
         
        for (c=l;c<r-l+1;c++)
        a[c] = b[c];
    
}
void mergesort(int a[],int n,int l,int r)
{
    if (r-l == 1 )
    {
        if (a[l]>a[r])
        swap(&a[l],&a[r]);
        
    }
    else if(l==r)
    {}
    else
    {mergesort(a,n,l,(l+r)/2);
     mergesort(a,n,((l+r)/2)+1,r);
       merge(a,l,r,n);
        
    }
    
}
int main(void) {
int *a,n,i;
scanf("%d",&n);
a = (int*)malloc(n*sizeof(int));
for (i=0;i<n;i++)
{
    
    scanf("%d",&a[i]);
    
}

mergesort(a,n,0,n-1);
for (i=0;i<n;i++)
{
    
    printf(" %d",&a[i]);
    
}


	return 0;
}



