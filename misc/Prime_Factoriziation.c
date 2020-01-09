/*
    AUTHOR: Christian Bender
    DATE: 12.02.2019
    DESCRIPTION: This program calculates the prime factoriziation of a positive integer > 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* initial length of the dynamic array */
#define LEN 10

/* increasing range */
#define STEP 5

/*
    this type is for the representation of the prim factoriziation
    - its series/range of prime factors
    - its length : numbers of prime factors
*/
typedef struct data
{
    int * range;
    int length;
} range;
typedef range* Range;

/* int_fac : calculates the prime factoriziation of positive integers */
Range int_fact(int);

/* print_arr : prints the integer (heap) array*/
void print_arr(Range);

/* increase : increases the dynamic integer array */
int * increase(int *, int);

/* destroy: destroys the range-structure */
void destroy(Range);

/*
    main : simle frame program with a simple UI
*/
int main()
{

    int n = 0; /* for user input */

    printf("\t\tPrim factoriziation\n\n");
    printf("positive integer (> 1) ? ");
    scanf("%d", &n);
    Range r = int_fact(n);
    printf("\nThe factoriziation are: ");
    print_arr(r);
    destroy(r);
    return 0;
}


Range int_fact(int n)
{
    assert(n > 1); /* precondition : n must be greater then 1*/

    int len = LEN;
    int count = 0;
    int i = 0;
    int * range = (int *) malloc(sizeof(int) * len);
    assert(range);
    Range pstr = (Range) malloc(sizeof(range));
    assert(pstr);

    while (n % 2 == 0)
    {
        n /= 2;
        if (i < len)
        {
            range[i] = 2;
            i++;
        }
        else
        {
            range = increase(range, len);
            len += STEP;
            range[i] = 2;
            i++;
        }
        count++;

    }

    int j = 3;
    while (j*j <= n)
    {
        while (n % j == 0)
        {
            n /= j;
            if (i < len)
            {
                range[i] = j;
                i++;
            }
            else
            {
                range = increase(range, len);
                len += STEP;
                range[i] = j;
                i++;
            }
            count++;
        }

        j += 2;
    }


    if (n > 1)
    {
        if (i < len)
        {
            range[i] = n;
            i++;
        }
        else
        {
            range = increase(range, len);
            len += STEP;
            range[i] = n;
            i++;
        }
        count++;
    }

    pstr->range = range;
    pstr->length = count;
    return pstr;


}


void print_arr(Range pStr)
{
    assert(pStr); /* checks whether pStr is a null-pointer */
    int i = 0;
    printf("\n");
    for (i; i < pStr->length; i++)
    {
        if (i == 0)
            printf("%d", pStr->range[0]);
        else
            printf("-%d", pStr->range[i]);
    }
    printf("\n");
}


int * increase(int * arr, int len)
{
    assert(arr); /* checks whether arr is a null-pointer */
    int * tmp = (int*) realloc(arr, sizeof(int) * (len + STEP));
    assert(tmp);
    return tmp;
//    assert(arr);
}


void destroy(Range r)
{
    free(r->range);
    free(r);
}
