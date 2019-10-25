#include<stdio.h>
int exponential_search(int [],int,int );
int binary_search(int [],int,int,int);
int main(){
	int n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the search element");
	int element;
	scanf("%d",&element);
	if(exponential_search(a,n,element)==1)
		printf("Search found");
	else
		printf("Search not found");
}
int exponential_search(int a[],int n,int x){
	int i=1;
	while(i<n){
		if(a[i]==x)
			return 1;
		if(a[i]<x)
			i=i*2;
		if(a[i]>x){
			if(binary_search(a,i/2,i,x)==0)
				return 0;
		}
	}
}
int binary_search(int a[],int f,int l,int x){
	if(f<=l){
		int mid=(f+l)/2;
		if(a[mid]==x)
			return 1;
		else if(a[mid]<x)
			binary_search(a,f,mid-1,x);
		else 
			binary_search(a,mid+1,l,x);
	}
	return 0;
}

		

