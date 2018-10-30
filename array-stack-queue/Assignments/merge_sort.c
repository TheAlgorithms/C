#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
		{
			L[i] = a[l+i];
		}
	for(j=0;j<n2;j++)
		{ 
			R[j] = a[m+1+j];
		}	
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
		{
			if(L[i]<=R[j])
				{
					a[k] = L[i];
					i++;
				}
			else
				{
					a[k] = R[j];
					j++;
				}
			k++;
		}

	while(i<n1)
		{
			a[k] = L[i];
			i++;
			k++;
		}

	while(j<n2)
		{
			a[k] = R[j];
			j++;
			k++;
		}
}

void merge_sort(int a[], int l, int r)
{
	if(l<r)
		{
			int m = l+(r-l)/2;

			merge_sort(a,l,m);
			merge_sort(a,m+1,r);

			merge(a,l,m,r);
		}
}

void print(int A[], int size)
{
	int i;
	for(i=0;i<size;i++)
		{
			printf("%d \n",A[i]);
		}
}

int main()
{
	int a[] = {10,20,44,12,56} ; 
	int a_size = sizeof(a)/sizeof(a[0]);
        /*printf("Enter the elements into the array\n");
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&a[i]);
	}*/
	printf("Given array is \n");
	print(a,a_size);
	
	merge_sort(a,0,a_size-1);

	printf("\nSorted array is \n");
	print(a,a_size);
	return 0;
}
			




































					





























			


