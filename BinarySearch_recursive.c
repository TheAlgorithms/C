#include<stdio.h>
int BS_rec(int arr[],int l,int h,int key)
{
	if(l<=h)
	{
		int mid=(l+h)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<key)
		{
			l=mid+1;
			return BS_rec(arr,l,h,key);
		}
		else if(arr[mid]>key)
		{
			h=mid-1;
			return BS_rec(arr,l,h,key);
		}		
	}
	return -1;
}
int main()
{
	int n;
	// int arr[] = {12, 34, 54, 2, 3}; 
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int arr[n];
	// scanf("%d",&n);
	printf("Enter the element in the sorted order\n");
	for(int i=0;i<n;i++)
	{
		
		scanf("%d",&arr[i]);
	}
	int len = sizeof(arr)/sizeof(arr[0]); 
	printf("Enter the number to be searched\n");
	int x ;
	scanf("%d",&x);
	int index = BS_rec(arr, 0, len-1, x); 
	if (index != -1) 
	{
		printf("Element %d is present at index %d", x, index); 
	}
	else
	{
		printf("Element %d is not present", x); 
	}
	
	return 0; 
}