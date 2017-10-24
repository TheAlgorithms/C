#include <stdio.h>
#incude  <stdlib.h>
#define MAX 20

//i and j act as counters
//arraySort is the array that is to be sorted
//elmtToInsert will be the element that we will be trying to move to its correct index in the current iteration

int main()
{
    int i, elmtToInsert , j , arraySort[MAX] = {0};

      for(i = 1 ; i < MAX ;  i++) //This array is being sorted in the ascending order. 
       {
           elmtToInsert = arraySort[i]; //Pick up the ith indexed element of the array. It will be the elmtToInsert.
           j = i - 1 ;

         while(j >= 0 && elmtToInsert < arraySort[j]) /*compare it with each (i-1)th, (i-2)th... max 0th element, till the correct 
                                                        position of the elmtToInsert, where it is finally greater than the element just
                                                        before it, is found */   
          {
              // You'll enter the loop if the elmtToInsert is less than the element just before it.
            
              arraySort[j+1] = arraySort[j]; //shift the current element one place forward to create room for insertion of the elmtToInsert
              j--;
          }
          //when we exit the loop, j+1 will be the index of the correct position of the elmtToInsert

            arraySort[j+1] = elmtToInsert ; //'insert' the elmtToInsert into its correct position
          
        }
    

    return EXIT_SUCCESS;
}
