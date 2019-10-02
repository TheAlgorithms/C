#include<stdio.h>
#include<stdlib.h>

void swap(int * x, int * y )
{
	int z = *x;
	*x = *y;
	*y = z;
}


void insertionSort(int *arr, int s, int e)
{
   int i, key, j;
   for (i = s+1; i < e; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}



void concat(int * arr, int l , int m, int r)
{
	int lh = m-l + 1 ,  rh = r-m ;
	int * brr = malloc(sizeof(int)*lh) , * crr = malloc(sizeof(int)*rh) ;
	int i, j = 0, k = l;
	
	insertionSort(arr, l , m);
	
	
	insertionSort(arr,m+1,rh);
	
	printf("\n\n\n");
	for(int i = l ; i < lh ; i++ )
		printf("%d",arr[i]); 
	
	printf("\n\n\n");
	for(int i = m+1 ; i < rh ; i++)
		printf("%d",arr[i]);	
		
	i=0;
		
	while( i < lh )
	{
	
		if( arr[i+l] >= arr[m+1] )
			{
			swap(&arr[l+i],&arr[m+1]);
			
			insertionSort(arr, m+1,rh );

			}
		i++;
	}	
}
	
	
	
	







void merge(int * arr, int l ,int r )
{

	if( r>l )
		{
		
			int m = (l+r)/2;
			merge(arr,l,m);
			merge(arr,m+1,r);
			
			concat(arr,l,m,r); 
		}


}




int main()
{

int * arr = malloc(sizeof(int ));

int n;
scanf("%d",&n);

for(int i = 0; i < n ; i ++)
scanf("%d",&arr[i]);

printf("\n\n");

for(int i = 0 ; i < n ; i ++)
printf("%d ",arr[i]);

merge(arr,0,n-1);

printf("\n\n");

for(int i = 0 ; i < n ; i ++)
printf("%d ",arr[i]);


return 0 ;
}
