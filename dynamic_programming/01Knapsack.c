/*
The 0/1 Knapsack Problem:
 
The problem is as follows:
You are given a set of items, each with a specific weight and a value.
You have a knapsack with a maximum weight capacity.
Your goal is to determine which items to put into the knapsack to maximize the total value, under the constraint that the sum of the weights of the chosen items does not exceed the knapsack's capacity.

The "0/1" property means that for each item, you have two choices:
1. Take the entire item (1).
0. Leave the item behind (0).
You cannot take a fraction of an item or take an item multiple times.

This implementation uses Dynamic Programming to solve the problem efficiently.
*/

#include <stdio.h>
#include <conio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// This function solves the 0/1 Knapsack problem using Dynamic Programming.
// n: the number of items.
// W: the capacity of the knapsack.
// weight[]: an array storing the weight of each item.
// value[]: an array storing the value of each item.
int knapsack(int n, int W, int weight[], int value[]) 
{
    // Create a DP table V[n+1][W+1] to store the maximum value that can be achieved with a capacity 'w' using items up to 'i'.
    // V[i][w] will store the maximum value for a knapsack of capacity w considering items from 1 to i.
    int V[n + 1][W + 1];

   
    // Build the table V[][] in a bottom-up manner.
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            // Base Case: If there are no items (i=0) or the knapsack capacity is 0 (w=0), the maximum value is 0.
            if (i == 0 || w == 0)
                V[i][w] = 0;
            // If the weight of the current item 'i' is more than the current knapsack capacity 'w', we cannot include this item. The solution is the same as the solution for the previous item.
            else if (weight[i] > w)
                V[i][w] = V[i - 1][w];
            // If the current item can fit in the knapsack.
            // We have two choices:
            // 1. Don't include the item: The value is the same as the previous state (V[i-1][w]).
            // 2. Include the item: The value is the value of the current item plus the value of the remaining capacity (w - weight[i]) with the previous items.
            // We take the maximum of these two choices.
            else
                V[i][w] = max(V[i - 1][w], value[i] + V[i - 1][w - weight[i]]);
        }
    }


    printf("\nDP Table (V[i][w]):\n");
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            printf("%3d ", V[i][w]);
        }
        printf("\n");
    }

    return V[n][W];
}


void main() 
{
    int n, W;
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], value[n + 1];

    printf("Enter weights of items:\n");
    for (i = 1; i <= n; i++) 
    {
        printf("Weight of item %d: ", i);
        scanf("%d", &weight[i]);
    }

    printf("Enter values of items:\n");
    for (i = 1; i <= n; i++) 
    {
        printf("Value of item %d: ", i);
        scanf("%d", &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(n, W, weight, value);
    printf("\nMaximum value that can be put in the knapsack = %d\n", maxValue);

	getch();
}
