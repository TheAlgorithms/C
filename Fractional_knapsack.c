
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct knapsack
{
    float X[10];
    float profit;
};
void mergesort(float *A, float *B, float *C, int *D, int *p, int *q, int *r)
{
    int n1, n2, i, j, k;
    n1 = *q - *p + 1;
    n2 = *r - *q;
    float Left1[n1 + 2], Left2[n1 + 2], Left3[n1 + 2], Left4[n1 + 2], R1[n2 + 2], R2[n2 + 2];
    int R3[n2 + 2], R4[n2 + 2];
    for (i = 1; i <= n1; i++)
    {
        Left1[i] = A[*p + i - 1];
        Left2[i] = B[*p + i - 1];
        Left3[i] = C[*p + i - 1];
        Left4[i] = D[*p + i - 1];
    }
    for (j = 1; j <= n2; j++)
    {
        R1[j] = A[*q + j];
        R2[j] = B[*q + j];
        R3[j] = C[*q + j];
        R4[j] = D[*q + j];
    }
    Left1[n1 + 1] = INT_MIN;
    R1[n2 + 1] = INT_MIN;
    i = 1;
    j = 1;
    for (k = *p; k <= *r; k++)
    {
        if (Left1[i] >= R1[j]) // changes here < by >
        {
            A[k] = Left1[i];
            B[k] = Left2[i];
            C[k] = Left3[i];
            D[k] = Left4[i];
            i = i + 1;
        }
        else
        {
            A[k] = R1[j];
            B[k] = R2[j];
            C[k] = R3[j];
            D[k] = R4[j];
            j = j + 1;
        }
    }
}

void mergesorting(float *A, float *B, float *C, int *D, int *p, int *r)
{
    if (*p < *r)
    {
        int q, g;
        q = ((*p + *r) / 2);
        g = q + 1;
        mergesorting(A, B, C, D, p, &q);
        mergesorting(A, B, C, D, &g, r);
        mergesort(A, B, C, D, p, &q, r);
    }
    return;
}

struct node *knapsack(int *num, float *w, float *c, float *W)
{
    struct knapsack *knap;
    knap = (struct knapsack *)malloc(sizeof(struct knapsack));
    struct knapsack *ptr;
    ptr = (struct knapsack *)malloc(sizeof(struct knapsack));
    int i, a[*num], j, l, r;
    float X[*num], v[*num + 1], profit,t;
    for (i = 1; i <= *num; i++)
    {
        printf("a[%d] cost = %.2f\n", i, c[i]);
        printf("a[%d] weight  = %.2f\n", i, w[i]);
    }
    for (i = 1; i <= *num; i++)
    {
        knap->X[i] = 0;
        v[i] = c[i] / w[i];
    }
    for (i = 1; i <= *num; i++)
    {
        printf("value cost of a[%d] =  %.2f\n", i, v[i]);
    }
    for (i = 1; i <= *num; i++)
    {
        a[i] = i;
    }
    l = 1;
    r = *num;
    mergesorting(v, w, c, a, &l, &r);
    printf("----->  Sorted Cost --->\n");
    for (j = 1; j <= *num; j++)
    {
        printf("%.2f\n", c[j]);
    }
    printf("------> Sorted Weight---->\n");
    for (j = 1; j <= *num; j++)
    {
        printf("%.2f\n", w[j]);
    }
    printf("After Sorting Value cost :-\n");
    for (j = 1; j <= *num; j++)
    {
        printf("%.2f\n", v[j]);
    }
    i = 1;
    while ((*W != 0) && (i <= *num))
    {
        if (*W >= w[i])
        {
            knap->X[i] = 1;
            *W = *W - knap->X[i] * w[i];
        }
        else
        {
            knap->X[i] = *W / w[i];
            *W = *W - knap->X[i] * w[i];
        }
        i = i + 1;
    }
    printf("Weight Taken Are Shown in Arranged Value Cost\n");
    for (i = 1; i <= *num; i++)
    {
        printf("X{%d} = %.2f\n", a[i], knap->X[i]);
    }
    t = 0;
    printf("Profit Are ---->\n");
    {
        for (i = 1; i <= *num; i++)
        {
            t += c[i] * knap->X[i];
            ptr->profit = t;
        }
    }
    printf("%f\n",ptr->profit);
}

int main()
{
    float w[20], c[20], W;
    int num, i;
    printf("Enter Number of Object\n");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        printf("Enter weight of the object O[%d]\n", i);
        printf("w[%d] = ", i);
        scanf("%f", &w[i]);
    }
    for (i = 1; i <= num; i++)
    {
        printf("Enter cost of the object O[%d]\n", i);
        printf("c[%d] = ", i);
        scanf("%f", &c[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &W);
    knapsack(&num, w, c, &W);
    return 0;
}
