//sorting of array list using selection sort
#include <stdio.h>

/*To diplay array elements using display function*/
void display(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 size --- Array Size
 */
void selectionSort(int arr[], int size){
    int temp;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[i] > arr[j]) {
                temp==arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() {
    int n,i;
    printf("Enter length of array:\n");
    scanf("%d", &n); 
    int arr[n];
    printf("Enter the elements of the array\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i] );
    }
    selectionSort(arr, n);
    printf("Sorted array is:");
    display(arr, n);               
    return 0;
}

