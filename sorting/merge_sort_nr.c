/* Program to demonstrate non recursive merge sort */

/* Merge sort is an effective sorting algorithm which falls under divide and
conquer paradigm and produces a stable sort. Merge sort repeatedly breaks down a
list into several sublists until each sublist consists of a single element and
merging those sublists in a manner that results into a sorted list.

Bottom-Up Merge Sort Implementation:
The Bottom-Up merge sort approach uses iterative methodology. It starts with the
“single-element” array, and combines two adjacent elements and also sorting the
two at the same time. The combined-sorted arrays are again combined and sorted
with each other until one single unit of sorted array is achieved. */

#include <stdio.h>

void mergesort(int x[], int n);
void show(int x[], int n);

void mergesort(int x[], int n)
{
    int temp[50], i, j, k, lb1, lb2, ub1, ub2, size;

    size = 1;
    while (size < n)
    {
        lb1 = 0;
        k = 0;

        while (lb1 + size < n)
        {
            lb2 = lb1 + size;
            ub1 = lb2 - 1;
            if (ub1 + size < n)
                ub2 = ub1 + size;
            else
                ub2 = n - 1;

            i = lb1;
            j = lb2;

            while (i <= ub1 && j <= ub2)
                if (x[i] < x[j])
                    temp[k++] = x[i++];
                else
                    temp[k++] = x[j++];

            while (i <= ub1) temp[k++] = x[i++];

            while (j <= ub2) temp[k++] = x[j++];

            lb1 = ub2 + 1;
        }

        for (i = 0; i <= ub2; i++) x[i] = temp[i];

        size = size * 2;

        show(x, n);
    }
}

// function to show each pass
void show(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++) printf("%d ", x[i]);
    printf("\n\n");
}

int main()  // main function
{
    int i, n, x[20];

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) scanf("%d", &x[i]);

    mergesort(x, n);

    printf("Sorted array is as shown:\n");
    for (i = 0; i < n; i++) printf("%d ", x[i]);
    return 0;
}

/* Output of the Program*/
/*
Enter the number of elements: 5
Enter the elements:
15
14
13
12
11
14 15 12 13 11

12 13 14 15 11

11 12 13 14 15

Sorted array is as shown:
11 12 13 14 15
*/
