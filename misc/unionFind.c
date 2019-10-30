#include <stdio.h>

int p[1000000];
int find(int x)
{
  if (p[x] == x)
  {
    return x;
  }
  else
  {
    p[x] = find(p[x]); 
    return p[x];
  }
}
// Call to function join(int x, int y) to join PARAM x and y
void join(int x, int y)
{
  p[find(x)] = find(y);
}

int main() 
{
    // Have all array indexes that you need to use refrence themselves
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
    // p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    join(3, 5);
    // Now 3 and 5 are groupped together, that is find(3) = find(5)
    // p = {0, 1, 2, 5, 4, 5, 6, 7, 8, 9}
    join(3, 8);
    // Now 3, 5 and are groupped together, find(3) = find(5) = find(8)
    // p = {0, 1, 2, 5, 4, 8, 6, 7, 8, 9}
    join(0, 5);
    if(find(0) == find(3)) 
    {
        printf("0 and 3 are groupped together\n");
    }
    printf("The array is now: ");
    for(int i = 0; i < 10; i++) 
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}