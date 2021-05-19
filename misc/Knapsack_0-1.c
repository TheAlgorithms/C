#include <stdio.h>

#define NUMBER_OF_ELEMENTS 10
#define WEIGHT_OF_KNAPSACK 30

int knapsack_recursive(int, int);
int knapsack_memoization(int, int);
int knapsack_iterative();
static int initialize_memoization_matrix();

int weight_of_elements[NUMBER_OF_ELEMENTS+1]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int memoization_matrix[NUMBER_OF_ELEMENTS+1][WEIGHT_OF_KNAPSACK+1];

int main()
{
    printf("Value of the function \"knapsack_recursive\": %d\n", knapsack_recursive(WEIGHT_OF_KNAPSACK, NUMBER_OF_ELEMENTS-1));
    initialize_memoization_matrix();
    printf("Value of the function \"knapsack_memoization\": %d\n", knapsack_memoization(WEIGHT_OF_KNAPSACK, NUMBER_OF_ELEMENTS-1));
    initialize_memoization_matrix();
    printf("Value of the function \"knapsack_iterative\": %d\n", knapsack_iterative());

    return 0;
}

int knapsack_recursive(int weight_of_knapsack, int element_index)
{
    if(element_index<0)
        if(weight_of_knapsack==0)
            return 1;
        else
            return 0;
    else
        if(weight_of_elements[element_index]<=weight_of_knapsack)
            return knapsack_recursive(weight_of_knapsack, element_index-1) || knapsack_recursive(weight_of_knapsack-weight_of_elements[element_index], element_index-1);
        else
            return knapsack_recursive(weight_of_knapsack, element_index-1);
}

int knapsack_memoization(int weight_of_knapsack, int element_index)
{
    if(element_index<0)
        if(weight_of_knapsack==0)
            return 1;
        else
            return 0;
    else
        if(memoization_matrix[element_index][weight_of_knapsack]==-1)
            if(weight_of_elements[element_index]<=weight_of_knapsack)
                memoization_matrix[element_index][weight_of_knapsack]=knapsack_memoization(weight_of_knapsack, element_index-1) || knapsack_memoization(weight_of_knapsack-weight_of_elements[element_index], element_index-1);
            else
                memoization_matrix[element_index][weight_of_knapsack]=knapsack_memoization(weight_of_knapsack, element_index-1);
    
    return memoization_matrix[element_index][weight_of_knapsack];
}

int knapsack_iterative()
{
    int i, j;

    memoization_matrix[0][0]=1;
    for(j=1; j<=WEIGHT_OF_KNAPSACK; j++)
        memoization_matrix[0][j]=0;
    
    for(i=1; i<=NUMBER_OF_ELEMENTS; i++)
        for(j=0; j<=WEIGHT_OF_KNAPSACK; j++)
        {
            memoization_matrix[i][j]=memoization_matrix[i-1][j];
            if(j-weight_of_elements[i-1]>=0)
                memoization_matrix[i][j]=memoization_matrix[i][j] || memoization_matrix[i-1][j-weight_of_elements[i-1]];
        }
    
    return memoization_matrix[NUMBER_OF_ELEMENTS][WEIGHT_OF_KNAPSACK];
}

static int initialize_memoization_matrix()
{
    for(int i=0; i<=NUMBER_OF_ELEMENTS; i++)
       for(int j=0; j<=WEIGHT_OF_KNAPSACK; j++)
           memoization_matrix[i][j]=-1;
}