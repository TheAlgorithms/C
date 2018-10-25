#include <stdio.h>
 
int main()
{
   int c, first, last, middle, n, searchkey, array[100];
 
   printf("Enter number of elements\n");
   scanf("%d",&n);
 
   printf("Enter %d integers\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
 
   printf("Enter value to find\n");
   scanf("%d", &searchkey);
 
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < searchkey)
         first = middle + 1;    
      else if (array[middle] == searchkey) {
         printf("%d found at location %d.\n", searchkey, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", searchkey);
 
   return 0;  
}
