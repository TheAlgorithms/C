#include <stdio.h>

int main()
{
#define SIZE 5   // defining a macro of definite size
int arr[SIZE] = {3,6,2,7,1};   // taking a demo array

//Bubble Sort Algorithm
for(int i = 0 ; i < SIZE - 1 ; i++)        //loop till SIZE - 1 index
{
    for(int j = 0 ; j < SIZE -i - 1 ; j++)  //loop till SIZE of array - i -1 index
    {
        if(arr[j] > arr[j + 1])    //comparing j and j+1 element
        {
            int temp = arr[j];   //swapping using a temporary(temp) variable
            arr[j] = arr[j + 1];    
            arr[j + 1] = temp;
        }
    }
}

for(int i = 0; i < SIZE; i++)   // Printing the array using for loop.
{    
    printf("%d ", arr[i]);
}

return 0;

}
