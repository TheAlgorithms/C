#include <stdio.h>
 
void bubble_sort(long [], long);
 
int main()
{
  long array[100], n, c, d, swap;
 
  printf("Enter number of elements\n");
  scanf("%ld", &n);
 
  printf("Enter %ld integers\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);
 
  bubble_sort(array, n);
 
  printf("Sorted list in ascending order:\n");
 
  for (c = 0; c < n; c++)
     printf("%ld\n", array[c]);
 
  return 0;
}
 
void bubble_sort(long list[], long n)
{
  long c, d, t;
 
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}
