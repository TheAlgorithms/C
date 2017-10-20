#include <stddef.h>
#include <stdio.h>

void bubbleSort(int array[], size_t size)
{
    
        for(int z=2; z<=size; z++){                         //For loop for bucle the sort loop
                for(int i=0; i<size-1; i++){                //For loop for sort the array
                        if(array[i] > array[i+1]){          //Compare array[i] if is bigger than array[i+1] for exchange values
                                int tmp = array[i];         //Temporal variable for swap the values
                                array[i] = array[i+1];      //Change array[i] with array[i+1]
                                array[i+1] = tmp;           //Change array[i+1] with tmp, tmp holds array[i]
                        }
                }
        }
}

int main()
{
        int arr[] = {5, 1, 2, 9 , 12, 53, 19};      //Create an array for test sort
        printf("Before BubbleSort \n");
        for(int i=0; i < 7; i++) {                  //Loop for print the array before the sorting
            printf("%d: %d \n", i, arr[i]);         //Print array values
        }
        
        
        bubbleSort(arr, 7);                         //Apply bubbleSort function
        
        printf("After bubbleSort \n");
        for(int i=0; i < 7; i++) {                  //Loop for print the array after the sorting
            printf("%d: %d \n", i, arr[i]);         //Print array values
        }
        
        return 0;                                   //Return 0 (Standard Success exit code)
}
