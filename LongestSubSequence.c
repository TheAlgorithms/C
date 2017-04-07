#include <stdio.h>
#include <stdlib.h>


void longestSub(int* ARRAY,int ARRAY_LENGTH, int** RESULT,int* RESULT_LENGTH){	//RESULT and RESULT_LENGTH will be modified by their pointers
	
	if(ARRAY_LENGTH<=1){
		*RESULT=ARRAY;
		*RESULT_LENGTH=ARRAY_LENGTH;
	}
	else{
		int PIVOT=ARRAY[0];													
		int *LONGEST_SUB=NULL;														
		int LONGEST_SUB_LENGTH=0,i,j;												
		int TEMPORARY_ARRAY_LENGTH=0, *TEMPORARY_ARRAY=NULL;

		for(i=1;i<ARRAY_LENGTH;i++){
			if (ARRAY[i]<PIVOT){
				
				TEMPORARY_ARRAY_LENGTH=0;
				TEMPORARY_ARRAY=NULL;

				for(j=i+1;j<ARRAY_LENGTH;j++){
					if(ARRAY[j]>=ARRAY[i]){

						TEMPORARY_ARRAY_LENGTH++;
						TEMPORARY_ARRAY=(int *)realloc(TEMPORARY_ARRAY,TEMPORARY_ARRAY_LENGTH*sizeof(int));
						TEMPORARY_ARRAY[TEMPORARY_ARRAY_LENGTH-1]=ARRAY[j];
					}
				}

				longestSub(TEMPORARY_ARRAY,TEMPORARY_ARRAY_LENGTH,&TEMPORARY_ARRAY,&TEMPORARY_ARRAY_LENGTH);
				if(LONGEST_SUB_LENGTH<TEMPORARY_ARRAY_LENGTH+1){

					LONGEST_SUB_LENGTH=TEMPORARY_ARRAY_LENGTH+1;
					LONGEST_SUB=(int*)realloc(LONGEST_SUB,(LONGEST_SUB_LENGTH)*sizeof(int));
					LONGEST_SUB[0]=ARRAY[i];

					for(i=1;i<LONGEST_SUB_LENGTH;i++)
						LONGEST_SUB[i]=TEMPORARY_ARRAY[i-1];	
				}
			}
		}

		TEMPORARY_ARRAY=NULL;
		TEMPORARY_ARRAY_LENGTH=0;
		for(i=1;i<ARRAY_LENGTH;i++){

			if(ARRAY[i]>=PIVOT){
				TEMPORARY_ARRAY_LENGTH++;
				TEMPORARY_ARRAY=(int *)realloc(TEMPORARY_ARRAY,TEMPORARY_ARRAY_LENGTH*sizeof(int));
				TEMPORARY_ARRAY[TEMPORARY_ARRAY_LENGTH-1]=ARRAY[i];
			}
		}

		longestSub(TEMPORARY_ARRAY,TEMPORARY_ARRAY_LENGTH,&TEMPORARY_ARRAY,&TEMPORARY_ARRAY_LENGTH);
		if(TEMPORARY_ARRAY_LENGTH+1>LONGEST_SUB_LENGTH){

			LONGEST_SUB_LENGTH=TEMPORARY_ARRAY_LENGTH+1;
			LONGEST_SUB=(int*)realloc(LONGEST_SUB,(LONGEST_SUB_LENGTH)*sizeof(int));
			LONGEST_SUB[0]=PIVOT;
			for(i=1;i<LONGEST_SUB_LENGTH;i++)
				LONGEST_SUB[i]=TEMPORARY_ARRAY[i-1];
		}
		*RESULT=LONGEST_SUB;
		*RESULT_LENGTH=LONGEST_SUB_LENGTH;
	}
	

}

int main(){

	int *example=NULL;
	int n,i;
	//int t[9]={10, 22, 9, 33, 21, 50, 41, 60, 80};
	int t[8]={18, 2, 15, 4, 30, 0, 11, 12};
	//Il y'a un problème au cas où on a un LONGEST_SUBmum au milieu
	longestSub(t,8,&example,&n);
	printf("longueur: %d\n",n);
	for(i=0;i<n;i++)
		printf("%d ",example[i]);
	printf("\n");

	return 0;
}