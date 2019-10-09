#include <stdio.h>
#define LONGT 1000

void trade(int *fp, int *sp)
{
    int aux = *fp;
    *fp = *sp;
    *sp = aux;
}

int main (int argc, char *argv[])
{
    int i, j, n, array_numer[LONGT];

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    printf("Enter the %d elements:\n", n);
    for(i = 0 ; i < n; ++i)
    {
       scanf("%d", &array_numer[i]);
    }

    for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array_numer[j] > array_numer[j+1])
              trade(&array_numer[j], &array_numer[j+1]);

   for (i=0; i < n; i++)
        printf("%d ", array_numer[i]);

   printf("\n");
   return 0;
    
}
