#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int array[], int value){
  int i = value;
  int j, k, tmp;
  for (i = value / 2; i > 0; i = i / 2){
    for (j = i; j < value; j++){
      for(k = j - i; k >= 0; k = k - i){
        if (array[k+i] >= array[k]){
          break;
        }
        else{
          tmp = array[k];
          array[k] = array[k+i];
          array[k+i] = tmp;
        }
      }
    }
  }
}


int main(){

    int array[20];
    int range = 500;
    for(int i = 0; i < 100; i++){
     array[i] = rand() % range + 1;
    }
    int size = sizeof array / sizeof array[0];



    clock_t start = clock();
    shellSort(array,size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;


    printf("Data Sorted\n");
    printf("%s\n", "Shell Sort Big O Notation:\n--> Best Case: O(n log(n))\n--> Average Case: depends on gap sequence\n--> Worst Case: O(n)\n");
    printf("Time spent sorting: %f\n", time_spent);

  return 0;
}

