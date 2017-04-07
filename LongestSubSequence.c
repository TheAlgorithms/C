#include <stdio.h>
#include <stdlib.h>

int* longestSubsequence(int* ARRAY, int LENGTH, int**RESULT,int* leRESULT_LENGTH){
	if(LENGTH<=1){
		*RESULT=ARRAY;
		*leRESULT_LENGTH=LENGTH;
	
	}
	else{
		int PIVOT=ARRAY[0],n;
		int* LongestSub=NULL;
		longestSubsequence(ARRAY+1,LENGTH-1,&LongestSub,&n);
		if (PIVOT<=LongestSub[0]){
			int *newArray=(int *)realloc(NULL,(n+1)*sizeof(int));
			int i;
			newArray[0]=PIVOT;
			for(i=1;i<n+1;i++)
				newArray[i]=LongestSub[i-1];
			*RESULT = newArray;
			*leRESULT_LENGTH = n+1;

		}
		else{

			*RESULT=LongestSub;
			*leRESULT_LENGTH=n;
		}
	}
}

void longestSub(int* ARRAY,int ARRAY_LENGTH, int** RESULT,int* RESULT_LENGTH){	//RESULT and RESULT_LENGTH will be modified by their pointers
	
	if(ARRAY_LENGTH<=1){
		*RESULT=ARRAY;
		*RESULT_LENGTH=ARRAY_LENGTH;
	}
	else{
		int PIVOT=ARRAY[0];													
		int *maxi=NULL;														
		int maxi_length=0,i,j;												
		int TEMPORARY_ARRAY_LENGTH=0, *TEMPORARY_ARRAY=NULL;
		int *LS_RESULT=NULL, LS_RESULT_length;

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

				LS_RESULT=NULL;
				LS_RESULT_length=0;
				longestSub(TEMPORARY_ARRAY,TEMPORARY_ARRAY_LENGTH,&LS_RESULT,&LS_RESULT_length);
				if(maxi_length<LS_RESULT_length+1){

					maxi_length=LS_RESULT_length+1;
					maxi=(int*)realloc(maxi,(maxi_length)*sizeof(int));
					maxi[0]=ARRAY[i];

					for(i=1;i<maxi_length;i++)
						maxi[i]=LS_RESULT[i-1];	
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

		longestSub(TEMPORARY_ARRAY,TEMPORARY_ARRAY_LENGTH,&LS_RESULT,&LS_RESULT_length);
		if(LS_RESULT_length+1>maxi_length){
			
			maxi_length=LS_RESULT_length+1;
			maxi=(int*)realloc(maxi,(maxi_length)*sizeof(int));
			maxi[0]=PIVOT;
			for(i=1;i<maxi_length;i++)
				maxi[i]=LS_RESULT[i-1];
		}
		*RESULT=maxi;
		*RESULT_LENGTH=maxi_length;
	}
	

}

int main(){

	int *example=NULL;
	int n,i;
	int t[9]={10, 22, 9, 33, 21, 50, 41, 60, 80};
	//Il y'a un problème au cas où on a un maximum au milieu
	longestSub(t,9,&example,&n);
	printf("longueur: %d\n",n);
	for(i=0;i<n;i++)
		printf("%d ",example[i]);
	printf("\n");

	return 0;
}