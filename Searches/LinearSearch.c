#include <stdio.h>

int linearsearch(int *arr, int size, int val){
	int i;
	for (i = 0; i < size; i++){
		if (arr[i] == val)
			return 1;
	}
	return 0;
}

void main(){
	int s,i,v;
	printf("Enter the size of the array:\n");
	scanf("%d",&s);

	int a[s];
	printf("Enter the contents for an array of size %d:\n", s);
	for (i = 0; i < s; i++)	scanf("%d", &a[i]);

	printf("Enter the value to be searched:\n");
	scanf("%d", &v);
	if (linearsearch(a, s, v))
		printf("Value %d is in the array.\n", v);
	else
		printf("Value %d is not in the array.\n", v);
}
