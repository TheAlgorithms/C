// Program to implement linear search algorithm
#include<stdio.h>

int main(void)
{
	int arr[] = {7,1,-9,3,4,20,4,0,-1}, size, n, flag=0;
	size = sizeof(arr) / sizeof(arr[0]);
	printf("Enter the element to be searched: ");
	scanf("%d",&n);
	for(int i=0; i<size; i++)
	{
		if(arr[i] == n)
		{
			flag = 1;
			break;
		}
	}
	(flag == 1) ? printf("\nElement Found!") : printf("\nElement not found!");
	return 0;
}
