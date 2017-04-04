#include <stdio.h>
#include <stdlib.h>


int main(){

    int* ARRAY=NULL;
    int ContinueFilling=1; //This is to know if we should continue filling our array
    int ARRAY_LENGTH=0,isSorted=0,i,TEMPORARY_ELEMENT;

    //This code part is for filling our array
    while(ContinueFilling){
        printf("Enter the value number %d \n",ARRAY_LENGTH+1);
        ARRAY=(int *)realloc(ARRAY,sizeof(int)*(ARRAY_LENGTH));
        scanf("%d",&ARRAY[ARRAY_LENGTH]);
        ARRAY_LENGTH+=1;
        printf("would you enter an other value (1:Continue/0:Sort the actual array)?\n");
        scanf("%d",&ContinueFilling);
    }

    //Then we sort it using Bubble Sort..

    while(!isSorted){ //While our array's not sorted
        isSorted=1; //we suppose that it's sorted
        for(i=0;i<ARRAY_LENGTH-1;i++){ //then for each element of the array
            if(ARRAY[i]>ARRAY[i+1]){  // if the two elements aren't sorted
                isSorted=0;    //it means that the array is not sorted
                TEMPORARY_ELEMENT=ARRAY[i]; //and we switch these elements using TEMPORARY_ELEMENT
                ARRAY[i]=ARRAY[i+1];
                ARRAY[i+1]=TEMPORARY_ELEMENT;
            }
        }
    }
    //And we display it
    for(i=0;i<ARRAY_LENGTH;i++){
        printf("%d, ",ARRAY[i]);
    }

    return 0;
}