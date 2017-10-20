#include <stddef.h>
#include <stdio.h>

void bubbleSort(int array[], size_t size)
{
    
        for(int z=2; z<=size; z++){
                for(int i=0; i<size-1; i++){
                        if(array[i] > array[i+1]){
                                int tmp = array[i];
                                array[i] = array[i+1];
                                array[i+1] = tmp;
                        }
                }
        }
        return 0;
}

int main()
{
        int arr[] = {5, 1, 2, 9 , 12, 53, 19};
        printf("Before BubbleSort \n");
        for(int i=0; i < 7; i++) {
            printf("%d: %d \n", i, arr[i]);
        }
        
        
        bubbleSort(arr, 7);
        
        printf("After bubbleSort \n");
        for(int i=0; i < 7; i++) {
            printf("%d: %d \n", i, arr[i]);
        }
        
        return 0;
}
