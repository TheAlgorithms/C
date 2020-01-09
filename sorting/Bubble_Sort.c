//sorting of array list using bubble sort
#include <stdio.h>

/*Displays the array, passed to this method*/
void display(int arr[], int n){
    
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
}

/*Swap function to swap two values*/
void swap(int *first, int *second){
    
    int temp = *first;
    *first = *second;
    *second = temp;
    
}

/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 size --- Array Size
 */
void bubbleSort(int arr[], int size){
    
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n); // E.g. 8
    
    printf("Enter the elements of the array\n");
    int i;
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i] );
    }
    
    printf("Original array: ");
    display(arr, n);                   // Original array : 10 11 9 8 4 7 3 8
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    display(arr, n);                // Sorted array : 3 4 7 8 8 9 10 11
    
    return 0;
}

