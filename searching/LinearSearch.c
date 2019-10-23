#include <stdio.h>

int linearsearch(int *arr, int length, int value){
	int i;
	for (i = 0; i <=length-1; i++){
		if (arr[i] == value) //search element found in array
			return 1;
	}
	return 0;
}

void main(){
	int n,i,val;
	printf("Enter the length of the array:\n");
	scanf("%d",&n); //Taking input length of array

	int a[n];
	printf("Enter %d array elements:\n", n);
	for (i = 0; i < n; i++)	scanf("%d", &a[i]);// accepts the values of array elements until the condition in loop fails//

	printf("Enter the value to be searched:\n");
	scanf("%d", &val); //Taking input the value to be searched
	if (linearsearch(a,n,val))
		printf("Search element found");
	else
		printf("Search element not found");
}
