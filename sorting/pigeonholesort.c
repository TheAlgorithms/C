Algorithm
pigeonHoleSort(array, size)
Input: An array of data, and the total number in the array

Output: The sorted Array

Begin
   find max and min from the array list
   holeRange := max – min +1
   define holeRange number of Lists

   for i := 0 to n-1 do
      hole[array[i]-min].append(array[i])
   done

   count := 0
   for j := 0 to holeRange-1 do
      while hole[j] is not empty do
         array[count] := get first node of hole[j] and delete it
         count := count +1
      done
   done
End


# source code for c

void pigeonhole_sort(int, int, int *);
void main()
{
    int a[MAX], i, min, max;
    printf("enter the values into the matrix :");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &a[i]);
    }
    min = a[0];
    max = a[0];
    for (i = 1; i < MAX; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    pigeonhole_sort(min, max, a);
    printf("Sorted order is :\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d", a[i]);
    }
}
 
/* sorts the array using pigeonhole algorithm */
void pigeonhole_sort(int mi, int ma, int * a)
{
 
    int size, count = 0, i;
    int *current;
    current = a;
    size = ma - mi + 1;
    int holes[size];
    for (i = 0; i < size; i++)
    {
        holes[i] = 0;
    }
    for (i = 0; i < size; i++, current++)
    {
        holes[*current-mi] += 1;
    }
    for (count = 0, current = &a[0]; count < size; count++)
    {
        while (holes[count]--> 0)
        {
            *current++ = count + mi;
        }
    }
}
