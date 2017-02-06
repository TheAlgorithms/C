/* ALGORITHM
1. Start from left hand side
2. Compare first two numbers
3. If first_number > second_number than swap both number position. And if first_number < second_number than these compare next two numbers i.e. second_number and third_number.
4. Step-3 process repeat until there are no more numbers left to compared.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
 int i,j,temp,SIZE;
 printf("Enter number of elements to be sorted : ");
 scanf("%d",&SIZE);
 int *arr = (int*)malloc(SIZE*sizeof(int));
 for(i=0; i<SIZE; i++)
 {
  printf("Enter Number : ");
  scanf("%d",&arr[i]);
 }
 for(i=0; i<SIZE ; i++)
 {
   for(j=0; j<(SIZE-1)-i; j++)
   {
     if( arr[j] < arr[j+1] )
     {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
     }
   }
   printf("%d\t",arr[j]);
 }
 getch();
 return 0;
}
