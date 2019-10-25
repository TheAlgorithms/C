//sorting of array list using insertion sort
#include <stdio.h>

/*Displays the array, passed to this method*/
void display(int arr[], int n) {
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
void insertionSort(int arr[], int size) {
    int i, j, key;
    for(i = 1; i <= size-1; i++) {
        
        key = arr[i];
        /* Move all elements greater than key to one position */
        for(j=i-1;j >= 0 && key < arr[j];j--) {    //j assigns j=i-1 bcoz we have assigned it to i=1 so for checking it from 0th position we need this
            arr[j + 1] = arr[j];
            
        }
        /* Find a correct position for key */
        arr[j + 1] = key;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n); // E.g. 8

    printf("Enter the elements of the array\n");
    int i;
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i] );
    }

    printf("Original array: ");
    display(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}

